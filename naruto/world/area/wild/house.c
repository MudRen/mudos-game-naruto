#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�p��");
    set("long", @LONG
�o�̥u��²���a�\��F�X�i��ȩM�@�Ӥ��A�a�𪺨��@�ݦ��@
�i�}�ª���ɡA�O�@���ܴ��q���p�ΡC����W���۴X���K�s�o���ת�
����C�@���ûs���d�l�Q���F�}�ӡA���@�j�K�o�X�u�U�U��r�r��v
���n���C
LONG);

    set("exits", ([
        "west" : ([ "filename" : __DIR__"land.c",
                    "x_axis" : 25,
                    "y_axis" : 4,
                 ]),           
        "east" : __DIR__"house2.c",
    ]));

    set("objects", ([
        __DIR__"npc/qinqin.c" : 1,
    ]));

    setup();
}
