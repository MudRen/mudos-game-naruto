#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���]���a");
        set("long", @LONG
�ж����\��ۤ@�ǰ��Y�����˹��~�A���Ȯ�l�d�l�]�����O�Ѱ�
�Y�s���A���H�ݤF���I��򪺡C�@���_�Ӧ~�����p�����]�ڦѤH��
���b���e���@�i���ȤW�A�L�ξU�Q�������n�ۥ|�P�ݡA������������
�إ����H�F�Ѩ�L�i�O���]�@�ڤ��u��������C
LONG);
    set("exits", ([
        "west" : ([ "filename" : __DIR__"bone.c",
                       "x_axis" : 16,
                       "y_axis" : 4,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/lon.c" : 1,
    ]));
    setup();
}
