#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIG"��"HIW"��"NOR, ({ "lich soul", "soul" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 2);
        set("no_box", 1);
        set("no_sell", 1);
        set("no_drop", 1);
        set("long", "���]����z�A�ҵo�X���G���޲��ʤH�A�l�ާA���إ��C");
    }
    setup();
}