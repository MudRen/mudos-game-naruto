#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "²�����ж�");
    set("long", @LONG
�ж����D�`²���A���F���n�����~���~�X�G����]�S���A�ж���
���F�@�Өk�l�A�y�W�]�O�S�����A�X�G�����ĤJ�o���Ŷ������A�L
���G�]���Ӧb�N�A���s�b�A�N��A�i�J�F�Τl�A�L�]�̵M�@�ʤ]����
�����b��a�A���Ӥ��|�u�O�����a�C
LONG);
    set("exits", ([
        "north" : __DIR__"hall3.c",
    ]));
    set("objects", ([
        __DIR__"npc/lu.c" : 1,
    ]));
    setup();
}