#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�|�U��");
    set("long", @long
�|�P�º��������H�ݤ��M���A���`���Hı�o�n�����F��b�n��
�A�ݡA��A�I�G�F�⤤������A�t�I�S�R�F�X�ӡC�u���@������G
�ꪺ���饿��ۨI�����B�飼�ӡA���G�S���򵽷N�C
long);
    set("exits", ([
        "west" : __DIR__"banquet.c",
        "south" : __DIR__"banquet5.c",
        "north" : __DIR__"banquet6.c",
    ]));
    set("objects", ([
    __DIR__"npc/zombie.c" : 3,
    ]));
    setup();
}
