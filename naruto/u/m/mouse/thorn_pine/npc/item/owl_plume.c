#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("����", ({ "owl plume", "plume", "_OWL_PLUME_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 1000);
        set("base_weight", 50);
        set("long", "�a�������Ф�A��@��Ф��[�X���C\n");
    }
    setup();
}
