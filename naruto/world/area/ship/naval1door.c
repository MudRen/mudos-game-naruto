#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���x��޲��");
        set("long", @LONG
����W���F�ܦh�����ϡA��l�W�h��F�U�Ӧa�誺�O�����w�A�]
���b���j����D���@����n�w�O�L�k�ϥΪ��A�U�q����ԩM�ϳ����P
�|�v�T����n�w�����T�ʡC
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"naval1.c",
                       "x_axis" : 14,
                       "y_axis" : 18,
                  ]),
    ]));
    setup();
}
