#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("���Ӥ�", ({ "picture", "__PIC__" }));
    set("unit", "�i");
    set("base_unit", "�i");
    set("base_value", -1);
    set("base_weight", 1);
    set("no_box", 1);
    setup();
}
