#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("���ⶱ�Υd", ({ "card", "_BANDIT_CARD_" }));
    if( !clonep() ) {
        set("base_unit", "�i");
        set("unit", "�i");
        set("base_value", 500000);
        set("base_weight", 100);
        set("long", "�M�����α��⪺�d�A������Q�C");
    }
    setup();
}
