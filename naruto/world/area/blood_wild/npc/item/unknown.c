#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�o��", ({ "unknown" }));
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�o�O�@�ӨS���Ϊ��o�󪫡C");
    }
    setup();
}
