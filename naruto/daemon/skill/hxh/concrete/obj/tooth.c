#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N張開血盆大口，用銳利的$w往$n的$l咬去",
    "$N發出尖銳的磨牙聲，忽然扭動身子游到$n的後方張口便咬",
    "$N尾巴一陣拍動，身子猛然彈向$n露出$w準備捕食獵物",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("毒牙", ({ "fish tooth", "tooth" }));
    set_weight(8000);
    setup_weapon(40, 55, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "粒");
        set("value", 47094);
        set("have_mag", 1);
        set("long", "相當銳利的毒牙。\n" );
    }
    setup();
}