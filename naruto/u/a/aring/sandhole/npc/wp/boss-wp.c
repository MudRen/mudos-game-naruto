#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIC"�Ȥ�"HIW"[�ܫ­�]"HIC"�C"NOR, ({ "scorpion sword","sword" }));
    set_weight(3000);
    setup_weapon(80, 99, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "lefthand", "twohanded" }) );
        set("unit", "��");
        set("value", 102678);
        set("long", "�Ȥ��ҫ����Z���A�u�n���_�o��M���H�A�N�|���ǤHı�o�A�ܫ­��C\n" );
    }
    set("apply_weapon/lefthand", 
        ([ "con" : 2,            // �ݩʡG�O�q
           "str" : 2,
           "attack" : 13,
           "intimidate" : 10,
        ]) );
    setup();
}

