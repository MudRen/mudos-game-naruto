#include <room.h>

inherit BANK;

void create()
{
        set("short", "�Ȧ�");
        set("long", @LONG
�ݰ_�Ӥ����\�H�س]���ؿv�A�̭����X�x���ھ��i�H�����C
    �s���Gdeposit       �����Gwithdraw
    �׿��Goutward       �d�ߡGbalance
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 26,
                       "y_axis" : 8,
                  ]),
    ]));
        setup();
}
