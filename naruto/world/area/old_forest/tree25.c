#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�ˤW�K");

    set("long", @long
�|�P��ۤp�p���O�l�A�J�Ӥ@�ݥi�H�o�{�q�o�̩~�M����@�s��
�~�@�����W�Ӫ���K�I�u���|�P���M�_�X�F���֤g�ۡA�L�̤⮳�}�b
�A�j���O�b�o�̰�ŧ�J�I�̡C
long);
    set("exits", ([
        "east" : __DIR__"tree26.c",
        "south" : __DIR__"tree31.c",
    ]));
    set("objects", ([
        __DIR__"npc/shooter.c" : 2,
    ]));
    setup();
}
