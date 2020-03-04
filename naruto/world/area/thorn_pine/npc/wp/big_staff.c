#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("大木棒", ({ "big staff", "staff" }));
    set_weight(3000);
    setup_weapon(10, 20, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 1515);
        set("long", "木頭製的棒子。\n" );
    }
    setup();
}
