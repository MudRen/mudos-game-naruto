#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("尚未命名的劍", ({ "noname sword", "sword", "_CREATION_SWORD_" }));
    set_weight(5000);
    setup_weapon(1, 1, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "把");
        set("value", 0);
        set("no_box", 1);
        set("no_drop", 1);
        set("long", "一把未經過投影的劍，如果你看到這把劍該找巫師處理了。\n" );
    }
    setup();
}
