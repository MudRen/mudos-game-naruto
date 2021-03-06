#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N將$w揮向$n，$n只感覺脖子一陣涼意，好像被銳利的寒氣給劃過",
    "$N連續刺出數劍，只見$w化為寒氣，在地上凍出一道冰痕衝向$n",
    "$n忽然感覺寒風刺骨，$w銳利的寒氣化為巨刃直接刺向$n的$l",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("魏氏"HIC"薄冰劍"NOR, ({ "wei ice sword", "sword" }));
    set_weight(3000);
    setup_weapon(80, 100, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "把");
        set("value", 50000);
        set("no_box", 1);
        set("no_auc", 1);
        set("have_mag", 1);
        set("long", "魏氏一族所使用的兵器，劍身如薄冰，散發出寒冷的氣息。因為光芒\n"
                    "反射的原故，使得肉眼所見之劍身比實際上還來的窄，導致閃避時經\n"
                    "常判斷錯誤而受到此劍的傷害。\n" );
    }
    set("apply_weapon/righthand", 
        ([ "dex" : 2,            // 敏捷
           "intimidate" : 20,    // 攻擊技巧
    ]) );
    setup();
}
void init()
{
    add_action("do_perform", "perform");
}
int do_perform(string arg)
{
    int damage;
    object enemy, me;

    me = this_player();
    enemy = this_player()->query_opponent();

    if( arg == this_object()->query("id")+".ice" ) {

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
        me->damage_stat("mp", 20, me);
        message_vision("\n$N緩緩的舉起「"+query("name")+"」以再平凡不過的方式砍向$n！\n", me, enemy);

        if( userp(me) ) damage = COMBAT_D->isDamage(me, enemy, this_object())/2;
        else damage = COMBAT_D->isDamage(me, enemy, this_object());

        if( damage < 50 ) damage = random(20) + 30;

        // 傷害盾吸收
        damage = COMBAT_D->receive_damage(enemy, me, damage);

        enemy->receive_damage(damage, me);
        message_vision( sprintf("$n以為能輕鬆避過攻擊，卻在驚訝中被刀鋒砍中(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);

        me->start_busy(1);
        return 1;
    }
}