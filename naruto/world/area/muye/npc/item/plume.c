#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("�Ф�", ({ "plume" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 25);
        set("base_weight", 100);
        set("long", "�@��¥ժ��Ф�C\n");
    }
    setup();
}
