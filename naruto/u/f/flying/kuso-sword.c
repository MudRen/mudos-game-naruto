#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�c�d���C", ({ "kuso sword", "sword" }));
    set_weight(1500);
    setup_weapon(199, 200, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 10);
        set("long", "�c�d���C�C\n" );
    }
     // ���[��O
        set("apply_weapon/righthand",
        ([ "exact" : 100,            
 ]) );
        set("apply_weapon/lefthand",
        ([ "exact" : 100,       
 ]) );

    setup();
}


