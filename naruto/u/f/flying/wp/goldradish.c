#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIY"�����ڽ�"NOR, ({ "gold radish", "radish" }));
    set_weight(2000);
    setup_weapon(150, 190, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 404);
        set("long", "�@�ڶ����s���ڽ��A�N�_�Ӥ�P���ΡA���H�@�w�ܮ��O�C\n"
     "�W����flying�����O�[���A�i�H���ݩʼɺ��C\n" );
    }

    // ���[��O
    set("apply_weapon/righthand", 
        ([ "str" : 180,            // �ݩʡG�O�q
           "con" : 180,
           "dex" : 180,
           "int" : 180,
           "wittiness" : 500,
           "intimidate" : 500,    // �����ޥ�
    ]) );

    setup();
}
