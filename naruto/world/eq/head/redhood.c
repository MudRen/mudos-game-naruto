#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIR"紅色頭巾"NOR, ({ "red hood", "hood" }) );

    set_weight(500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "條");
        set("value", 450);
        set("long", "一條相當有個人風格的頭巾。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "exact": 3,
        ]));
    }

    setup();
}
