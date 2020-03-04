#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "���x�n�O�B");
    set("long", @LONG
�ж����������\�F�@�i�j��l�A�W�����F�@�ӵP�l�g�ۡG�u��~
����s���A�Ʊ榳�ӤH�K���D�[�J���x����C�A�@�P����U�c������
�A���@���~��O���M���C�v
LONG);

    set("exits", ([
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 40,
                     "y_axis" : 32,
                  ]),
        ]));

    set("objects", ([
        __DIR__"npc/nai.c": 1,
        __DIR__"npc/bone.c": 1,
    ]));
    setup();
}