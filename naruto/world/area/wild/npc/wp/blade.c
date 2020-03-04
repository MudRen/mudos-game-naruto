#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�尨�j�M", ({ "large blade", "blade" }));
    set_weight(15000);
    setup_weapon(40, 50, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "twohanded" }) );
        set("unit", "��");
        set("value", 14240);
        set("long", "�@��I���������j�M�A���R�_�Ӫ֩w�۷��~�H�C\n" );
    }
    
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "str" : 3,            // �ݩʡG�O�q
           "attack" : 5,         // �����O�q
           "intimidate" : 5,     // ������O
    ]) );

    setup();
}
