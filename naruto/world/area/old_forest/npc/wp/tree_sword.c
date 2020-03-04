#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(YEL"����C"NOR, ({ "Tree sword", "sword" }));
    set_weight(7000);
    setup_weapon(50, 80, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 73230);
        set("no_box", 1);
        set("long", "�����K�Ҧ����C�A�W�Q�L��A�C�W�L�{�ۥ��~�C\n" );
        set("wield_msg", HIW"$N�u��v���@�n��X$n"HIW"�A�L�L���G���b$n"HIW"�|�P�{ģ�ۡC\n"NOR);
        set("unwield_msg", "$N�N$n���^�C�T�A���~�]�����H�h�C\n");
    }
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "str" : 2,            // �ݩʡG�O�q
           "attack" : 10,         // �����O�q
           "intimidate" : 5,     // ������O
           "continual hit" : 7,
    ]) );
    set("apply_weapon/lefthand", 
        ([ "intimidate" : 5,     // ������O
    ]) );
    setup();
}
