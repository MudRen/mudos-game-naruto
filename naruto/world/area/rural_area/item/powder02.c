#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"���ԯ�"NOR, ({ "chili powder", "powder", "_CHILI_D_" }));
    if( !clonep() ) {
        set("unit", "�]");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 10);
        set("long","�N���Կi���������ˤl�A�Ψӵ����~�K�W�ֳ\�����C\n");
    }
    setup();
}
