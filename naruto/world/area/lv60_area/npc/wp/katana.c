#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N右手握住$w謹遵戰法「先驅」接連不斷的攻勢連續攻擊$n的$l",
    "$N舉起$w擺出衝鋒姿勢「突進」利用瞬間爆發力攻向$n",
    "$N左右迂迴，忽然向前一記「突襲」$w打向$n的$l",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("長尾"HIW"武士刀"NOR, ({ "nagao katana", "katana" }));
    set_weight(3000);
    setup_weapon(77, 96, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "把");
        set("value", 50000);
        set("no_box", 1);
        set("no_auc", 1);
        set("have_mag", 1);
        set("long", "越後名產之一，鋒利的武士刀，本名為越後武士刀，因為紀念被稱為\n"
                    "「越後之龍」的長尾景虎而改名為長尾武士刀，其後人為了突顯此刀\n"
                    "的特色，更把刀握柄的部份加長，就有如長長的尾巴。\n" );
    }
    set("apply_weapon/righthand", 
        ([ "con" : 3,             // 體格
           "attack" : 10,         // 攻擊能力
           "wittiness" : 5,        // 防禦技巧
    ]) );
    setup();
}
void init()
{
    add_action("do_perform", "perform");
}
int do_perform(string arg)
{
    int damage, raiseDamage;
    object enemy, me;

    me = this_player();
    enemy = this_player()->query_opponent();

    if( arg == this_object()->query("id")+".hew" ) {

        if( me->is_busy() ) return notify_fail("你現在沒有空。\n");
        if( !enemy ) return notify_fail("沒有敵人可以施展技能。\n");
        if( !me->is_fighting(enemy) ) return notify_fail("你並未和對方戰鬥。\n");
        if( !query("equipped") ) return notify_fail("你沒裝備這樣武器。\n");
        if( me->query_stat("mp") < 35 ) return notify_fail("你沒魔力使用這招。\n");
        if( me->query_level() < 41 ) return notify_fail("你無法使用這個招式。\n");

        // 敵人在不同位置
        if( environment(me)->is_area() ) {
            if( !area_environment(me, enemy) ) return notify_fail("沒有敵人可以施展技能。\n");
        } else {
            if( environment(enemy) != environment(me) ) return notify_fail("沒有敵人可以施展技能。\n");
        }
        me->damage_stat("mp", 35, me);
        message_vision("\n$N忽然散發出龍吟般的氣勢，迅速抽刀「"HIW"越後龍吼"NOR"•"HIG"軍神"NOR"」驚天動地的一擊！\n", me, enemy);
        if( !COMBAT_D->isHit(me, enemy) ) {
            message_vision("強力的刀氣只在地上留下了痕跡，白白浪費力氣。\n\n", me, enemy);
            me->start_busy(4);
        } else {
            if( userp(me) ) raiseDamage = me->query_level()*5;
            else raiseDamage = 800;

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 200 ) damage = 80 + random(120);

            enemy->receive_damage(damage, me);
            message_vision( sprintf("$n承受不住這股力量，全身嚴重受創，噴了滿天的鮮血(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            me->start_busy(3);
        }
        return 1;
    }
}