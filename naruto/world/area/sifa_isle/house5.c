#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�ڭ��ж�");
    set("long", @LONG
�ж����a�O�����ڦ����ѽL�A�ж����\�]�]�X�G���O�ڦ����ا�
�C�Ф����|�P���O���d�A�d�l�̩񺡤F�U���U�˪����y�A�Ф�������
�O�@�Ӥj���l�A�l�e���Ȥl�W���ۤ@�ӻ�l�������H�C
LONG);
    set("exits", ([
        "south" : __DIR__"hall4.c",
    ]));
    set("objects", ([
        __DIR__"npc/ku.c" : 1,
    ]));
    setup();
}