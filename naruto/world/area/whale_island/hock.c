/* write by -Acme- */

#include <room.h>

inherit HOCKSHOP;

void create()
{
    set("short", "�H�����E");

    set("long", @long
�o�̬O�H���q�W�ߤ@���@�����E�A�b���E���j���W�豾�ۤ@���j�СA
�W�Y�D�ۡu�Q�ѤE���Q�A�O�����Q�U�v�C�j���K�]��A�A�i�H�ݨ���
�����ӽ��Y������A���b���ݵۻL���Ƶۤj��j��ժ�᪺�Ȥl�C
long);

    set("exits", ([
        "north" : ([ "filename": __DIR__"area.c",
                      "x_axis": 10,
                      "y_axis": 33,
                 ]),
    ]));

    setup();
}
