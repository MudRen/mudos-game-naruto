#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "石室");
    set("long", @long
牆上有一塊詭異的石版，四周刻滿了各種不同的音符。看著那
些音符會讓人有種被迷惑的感覺，漸漸的失去意志。
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"hole_2b.c",
                      "x_axis": 17,
                      "y_axis": 1,
                 ]),
    ]));
    set("detail", ([
        "石版": "似乎可以推動(push)。",
    ]));
    setup();
}
void init()
{
    add_action("do_push", "push");
}
int do_push(string arg)
{
    string area_file = __DIR__"music.c";
    int i;
    object area;
    if( arg == "石版" ) {
        if( this_player()->query_temp("quest/music_F") >= 1 &&
            this_player()->query_temp("quest/music_A") == 0 &&
            this_player()->query_temp("quest/music_B") == 0 &&
            this_player()->query_temp("quest/music_C") == 0 &&
            this_player()->query_temp("quest/music_D") == 0 &&
            this_player()->query_temp("quest/music_E") == 0 ) {

            if( !objectp(area = load_object(area_file)) ) return 0;
            if( !area->is_area() ) return 0;
            message_vision("$N用力一推，整個人掉進密道裡去了。\n", this_player());
            if( !area_move(area, this_player(), 7, 19) ) return 0;
            message_vision("$N從密道跌了進來。\n", this_player());
            this_player()->delete_temp("quest/music_A");
            this_player()->delete_temp("quest/music_B");
            this_player()->delete_temp("quest/music_C");
            this_player()->delete_temp("quest/music_D");
            this_player()->delete_temp("quest/music_E");
            this_player()->delete_temp("quest/music_F");
            return 1;
        } else
        if( this_player()->query_temp("quest/music_F") >= 1 ) {
            message_vision("$N用力的推著石版，卻沒任何事情發生。\n", this_player());
            return 1;
        }
        message_vision("$N用力的推動石版，只見音符上出現了幾個數字....\n", this_player());
        i = random(10)+1;
        this_player()->add_temp("quest/music_A", i);
        message_vision("宮之音："HIR+i+NOR"\n"NOR, this_player());
        i = random(10)+1;
        this_player()->add_temp("quest/music_B", i);
        message_vision("商之音："HIR+i+NOR"\n"NOR, this_player());
        i = random(10)+1;
        this_player()->add_temp("quest/music_C", i);
        message_vision("角之音："HIR+i+NOR"\n"NOR, this_player());
        i = random(10)+1;
        this_player()->add_temp("quest/music_D", i);
        message_vision("徵之音："HIR+i+NOR"\n"NOR, this_player());
        i = random(10)+1;
        this_player()->add_temp("quest/music_E", i);
        message_vision("羽之音："HIR+i+NOR"\n"NOR, this_player());
        this_player()->add_temp("quest/music_F", 1);
        return 1;
    }
    return notify_fail("你想推動什麼？\n");
}
