#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�˪K��");

    set("long", @long
�o�̦��G�O�𪺤��ߪ���A��K�����۾�F���W�k�ɡA�]�\�i�H
���W���A����󰪪���h�h�C
long);
    set("exits", ([
        "west" : __DIR__"tree16.c",
        "east" : __DIR__"tree18.c",
    ]));
    set("detail", ([
        "��K": "�@���ݦ���T����K�A�i�H�յ��k��(climb)�W�h�C",
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
    message_vision("$N���c�T����K�A�ֳt�����F�W�h�C\n", this_player());
    this_player()->move(__DIR__"tree24.c");
    message_vision("$N�q�U�����F�W�ӡC\n", this_player());
    return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
