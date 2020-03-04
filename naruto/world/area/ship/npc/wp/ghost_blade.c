#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIM"長曾禰"HIY"虎徹"NOR, ({ "tiger katana", "katana" }));
    set_weight(5000);
    setup_weapon(100, 120, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "把");
        set("no_box", 1);
        set("value", 176010);
        set("long", "江戶時代的名刀虎徹所仿造的刀，刀身漆亮，與原刀相差不遠。\n" );
    }
    set("apply_weapon/lefthand",
        ([ "str" : 3,
           "exact" : 5,
           "intimidate" : 5,
    ]) );
    setup();
}
