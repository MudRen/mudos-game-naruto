#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(YEL"�˼��Ѱ�"NOR, ({ "kiss heaven book", "book"}));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 1);
        set("long", "�˼��Ѱ��򶰡A�]���|���X���A�Q�����ǻ�����Ū���C");
    }
    setup();
}
