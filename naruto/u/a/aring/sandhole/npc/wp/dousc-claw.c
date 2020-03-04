#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIR"���Ȥ�"NOR, ({ "double-scorpion claw","claw" }));
    set_weight(4500);
    setup_weapon(44, 55, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 53198);
        set("long", "�a�U�F�޸��Ȥl�ҨϥΪ��Z���C\n" );
    }
    set("apply_weapon/righthand", 
        ([ "str" : 3,            // �ݩʡG�O�q
           "attack" : 2,         // �����O�q
          
        ]) );
    setup();
}

