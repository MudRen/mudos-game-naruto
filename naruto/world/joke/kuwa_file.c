#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【城市獵人(Kuwa)角色檔案】", ({ "kuwa's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "個");
        set("value", 0);
        set("long", "一個 城市獵人(Kuwa) 的人物角色檔，期限內未售出便會銷毀。");
    }
    setup();

}
