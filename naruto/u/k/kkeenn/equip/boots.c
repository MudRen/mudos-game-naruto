#include <ansi.h>
#include <armor.h>
inherit F_FEET_EQ;
void create()
{
    set_name(BRED+HIR"���~���@"NOR, ({ "blood boots", "boots" }) );
    set_weight(100);
    setup_feet_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī����]�c\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,       
            ]) ); 
        set("wear_msg",RED+"$N��W"+name()+RED"���P�ɡA�}�W���t���d�J�Ԭ�M�z�o�X�ӡI\n"NOR);
    }

    setup();
}


