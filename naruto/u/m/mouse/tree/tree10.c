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
        "southwest" : __DIR__"tree16.c",
        "north" : __DIR__"tree01.c",
        "west" : __DIR__"tree09.c",
        "east" : __DIR__"tree11.c",
    ]));
    setup();
}
