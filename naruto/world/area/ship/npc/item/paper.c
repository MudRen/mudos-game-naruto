#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("�Ѯ�w����", ({ "weather forecast", "weather" }));
    if( !clonep() ) {
        set("base_unit", "�i");
        set("base_value", 0);
        set("unit", "�i");
        set("base_weight", 1);
        set("long", "�����Ҽg���Ѯ�w�����C\n");
    }
    setup();
}
