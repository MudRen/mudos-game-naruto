#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�D�ǩж�");
    set("long", @LONG
��өж��N���ӯD�ǡA�ר�O�Ф������������j�D���A�̭����G
�٦���n�������A�������_�X�w�j�C�D���e���\�ۤ@�i���ӥX�{�b�D
�Ǥ��o��o�ܷf�t�����A��W���\�ۼ����˪������C
LONG);
    set("exits", ([
        "north" : __DIR__"hall4.c",
    ]));
    set("objects", ([
        __DIR__"npc/ka.c" : 1,
    ]));
    setup();
}