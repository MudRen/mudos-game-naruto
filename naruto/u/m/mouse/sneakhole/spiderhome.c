#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�j�ﶡ");
        set("long", @LONG
�@���ѻj�ﵷ�զ����Фl�A�Ф��]��B���O�j�ﵷ�C�ߦ��𨤦�
�ӫD�`�㲴�����¦�۶�����b���̡A�n���O����F���ۦb���C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"path.c",
                       "x_axis" : 17,
                       "y_axis" : 5,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/spiderman.c" : 1,
    ]));
    setup();
}
