#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N使用$w吹出一個電氣泡，但是$n只覺得一陣麻，$N只好揮舞$w攻擊",
    "$N的$w忽然噴出一朵花束，令$N哀傷地搖搖頭直接攻向$n的$l",
    "$N想要發動$w的特技，卻變成雜耍的噴水特技，讓$n整個笑翻在地上",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("表演用天候棒", ({ "act sky stick", "stick", "_WEATHER_" }));
    set_weight(1000);
    setup_weapon(5, 15, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "支");
        set("value", 1010);
        set("have_mag", 1);
        set("long", "騙人布做的半成品天候棒，很多功能都只是表演用途。\n" );
    }
    setup();
}
