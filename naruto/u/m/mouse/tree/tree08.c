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
        "north" : __DIR__"tree03.c",
        "west" : __DIR__"tree07.c",
        "east" : __DIR__"tree09.c",
    ]));
    setup();
}
