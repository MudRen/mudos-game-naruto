#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(BBLU+HIC"B�Ũ�԰��C"NOR, ({ "blevel sword", "sword" }));
    set_weight(7000);
    setup_weapon(91, 100, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 286690);
        set("long", "�@��D�`�W�Q��B�Ũ�԰��C�C\n" );
    }
     // ���[��O
        set("apply_weapon/righthand",
        ([ "exact" : 5,            
 ]) );
        set("apply_weapon/lefthand",
        ([ "exact" : 5,       
 ]) );

    setup();
}


