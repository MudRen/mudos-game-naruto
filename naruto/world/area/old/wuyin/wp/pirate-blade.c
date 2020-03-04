#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name(RED"�����s�M"NOR, ({ "piriate's blade", "blade" }));
    set_weight(10000);
    setup_weapon(40, 50, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 14240);
        set("long", "�j�ɭԮ��s���W�t�a���u�b�A�i�H��L���ӷ�P���ΡC\n" );
    }
    
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "int" : 4,            // �ݩʡG�O�q
           "attack" : 5,         // �����O�q
           "intimidate" : 5,     // ������O
    ]) );

    setup();
}
