#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("��o����", ({ "doll", "_EXQUISITE_DOLL_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 20);
        set("base_weight", 100);
        set("long", "�y������������A�s���`�������i���ʡC");
    }
    setup();
}
