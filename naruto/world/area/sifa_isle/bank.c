#include <room.h>

inherit BANK;

void create()
{
        set("short", "�Ȧ�");
        set("long","�ѥ@�ɬF������~����a�Ȧ�A�i�H�O�Ҥ��|�}���C\n"
                   "[�s��]�Gdeposit       [����]�Gwithdraw\n"
                   "[�׿�]�Goutward       [�d�M]�Gbalance\n");
    set("exits", ([
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 32,
                     "y_axis" : 76,
                  ]),
    ]));
    setup();
}
