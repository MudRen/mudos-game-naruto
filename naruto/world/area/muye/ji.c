/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "�N�Юa");

    set("long", @long
�o�̬O�츭�����N�Юa�A���O�N���a�A�O�d���F�C
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 11,
                      "y_axis": 18,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/ji.c": 1,
    ]));

    setup();
}
