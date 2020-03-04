#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name(HIB"�Ԫ��@�y"NOR, ({ "ninja belt", "belt" }) );
    set_weight(2000);
    setup_waist_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 11950);
        set("long", "�Ԫ̨ϥΪ��y�a�A���\�h�i�H�\�÷t�����p�f�C\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 5,
            "con": 1,
            "wittiness": 5,
            "continual hit": 5,
        ]));
    }
    setup();
}
