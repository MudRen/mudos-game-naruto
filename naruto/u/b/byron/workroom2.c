#include <ansi.h>
#include <room.h>

// 設成INN者，會自動成為非戰區，並且是重生點
inherit INN;
 
void create() 
{
    set("short", "落下孤燈-涼亭內");
    set("long", @LONG
一個不是很大的涼亭，外面還在下雪非常的冷，但是這裡似乎有暖氣一樣溫暖了許多。
LONG);
    set("exits", ([ /* sizeof() == 2 */
        "south" : "/u/b/byron/workroom",  
    ]));
    setup();
    load_object("/daemon/board/byron2");
}
