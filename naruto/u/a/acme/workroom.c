/* write by -Acme- */

#include <ansi.h>
#include <room.h>

// �]��INN�̡A�|�۰ʦ����D�԰ϡA�åB�O�����I
inherit INN;

void create()
{
    set("short", "�y�ûR��");
    set("long", "�@�Ӭ۷������a��A�o���õۤ@��}�_�j�Ǫ��ƪ��C\n");
    set("exits", ([
        "wizard" : "/world/area/wizard/guildhall.c", 
        "south" : ([ "filename" : "/world/area/wizard/wizard.c",
                       "x_axis" : 23,
                       "y_axis" : 15,
                  ]),
    ]));

    setup();
    load_object("/daemon/board/acme");
}