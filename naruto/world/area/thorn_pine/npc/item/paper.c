#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("���X�P("HIW+random(406)+NOR")", ({ "paper" }));
    set_weight(1);
    if( !clonep() ) {
        set("inter_test", 1);
        set("unit", "�i");
        set("value", 0);
        set("no_box", 1);
        set("long", "�y�H�Ҹժ����X�P�A�n���S�����");
    }
    setup();
}
