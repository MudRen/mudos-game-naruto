#include <room.h>

inherit BANK;

void create()
{
        set("short", "�Ȧ�");
        set("long", @LONG
�˨��@�ڪ��Ȧ�A�ݰ_�ӫD�`�}��....
    [�s��]�Gdeposit       [����]�Gwithdraw
    [�׿�]�Goutward       [�d��]�Gbalance
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"bone.c",
                     "x_axis" : 34,
                     "y_axis" : 15,
                  ]),
    ]));
    setup();
}
