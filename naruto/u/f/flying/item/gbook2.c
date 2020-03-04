#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【"HIR"武卷"HIW"100%"NOR"】基本技能+20", ({ "book", "__BOOK__" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "個");
        set("value", -1);
        set("long", "一個可以增強武器能力的卷軸。(help combine)");
    }

    // 效果
    set("effect", ([
            "type": "WP",                // 武器類
            "success": 100,              // 成功率
            "evade": 20,
            "wittiness": 20,
            "dodge": 20,
            "savage hit": 20,
            "continual hit": 20,
            "parry": 20,
            "combat": 20,
            "heavy hit": 20, 
            "wittiness": 100,              // 防禦技巧+1
            "hp": 200,
            "mp": 200,
            "ap": 200,


     ]) );

    setup();
}

