#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�J��");
        set("long", @LONG
�o�̴N�O�D�ڪ��J�ǤF�A�̭����ūפ�~�����X�\�h�A�|�P����
���F�_��ӷŷx�Ф��A���L�]���_��諸�Ӻ��F�A���H�ݤ��X�Ӹ̭�
�쩳�٦��S���J�C���L�{�b�o�̳s�@�Ӧu�ó��S���A�i���{�b�@�w�S
���J�b�̭��C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"marsh.c",
                       "x_axis" : 24,
                       "y_axis" : 13,
                  ]),
    ]));
    setup();
}
