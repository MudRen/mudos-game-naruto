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
        "west" : __DIR__"home05.c",
        "east" : __DIR__"home07.c",
        "north" : __DIR__"home03.c",
    ]));
    setup();
}
