/* write by -Acme- */

#include <room.h>

inherit HOCKSHOP;

void create()
{
    set("short", "�츭���E");

    set("long", @long
�o�̬O�츭���������W�����E�A�b���E���j���W�豾�ۤ@���j��
�B�A�W�Y�g�ۡu��������A����۴ۡv�ݨӳo�����E�@�w�O���©��F
�C�j���K�]��A�i�H�ݨ��̭����ӼL�n���ת�����A���b���ݵۻL��
�Ƶۤj��j��ժ�᪺�Ȥl�C
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 33,
                      "y_axis": 30,
                 ]),
    ]));

    setup();
}
