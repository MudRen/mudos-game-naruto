#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【櫻塚星史郎(Sakuratomb)角色檔案】", ({ "sakuratomb's file", "file" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "個");
        set("value", 0);
        set("long", "一個 櫻塚星史郎(Sakuratomb) 的人物角色檔，期限內未售出便會銷毀。");
    }
    setup();

}

