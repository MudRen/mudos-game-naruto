#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【偷心•盜香帥(Issa)角色檔案】", ({ "issa's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "個");
        set("value", 0);
        set("long", "一個 偷心•盜香帥(Issa) 的人物角色檔，期限內未售出便會銷毀。");
    }
    setup();

}

