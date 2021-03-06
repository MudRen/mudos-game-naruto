#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "石木室");
    set("long", @long
四周由木板所搭建的小房間，敲敲四周的木板都很結實，看來
木板後面還是這洞中的岩石。唯一不同的地方就是房底中央牆上有
著一塊詭異的石版，石版的四周都刻著不同的音符，看久了還真是
讓人感到頭暈目眩眼花撩亂，彷彿被迷惑住了，漸漸失去意識。
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"hole_2b.c",
                      "x_axis": 17,
                      "y_axis": 1,
                 ]),
    ]));
    set("detail", ([
        "石版": "石版上寫了「無聲」二字，似乎可以推動(push)。",
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
            message_vision("$N用力推石版，腳下忽然出現一個大洞掉了下去。\n", this_player());
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
            message_vision("$N用力的推著石版，除了音樂聲卻沒任何事情發生。\n", this_player());
            return 1;
        }
        message_vision("$N用力的推動石版，只見四周忽然響起了五個高低不同的音色。\n", this_player());
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
