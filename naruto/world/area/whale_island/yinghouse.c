inherit ROOM;

void create()
{
    set("short", "�j�ũ~");
    set("long", @long
���Z���p�Τl�A�\�]�]�ܴ��q�A���W���ۤ@�Ӥj�Сy�j�ũ~�z
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"area.c",
                      "x_axis": 22,
                      "y_axis": 30,
                 ]),
    ]));
    set("objects", ([
        "/world/area/old_forest/npc/ying.c" : 1,
    ]));
    setup();
}
