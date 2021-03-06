#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N向後躍出三步，左手順勢抄起三支弓箭朝$w一搭射向$n",
    "$N左手往地上拔起雜草測試風向，右手將箭搭於腰間放箭射擊$n",
    "$N呈跪姿朝高空射出一箭，但弓箭卻以不可思議的角度回轉射向$n$l",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("毛利"HIM"遠弓"NOR, ({ "mouri bow", "bow" }));
    set_weight(3000);
    setup_weapon(10, 70, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "支");
        set("value", 50000);
        set("no_box", 1);
        set("no_auc", 1);
        set("have_mag", 1);
        set("long", "毛利家族以水軍為基礎，發展出一套特殊的作戰方式，在海戰中最適\n"
                    "合使用的武器就屬弓箭，為了讓本家的海戰更能無往不利，在弓箭的\n"
                    "設計上也下了一翻功夫。\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "intimidate" : 40,      // 攻擊技巧
           "attack" : 5,           // 攻擊能力
    ]) );
    setup();
}
void init()
{
    add_action("do_perform", "perform");
}
int do_perform(string arg)
{
    int damage, raiseDamage, exact, evade;
    object enemy, me;

    me = this_player();
    enemy = this_player()->query_opponent();

    if( arg == this_object()->query("id")+".loose" ) {

        if( me->is_busy() ) return notify_fail("你現在沒有空。\n");
        if( !enemy ) return notify_fail("沒有敵人可以施展技能。\n");
        if( !me->is_fighting(enemy) ) return notify_fail("你並未和對方戰鬥。\n");
        if( !query("equipped") ) return notify_fail("你沒裝備這樣武器。\n");
        if( me->query_stat("mp") < 20 ) return notify_fail("你沒魔力使用這招。\n");
        if( me->query_level() < 41 ) return notify_fail("你無法使用這個招式。\n");

        // 敵人在不同位置
        if( environment(me)->is_area() ) {
            if( !area_environment(me, enemy) ) return notify_fail("沒有敵人可以施展技能。\n");
        } else {
            if( environment(enemy) != environment(me) ) return notify_fail("沒有敵人可以施展技能。\n");
        }
        exact = COMBAT_D->intimidate(me, 1)*1.2;
        evade = COMBAT_D->wittiness(enemy, 1);

        me->damage_stat("mp", 20, me);
        message_vision("\n$N"+query("name")+"一搭一放，使出毛利家絕技「"RED+BLINK"焙烙火矢"NOR"」連株箭向$n射去！\n", me, enemy);
        if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
            message_vision("但是火矢在空中就爆了開來，沒有任何影響。\n\n", me, enemy);
            me->start_busy(2);
        } else {
            if( userp(me) ) raiseDamage = me->query_level()*2;
            else raiseDamage = me->query_level()*5;

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            // 傷害盾吸收
            damage = COMBAT_D->receive_damage(enemy, me, damage);
            enemy->receive_damage(damage, me);
            message_vision( sprintf("「噗」地一聲，火矢射中了$n，使$n哀嚎了一聲(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            if( random(200) > 50 ) {
                if( userp(me) ) raiseDamage = me->query_level()*3;
                else raiseDamage = me->query_level()*5 + me->query_ability("exact");

                me->add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(me, enemy, this_object());
                me->add_temp("apply/attack", -raiseDamage);

                if( damage < 150 ) damage = 100 + random(50);

                enemy->receive_damage(damage, me);
                message_vision( sprintf("忽然火矢發生一陣爆炸，立刻炸傷了被箭射中的$n(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                if( random(200) > 150 ) {
                    damage = me->query_level() + random(me->query_level());
                    // 傷害盾吸收
                    damage = COMBAT_D->receive_damage(enemy, me, damage);
                    enemy->receive_damage(damage, me);
                    message_vision( sprintf("沒想到火燄的餘灰又噴到$n身上造成第三次傷害(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                }
            } else {
                message_vision("$n把箭拔了下來丟到一旁。\n", me, enemy);
            }
            message_vision("\n", me, enemy);
        }
        return 1;
    }
}