#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("��C", ({ "wood sword", "sword" }));
    set_weight(300);
    setup_weapon(1, 5, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 606);
        set("long", "���Y���C�A�@��Z���C\n" );
    }
    setup();
}
