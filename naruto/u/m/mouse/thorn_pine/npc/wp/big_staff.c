#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("�j���", ({ "big staff", "staff" }));
    set_weight(3000);
    setup_weapon(10, 20, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 1515);
        set("long", "���Y�s���Τl�C\n" );
    }
    setup();
}
