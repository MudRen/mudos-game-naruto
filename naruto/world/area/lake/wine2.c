#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @long
�s�����᭱�~�M���@���K���A���O�K���]�Q�j���R���n�C��K
�����ܧΡA�q�o�̥i�H�ݨ�~���w�g�Q�j�񪺯}�H�۶���n�A�L�k
�q�o�̨���~���h�F�C
long);
    set("exits", ([
        "east" : __DIR__"wine.c",
    ]));
    set("objects", ([
    __DIR__"npc/zombie3.c" : 1,
    ]));
    setup();
}
