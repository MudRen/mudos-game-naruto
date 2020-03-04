#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�s�M", ({ "curve blade", "blade" }));
    set_weight(10000);
    setup_weapon(50, 60, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 35555);
        set("long", "�@���s�������M�A�W����ۤ@���D���ϮסC\n" );
    }
    set("apply_weapon/righthand", 
        ([ "attack" : 10,
           "intimidate" : 10,
    ]) );
    setup();
}
