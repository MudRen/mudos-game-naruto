inherit ROOM;

void create()
{
        set("short", "海軍彈藥庫");
        set("long", @LONG
海軍的彈藥庫，裡面卻空空如也只有少量的槍支和子彈。一位非
常高大的人正站在房子中，不過他半彎著腰，整個背部都頂在房頂上
，似乎很難過的樣子。
LONG
);
    set("exits", ([
        "west" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 59,
                     "y_axis" : 40,
                 ]),
        ]));
    set("objects", ([
        __DIR__"npc/jie.c": 1,
    ]));
    setup();
}
