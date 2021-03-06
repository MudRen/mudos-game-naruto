/* write by -Acme- */

#include <room.h>

// 設成INN者，會自動成為非戰區，並且是重生點
inherit INN;

void create()
{
    set("short", "巫師神殿");
    set("long", @LONG
這裡住著一群擁有高級魔法的巫師，巫師所擁有的能力不是一般
人可以瞭解的，你可以看見前面的巫師手舞足蹈地，週身不時散發出
七彩光芒，不知在使什麼魔法。
LONG
    );
    set("exits", ([
        "west" : __DIR__"bug",
        "north" : __DIR__"academy",
        "east" : __DIR__"propose",
        "up" : __DIR__"meetingroom",
        "south": __DIR__"power",
    ]));

    set("objects", ([
        __DIR__"npc/annihilator" : 1,
        __DIR__"npc/luky" : 1,
        __DIR__"npc/shengsan" : 1,
        __DIR__"npc/tmr" : 1, 
        __DIR__"npc/acme" : 1, 
        __DIR__"npc/chi.c" : 1,
    ]));

    setup();
    load_object("/daemon/board/wizard");
    replace_program(ROOM);
}
