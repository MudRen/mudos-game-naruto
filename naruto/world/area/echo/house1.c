inherit ROOM;

void create()
{
        set("short", "獵戶");
        set("long", @LONG
有點破爛的小屋子，屋中點了一盞油燈，一位手拿獵槍的女性正
在燈光下，沉默的拿著子彈裝填，偶爾神情緊張的看看四周，隨時都
保持著警戒的狀態。
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"tomb.c",
                       "x_axis" : 11,
                       "y_axis" : 17,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/chu.c" : 1,
    ]));
    setup();
}
