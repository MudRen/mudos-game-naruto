#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【海王星(Neptune)角色檔案】", ({ "neptune's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "個");
        set("value", 0);
        set("long", "一個 海王星(Neptune) 的人物角色檔，期限內未售出便會銷毀。");
    }
    setup();

}

