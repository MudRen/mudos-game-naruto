#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�_�c�H���a");

    set("long", @long
�ж����R���F�@�Ѱs���A�D�_�ӹ��O����s�����D�A���O�S�h�F
�@�دS�������A���G�D�@�D�N�Q�o�ح������l�ަ�C�u���@�ӤH��
�b�ж��̤j�|�A�����D�O�]������Ʊ��C
long);
    set("exits", ([
        "east" : ([ "filename": __DIR__"barren.c",
                    "x_axis": 18,
                    "y_axis": 8,
                 ]),
        "south" : ([ "filename": __DIR__"barren.c",
                     "x_axis": 15,
                     "y_axis": 11,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/ka.c" : 1,
    ]));
    set("no_recall", 1);
    setup();
}
int valid_leave(object me, string dir)
{
    object ob;

    if( !me ) return 0;
    if( dir == "south" ) { 
        if( me->query_temp("piece_test") != 1) return notify_fail("�u�����U�_�c�H�~��i�h�C\n");
    }
    return ::valid_leave(me, dir);
}
