#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(HIM"�G��"HIY"����"NOR, ({ "fruit necklace", "necklace" }) );
    set_weight(900);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 14000);
        set("long", "�G���ΰ��ᰵ��������A�ѯ��쯬�֫��O�@�t�a�̡C\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "hp": 100,
            "ap": 40,
        ]));
    }
    setup();
}
