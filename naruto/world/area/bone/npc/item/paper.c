#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR"���]����"NOR, ({ "paper", "__WHEYA__" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "�i");
        set("value", 0);
        set("long", "�j�D�Y�浹�˨��@�ڪ��q���ҩ��C");
    }
    setup();
}
