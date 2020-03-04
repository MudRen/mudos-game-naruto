#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"���줤��"NOR);

    set("long", @long
�񲴱�h�O�@���s�j���Ť��x�|�A��ӯ��쪺��K�P���w�g�X�i
��������˪L�A�ҥH�~�ϱo�U�������@�����¡A�������z���i�h�C
�p�G�Q���}�i�H���ۭ�����U�h�C
long);
    set("exits", ([
        "west" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 4,
                      "y_axis": 16,
                 ]),
        "east" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 6,
                      "y_axis": 16,
                 ]),
        "north" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 5,
                      "y_axis": 15,
                 ]),
        "south" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 5,
                      "y_axis": 17,
                 ]),
    ]));
    set("detail", ([
        "��K": "�ʧ�������j�ڡA�Q���}�N��(climb)�U�h�a�C",
    ]));
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    if( arg == "��K") {
    message_vision("$N�w�w�����F�U�h�C\n", this_player());
    this_player()->move(__DIR__"tree30.c");
    message_vision("$N�q�W�Y���F�U�ӡC\n", this_player());
    return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
