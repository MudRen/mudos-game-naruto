#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(CYN"�i�Ѥ��ѡj"NOR, ({ "sky book", "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("middle_test", 1);
        set("unit", "��");
        set("value", 0);
        set("no_box", 1);
        set("long", "�@�Ӭݦ����q�����b�A�����D������γB�C");
    }

    setup();
}
