#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��s�s�X�ΰѼ�");
        set("long", @LONG
�ж��̱��۳\�h���Ӥ��A�Ӥ����O�V�V�M��H�P�@���Y�W���ߤl
���٧��y�j�����X�ӡA����`���ͬ��٦�����_���ɪ��Ӥ��C�Ӥ���
�T�H�������Q���}�ߡC
LONG);
    set("exits", ([
        "down" : __DIR__"monkey2.c",
        "east" : ([ "filename" : __DIR__"lufi.c",
                       "x_axis" : 26,
                       "y_axis" : 22,
                  ]),

    ]));
    setup();
}
