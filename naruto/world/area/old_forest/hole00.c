#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","村外洞窟");
    set("long", @long
位於土著村正後方的一條小徑，走到底端是完全漆黑的洞窟，洞
外掛滿了土著經常使用的樹果、花圈、各種各樣的飾品，每種都製作
的十分精美，飾品外表還包裹了一層透明固體，使裡面的果實花朵都
有如剛採下來一般的鮮艷，代表土著人非常尊敬這個洞窟。
long);
    set("exits", ([
        "south" : __DIR__"hole01.c",
        "north" : __DIR__"tree36.c",
    ]));
    set("no_recall", 1);
    setup();
}
