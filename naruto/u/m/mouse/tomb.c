#include <ansi.h>
inherit ROOM;

string do_abc_list()
{
    int index, size, x, y;
    string msg;

    msg  = "╭────────────────────────╮\n";
    msg += "│                                                │\n";
    msg += "│  "HIC"孤山獨人    孤思群城    御劍萬里    遊遍中原"NOR"  │\n";
    msg += "│                                                │\n";
    msg += "│  "HIY"心誠則置    心想事成    神劍破空    嘯天而行"NOR"  │\n";
    msg += "│                                                │\n";
    msg += "╰────────────────────────╯";

    return msg;
}
void create()
{
    set("short", HIW+BLK"無名"NOR"劍塚");
    set("long", @LONG
雜草叢生的一片荒山，在草堆中卻有塊空曠的土地，只見一把帶
著劍鞘的長劍，正插在空地的土堆上。長劍所散發出的氣息吸引了你
的注意，當你朝著長劍走去，卻感覺身上愈來愈寒冷，彷彿置身於冰
天雪地之中。當你辛苦的走到土堆五尺前時，一股強烈的冷風吹向你
的身驅，使你全身幾乎凍結而無法前進。你抬起頭來望向土堆，卻發
現土堆的後方還有一塊巨大的石牆，上面似乎寫了什麼。
LONG);
    set("exits", ([
        "south" : __DIR__"workroom.c",
    ]));
    set("detail", ([
        "石牆": (: do_abc_list :),
    ]));
    set("objects", ([
        __DIR__"npc/item/sword.c" : 1,
    ]));
    set("no_fight", 1);
    setup();
}
