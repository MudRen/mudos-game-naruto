#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【神杯(Doz)角色檔案】", ({ "doz's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "個");
        set("value", 0);
        set("long", "一個 神杯(Doz) 的人物角色檔，期限內未售出便會銷毀。");
    }
    setup();

}

