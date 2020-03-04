#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIG"蛇杖"NOR, ({ "snake staff", "staff" }));
    set_weight(7000);
    setup_weapon(40, 40, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 4740);
        set("long", "彎彎曲曲的青色木杖，看起來活像一條蛇。\n" );
    }
    // 附加能力
    set("apply_weapon/twohanded", 
        ([ "int" : 1 ]) );
    setup();
}
