#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�ܮw");
    set("long", @LONG
�ӤH�a���䪺�j�ܮw�A�i�Ӥ���u���|�P�������Q��W�F�A�ڥ�
�S��k���}�A���ӳ��O�ӤH�n�c�檺���~�a�C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 35,
                       "y_axis" : 7,
                  ]),
    ]));
    setup();
}
