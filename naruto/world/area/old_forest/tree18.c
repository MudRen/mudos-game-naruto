#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�˪K��");

    set("long", @long
�o�̬O�g�ۭ̥𮧪��a��A�@�i�ξ�ڷf�����p��W��ۤj����
�����J�ˤ��C���O�L�̨S���߱��h�ܡA�]���J�I�̤w�g�X�{�F�C
long);
    set("exits", ([
        "west" : __DIR__"tree17.c",
        "east" : __DIR__"tree19.c",
    ]));
    set("objects", ([
        __DIR__"npc/warrior.c" : 1,
        __DIR__"npc/shooter.c" : 1,
    ]));
    setup();
}
