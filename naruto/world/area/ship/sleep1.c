#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�ש�");
        set("long", @LONG
�שФ@�ӡA���䦳�Ӽӱ�i�H��ӤU�C�שФ@�ӥi�H��²������
��b²���F�A�u���X�i�Q�ɡA��L���F�褰��]�S���C
LONG);
    set("exits", ([
        "down" : __DIR__"sleep2.c",
        "south" : ([ "filename" : __DIR__"lufi.c",
                       "x_axis" : 9,
                       "y_axis" : 15,
                  ]),
    ]));
    setup();
}
