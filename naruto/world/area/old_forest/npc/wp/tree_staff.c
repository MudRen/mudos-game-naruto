#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(YEL"神木杖"NOR, ({ "Tree staff", "staff" }));
    set_weight(7000);
    setup_weapon(40, 45, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 26884);
        set("long", "神木樹枝所成之杖，擁有神木的法力。\n" );
    }
    // 附加能力
    set("apply_weapon/righthand", 
        ([ "int" : 2,
           "continual hit" : 10,
    ]) );
    setup();
}
