inherit ROOM;

void create()
{
    set("short", "���K�Q");
    set("long", @long
�츭�������p�Q�l�A���G�S���s�@�Z���Ϊ��j���l�A�ҳc�檺��
�O�@�ǻs�@²�檺�u��Ӥw�C
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
