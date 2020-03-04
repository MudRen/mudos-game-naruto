#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�޼C", ({ "shield sword", "sword", "shield" }));
    set_weight(5000);
    setup_weapon(20, 20, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "��");
        set("value", 12000);
        set("long", "�ޤW���۵u�C�A���m���a�������C\n" );
    }
    set("apply_weapon/lefthand", 
        ([ "armor" : 20,
           "wittiness" : 5,
    ]) );
    setup();
}
