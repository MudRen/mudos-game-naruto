#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIG"����"NOR+GRN"�s���Z"NOR, ({ "root armor", "armor" }) );
    set_weight(2500);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 121000);
        set("no_box", 1);
        set("long", "�ѥ��������ڳ��s�������ҡA�j�j���ͩR�O��ϥΪ̤]�|�y���v�T�C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
            "hp": 200,
            "mp": 100,
            "ap": 100,
        ]));
    }
    setup();
}
