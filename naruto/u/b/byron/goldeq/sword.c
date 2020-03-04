#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;
void create()
{
    set_name(HIY"黃金長劍"NOR, ({ "gold sword", "sword" }));
    set_weight(5000);
    setup_weapon(180, 200, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "把");
        set("value", 176010);
        set("long", "純金打造的長劍。\n" );
    }
    set("apply_weapon/righthand", 
        ([ "str" : 10,
           "con" : 10,
           "dex" : 10,
           "int" : 10,
           "ap"  : 1000,                      
    ]) );
    setup();
}

