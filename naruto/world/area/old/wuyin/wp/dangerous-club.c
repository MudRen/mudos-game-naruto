#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(GRN"����"NOR, ({ "dangerous club", "club" }));
    set_weight(10000);
    setup_weapon(20, 70, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 14240);
        set("long", "�@�ڨ��Ǳj�ƹL���Z���A�n�Ⱖ��~���ʰ_�ӡC\n" );
    }
    
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "attack" : 10,         // �����O�q
           "intimidate" : 10,     // ������O
    ]) );

    setup();
}

