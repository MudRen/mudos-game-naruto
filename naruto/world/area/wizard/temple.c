#include <ansi.h>

inherit ROOM;


void create()
{
    set("short", "�g�a���q");
    set("long", "�@�������������g�a���q�A�A���O�S�ƥi�H�ӿN�ӭ��A�U�ܻ��o�n�G\n"
                "���N�����O���A�S�N���|�X�Ʊ��ڡC\n" );

    set("objects", ([ __DIR__"npc/temple_master": 1 ]));
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 21,
                       "y_axis" : 36,
                  ]),
        "south" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 18,
                       "y_axis" : 39,
                  ]),
        "west" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 15,
                       "y_axis" : 36,
                  ]),
        "north" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 18,
                       "y_axis" : 33,
                  ]),
    ]));

    setup();
}
