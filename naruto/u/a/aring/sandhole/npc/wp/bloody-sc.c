#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(NOR+RED"�V���Ȥ�"NOR, ({ "bloody scorpion claw","claw" }));
    set_weight(4750);
    setup_weapon(50, 60, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 61710);
        set("long", "�a�U�F�޸��Ȥl�ҨϥΪ��Z���C\n" );
    }
    set("apply_weapon/righthand", 
        ([ "str" : 2,            // �ݩʡG�O�q
           "attack" : 3,         // �����O�q
           "intimidate" : 7,
        ]) );
    setup();
}

