#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("��j", ({ "lance", "lance" }));
    set_weight(8000);
    setup_weapon(50, 55, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 36952);
        set("long", "�g�ۨϥΪ�������j�A�M�b�p�Q�C\n" );
    }
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "str" : 2,            // �ݩʡG�O�q
           "dex" : 1,            // �ݩʡG�ӱ�
           "intimidate" : 10,     // ������O
    ]) );
    setup();
}
