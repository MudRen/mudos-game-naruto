#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("�K��", ({ "iron hook", "hook" }));
    set_weight(1000);
    setup_weapon(5, 15, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 2020);
        set("long", "��⪺�K�Ĥ��C\n" );
    }
    setup();
}
