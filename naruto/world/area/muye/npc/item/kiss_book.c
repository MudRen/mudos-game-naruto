#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(YEL"�˼��Ѱ�"NOR, ({ "kiss heaven book", "book", "_KISS_" }));
    set_weight(1);
    if( !clonep() ) {
        set("middle_test", 2);
        set("unit", "��");
        set("value", 30000);
        set("long", "�@���ൣ���y�����}�p���C");
    }

    setup();
}
