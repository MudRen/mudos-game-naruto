#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;
void create()
{
    set_name(BRED+HIR"���~����"NOR, ({ "blood sword", "sword" }) );
    set_weight(100);
    setup_weapon(40, 50, 200, 1);    
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī�������b\n");
        set("wield_as",  ({ "lefthand" }) );
        set("wield_msg",RED+"$N���_�@��"+name()+RED"�y�W�B�{�X�@�Ѧ���I\n"NOR);
    }

    setup();
}


