#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIK"��"HIW"��"NOR, ({ "heart soul", "soul" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 2);
        set("no_box", 1);
        set("no_sell", 1);
        set("no_auc", 1);
        set("no_drop", 1);
        set("long", "�ߤ�����z�A�f�H�L���A�o�����a�{�ۤ@�اƱ�C");
    }
    setup();
}
