#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(HIW"白皇蛇槍"NOR, ({ "whitesnake lance", "lance" }));
    set_weight(15000);
    setup_weapon(120, 150, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 261935);
        set("long", "槍身雪白，頭如蛇頭，輕輕一抖，就像一隻正在游走的白蛇。\n" );
        set("wield_msg", "$n"HIY"「嗡」地一聲從$N背後彈出，穩穩的握在$N手上。\n"NOR);
        set("unwield_msg", HIY"$N將$n"HIY"朝空中一拋，$n"HIY"自動落回$N背上。\n"NOR);
    }
    // 附加能力
    set("apply_weapon/twohanded", 
        ([ "str": 5,
           "con": 2,
           "attack": 10,
           "evade": 10,
           "continual hit": 10,
    ]) );
    setup();
}
