#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;
void create()
{
    set_name(BRED+HIR"���~�k��"NOR, ({ "blood blade", "blade" }) );
    set_weight(100);
    setup_weapon(30, 40, 200, 1);   
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī��歱��b\n");
        set("wield_as",  ({ "righthand" }) );
        set("wield_msg",RED+"$N���_�@��"+name()+RED"�y�W�B�{�X�@�Ѭ����I\n"NOR);
    }

    setup();
}


