#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【"HIR"神化"HIW"卷軸"NOR"】, ({ "book", "__BOOK__" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "個");
        set("value", -1);
        set("long", "一個可以神化武器能力的卷軸。(help combine)");
    }

    // 效果
    set("effect", ([
        "type": "WP",                // 武器類
        "success": 100,              // 成功率
        "str": 20,
        "con": 20,
        "dex": 20,
        "int": 20,
        "ap": 100,
        "hp": 100,
        "mp": 100,
        "exact": 20,
        "attack": 20,
        "intimidate": 20,
        "combat": 20,
        "parry": 20,
        "dodge": 20,
        "heavy hit": 20,
        "savage hit": 20,
        "solid": 20,
        "continual hit": 20,
    ]) );

    setup();
}

