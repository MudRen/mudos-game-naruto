#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�}�]��");
    set("long", @long
�Q�ª��}�]���A�A�ϩ��D��F�@�Ѩ�󪺯���A�D�_�ӹ��O���D
�������F��A���Ǧb�}�]���S�����󪺤���ө��A�i��@�U�l�ˤ��n
�N�|�o���z���a�C
long);
    set("exits", ([
        "south" : __DIR__"hole02.c",
        "north" : __DIR__"hole00.c",
    ]));
    set("no_recall", 1);
    setup();
}
