#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "團長室");
    set("long", @LONG
位於六芒星右側的團長室中，團長言峰���鉭℅y笑容的向你問好
，但是你卻隱約的感覺到這房間中有種說不出的難過感，你隨便打馬
虎跟團長哈啦了幾句，便快步離開屋子，在臨走前似乎聽到言峰����
在房間中跟某人交談著....但是你剛才進去並沒看到人阿？
LONG);
    set("exits", ([
        "west" : __DIR__"magic06.c",
        "east" : __DIR__"magic08.c",
        "north" : __DIR__"magic03.c",
        "south" : __DIR__"magic11.c",
    ]));
    set("objects", ([
        __DIR__"npc/yan.c" : 1,
    ]));
    setup();
    set("no_recall", 1);
}
void init()
{
    add_action("do_move", "move");
    add_action("do_move", "sfly");
}
int do_move(string arg)
{
    message_vision("$N企圖飛上天空，但是撞到房頂又跌了下來。\n", this_player());
    return 1;
}
