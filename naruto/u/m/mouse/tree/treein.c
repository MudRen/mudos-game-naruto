#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�ʦ~�j�˥~");

    set("long", @long
�񲴱�h�O��������j�j�˪L�A�s�������X�G�z���i�ӡC�b�츭
�����ɱ`���ǵۡA�����~�����j�Ѫ��˪L�A�̭���ۻP�~�H�j�����g
�ۡA���F�u�@�˪L�����@�ʤd�~����ӸT��~�Ӫ̶i�J�C
long);
    set("exits", ([
        "south" : __DIR__"tree00.c",
        "north" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 4,
                      "y_axis": 11,
                 ]),
    ]));
    setup();
}
