#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�˪K��");

    set("long", @long
���t�����O���A���Fť��ۤv���}�B�n�P�|�P���j�𸭪��n���~
�A�@�����ܥ��R�A���`���Hı�o�|�o�ͤ����....
long);
    set("exits", ([
        "south" : __DIR__"tree08.c",
        "east" : __DIR__"tree02.c",
        "west" : __DIR__"tree04.c",
    ]));
    setup();
}
