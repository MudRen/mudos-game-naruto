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
        "east" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 9,
                      "y_axis": 16,
                 ]),
        "west" : __DIR__"tree26.c",
    ]));
    set("objects", ([
        __DIR__"npc/shooter.c" : 3,
    ]));
    setup();
}
