#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�ӤH��");
    set("long", @LONG
�G�m��²�檺�ӤH�a�A�����@��j�ӤH���|�G�N��a�̧G�m���D
�`���ءC�u���@�쳻�۰�s�{���ӤH���}�}���a��A�A�V�A���P�A��
�o�u�������U�ا@���C�u�����w�ͭ��]�S���Y���̪o�Q��L�����
�̳o�������ɦ���I�v�ӤH���ܤ��������˵ۡC
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 31,
                       "y_axis" : 7,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/seller.c" : 1,
    ]));
    setup();
}
