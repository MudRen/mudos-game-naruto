
#include <ansi.h>
#include <room.h> 
inherit INN;

void create()
{
    set("short", "巧翎震天");
    set("long", "一個相當便秘的地方，這裡藏著一堆稀奇古怪的事物。\n");

    setup();
    load_object("/daemon/board/jolin");
}

