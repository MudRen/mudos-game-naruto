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
        "west" : __DIR__"tree10.c",
        "east" : __DIR__"tree12.c",
    ]));
    setup();
}
