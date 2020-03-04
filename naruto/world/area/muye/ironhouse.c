inherit ROOM;

void create()
{
    set("short", "打鐵鋪");
    set("long", @long
木葉村中的小鋪子，似乎沒有製作武器用的大火爐，所販賣的都
是一些製作簡單的工具而已。
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 20,
                      "y_axis": 5,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/iron.c" : 1,
        __DIR__"npc/student.c" : 4,
    ]));
    setup();
}
