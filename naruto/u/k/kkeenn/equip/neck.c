#include <ansi.h>
#include <armor.h>
inherit F_NECK_EQ;
void create()
{
    set_name(BRED+HIR"���~�k�@"NOR, ({ "blood necklace", "necklace" }) );
    set_weight(100);
    setup_neck_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī�����\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,
]) );
        set("wear_msg",RED+"$N�a�W"+name()+RED"���P�ɡA$N���I��X�{�F�@�ӻ����k�ʪ��������I\n"NOR);
    }

    setup();
}


