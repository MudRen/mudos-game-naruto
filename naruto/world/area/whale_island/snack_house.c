inherit ROOM;

void create()
{
    set("short", "�N��p�Y��");

    set("long", @long
�o�̬O�H���q�W�ߤ@�@�a�M����N�檺�p�Y���C
long);

    set("exits", ([
        "east" : ([ "filename": __DIR__"area.c",
                      "x_axis": 15,
                      "y_axis": 18,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/snack_boss" : 1,
    ]));

    setup();
}


