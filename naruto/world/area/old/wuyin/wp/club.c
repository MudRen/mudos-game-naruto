#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(YEL"���"NOR, ({ "club" }));
    set_weight(10000);
    setup_weapon(40, 50, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 14240);
        set("long", "�@�ڨ��Ǫ��Z���A�n�Ⱖ��~���ʰ_�ӡC\n" );
    }
    
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "int" : -5,            // �ݩʡG�O�q
           "attack" : 10,         // �����O�q
           "intimidate" : 10,     // ������O
    ]) );

    setup();
}

