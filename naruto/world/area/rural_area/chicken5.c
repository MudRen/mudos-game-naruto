#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
���٪�������F�ܦh�_��A���ӬO��������O�x�C�٤������䳣
����m�����}�ơA�����j���ɭԫK�|�ۤv������h�Y�}�ơA���`���S
�ƫK�|��~���ö]�A���I�����񪪫��A���}�i�k�C
LONG);
    set("exits", ([
        "west" : __DIR__"chicken4.c",
        "south" : __DIR__"chicken0.c",
    ]));
    set("objects", ([
        __DIR__"npc/chicken.c" : 3,
    ]));
    setup();
}
