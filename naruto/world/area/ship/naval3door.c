#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���x��޲��");
        set("long", @LONG
�̭��ſ������S���b�ӤH�A�����M�U�إΨ�]�O��b�@�Ǫ���l
�W�A�]�\�O��ܳo����ĥ�Ȯɤ��|���a�C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"naval3.c",
                       "x_axis" : 10,
                       "y_axis" : 18,
                  ]),
    ]));
    setup();
}
