#include <ansi.h>
#include <room.h>

// �]��INN�̡A�|�۰ʦ����D�԰ϡA�åB�O�����I
inherit INN;

void create()
{
    set("short", HIB"�̫B�P��"NOR);
    set("long", "�i���e�Х��V��= =a�C\n");
    set("exits", ([
        "wizard" : "/world/area/wizard/guildhall.c", 
        "south" : ([ "filename" : "/world/area/wizard/wizard.c",
                       "x_axis" : 27,
                       "y_axis" : 15,
                  ]),
    ]));

    setup();
    load_object("/daemon/board/ayumi");
}
