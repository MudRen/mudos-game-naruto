#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("�ȹζ��г�", ({ "paper", "_TEAM_PAPER_" }));
    if( !clonep() ) {
        set("base_unit", "�i");
        set("unit", "�i");
        set("base_value", 99999999);
        set("base_weight", 100);
        set("long", "�@��H�ڥ��I���_���ѻ��A���Τۼv�ȹΦ����M�ΡC");
    }
    setup();
}
