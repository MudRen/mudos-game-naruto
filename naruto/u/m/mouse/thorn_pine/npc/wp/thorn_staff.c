#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("����", ({ "thorn staff", "staff" }));
    set_weight(3000);
    setup_weapon(25, 30, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 4477);
        set("long", "��Q�L�����һs�����Τl�C\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "attack" : 10,
           "exact" : 5,
    ]) );
    setup();
}
