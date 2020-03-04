#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【"HIR"武卷"HIW"60%"NOR"】敏捷+2", ({ "book", "__BOOK__" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "個");
        set("value", -1);
        set("long", "一個可以增強武器能力的卷軸。(help combine)");
    }

    // 效果
    set("effect", ([
        "type": "EQ",                // 武器類
        "success": 100,              // 成功率
        "dex": 3,
    ]) );

    setup();
}

