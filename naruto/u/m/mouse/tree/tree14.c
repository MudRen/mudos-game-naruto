#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�˪K��");

    set("long", @long
�ּƪ��g�ۥ��b�b�̤������r�޵ۡA�L�̯������^�B���⾮���A�⮳
�۪Z���H�ɫO�����������A�C
long);
    set("exits", ([
        "north" : __DIR__"tree07.c",
        "east" : __DIR__"tree15.c",
    ]));
    set("objects", ([
        __DIR__"npc/warrior.c" : 1,
    ]));
    setup();
}
