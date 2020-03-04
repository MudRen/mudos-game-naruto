#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(YEL"蘿蔔"NOR, ({ "radish" }));
    set_weight(2000);
    setup_weapon(1, 3, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "根");
        set("value", 404);
        set("long", "一根乾黃的蘿蔔，摸起來硬邦邦的，應該可以拿來打人。\n" );
    }

    setup();
}
