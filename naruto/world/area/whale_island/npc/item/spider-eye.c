#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"�j�ﲴ��"NOR, ({ "spider eye", "eye" }));
    if( !clonep() ) {
        set("base_unit", "��");
          set("base_value", 15);
        set("base_weight", 100);
        set("long", "�@���ޤU�Ӫ��j�ﲴ���C\n");
    }
    setup();
}

