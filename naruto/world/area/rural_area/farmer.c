#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�A�a");
    set("long", @LONG
�ѹA�Ҫ��a�A�ݰ_��²����C�ж��̦���ѹA�ҡA�y�W�`�O��
���ۯ��e�A�쥻�L�P�Ѧ�~��b�o���ۤv���a��A���O�Ʀ~�e�Ѧ��
�h�F����ѥL�W�ۤ@�H�L���D�`���W�A�o�ɰӤH���H���n�Ө즹�a�A
�q���K�b�ѹA�Ҫ��a��\�F�ۤv���a�~��U�ӡA���ѹA�ҥ��I�A�@��
���R��C�{�b���ѹA�ҴX�G�C�ѳ��L���ܧּ֡C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 18,
                       "y_axis" : 18,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/farmer.c" : 1,
    ]));
    setup();
}
