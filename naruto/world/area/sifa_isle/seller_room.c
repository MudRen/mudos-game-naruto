#include <room.h>

inherit HOCKSHOP;

void create()
{
        set("short", "���x��Q");
        set("long", @LONG
�]�����ۥH���j������|�]�Ӱ�ŧ�q�k�q�A�ɭP���x�h�L�̱`��
��@�ǥΤ��W�����骫�~�A���y���ӤH���W�ݷǤF�o�ӰӾ��A�d�߸U
�W�s�X�F�Ҧ��ӤH���|����ש�b�F�����q�k�q�W�}�F�Ĥ@�a�]�O��
�@���@�a������ʡC
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 35,
                     "y_axis" : 76,
                  ]),
    ]));
    setup();
}
