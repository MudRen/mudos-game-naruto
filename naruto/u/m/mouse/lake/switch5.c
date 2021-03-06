#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "機關室");
    set("long", @long
房內除了一個人站的空間之外，到處都佈滿了齒輪與開關，因
為長久的停用似乎都有些破損，不知道啟動這些開關會發生什麼嚴
重的事，也許這遺跡會沉入水底就是因為這些開關也說不定。
long);
    set("exits", ([
        "east" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 31,
                      "y_axis": 11,
                 ]),
    ]));
    set("detail", ([
        "齒輪": "巨大的齒輪，千萬別妄想用手去轉動它。",
        "開關": "似乎可以開啟(open)或關閉(close)。",
    ]));
    setup();
}
void init()
{
    add_action("do_open", "open");
    add_action("do_close", "close");
}
int do_open(string arg)
{
    if( arg == "開關" ) {
        if( this_player()->query_temp("quest/opengold") > 1) {
            message_vision("$N用力的將開關往下壓。\n", this_player());
            message_vision("但是開關已經壓到底了，沒辦法在壓下去。\n"NOR, this_player());
            return 1;
        } else
        if( this_player()->query_temp("quest/opengold") == 1) {
            message_vision("$N用力的將開關往下壓。\n", this_player());
            message_vision("旁邊齒輪轉動加快，遠處還聽見很大的「轟隆」聲。\n"NOR, this_player());
            this_player()->add_temp("quest/opengold", 1);
            return 1;
        }
        message_vision("$N用力的將開關往下壓。\n", this_player());
        message_vision("但是開關似乎被什麼給卡住，壓不下去。\n"NOR, this_player());
        return 1;
    }
    return notify_fail("你想啟動什麼？\n");
}
int do_close(string arg)
{
    if( arg == "開關" ) {
        if( this_player()->query_temp("quest/opengold") > 2) {
            message_vision("$N使盡吃奶的力氣將開關往上推。\n", this_player());
            message_vision("但是開關似乎卡的很緊，$N推的滿頭大汗都沒點動靜。\n"NOR, this_player());
            return 1;
        } else
        if( this_player()->query_temp("quest/opengold") == 2) {
            message_vision("$N使盡吃奶的力氣將開關往上推。\n", this_player());
            message_vision("齒輪傳出刺耳的磨擦聲，轉動似乎變慢了。\n"NOR, this_player());
            this_player()->add_temp("quest/opengold", -1);        return 1;
        }
        message_vision("$N使盡吃奶的力氣將開關往上推。\n", this_player());
        message_vision("但是開關已經推到頂了，白廢功夫。\n"NOR, this_player());
        return 1;
    }
    return notify_fail("你想停止什麼？\n");
}
