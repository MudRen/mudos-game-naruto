#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "團員休息室");
    set("long", @LONG
陰暗的小房間，中央畫了一個與馬戲團帳篷中間類似的六芒星，
只見一位披著黑色斗蓬的人坐在房間左側，嘴巴裡唸唸有詞，每當她
停下來不說話時，房間中間的六芒星就會發出紫色的光芒，但是光芒
雖強卻一點也照不出門外，讓人感到非常詭異。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"house.c",
                       "x_axis" : 28,
                       "y_axis" : 24,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/transfer.c" : 1,
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
