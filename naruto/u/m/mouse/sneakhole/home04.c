#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�@�ԫ�");
        set("long", @LONG
�Ф�����F�@�i�j���A��W�\�F�@�i�o���񪺦a�ϡC�a�ϤW�b
�츭�Ԫ̧����|�P�e���F�U�ت��Ÿ��A���D�L�̥��b�p�������츭��
�̧��ܡH�٦n�|�P�Ԫ̳����ۦۤv���ơA�S�o�{���H�b���ݦa�ϡC
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"music.c",
                       "x_axis" : 26,
                       "y_axis" : 4,
                  ]),
        "west" : __DIR__"home03.c",
        "south" : __DIR__"home07.c",
    ]));
    setup();
}
