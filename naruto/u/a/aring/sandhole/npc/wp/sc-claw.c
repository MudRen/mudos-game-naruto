#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIW+BLK"蠍爪"NOR, ({ "scorpin claw","claw" }));
    set_weight(4000);
    setup_weapon(10, 15, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 2424);
        set("long", "地下沙穴裡蠍子所使用的武器。\n" );
    }

    setup();
}

