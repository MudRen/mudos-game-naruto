#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�֬�", ({ "shield" }));
    set_weight(15000);
    setup_weapon(5, 10, 0, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "��");
        set("value", 5000);
        set("long", "�@�ӥֻs��ޡC\n" );
    }
    
    // ���[��O
    set("apply_weapon/lefthand", 
        ([ "con" : 3,            // �ݩʡG�O�q
           "armor" : 5,         // �����O�q
           "wittiness" : 5,     // ������O   
 ]) );

    setup();
}

