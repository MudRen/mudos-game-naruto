#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�ˮڳ�");

    set("long", @long
���e�O�@�j���L�ڿ��`����ڡA���Y��h���F����٬O��ڡA�~
�M�s��F���ݤ���A�i���o���˪L���h�򥨤j�C
long);
    set("detail", ([
        "���": "�@�ڲʤj����ڡA�A�i�H�k��(climb)�W�h�C",
    ]));
    set("exits", ([
        "north" : __DIR__"treein.c",
    ]));
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    if( arg == "���") {
    message_vision("$N��F�@���ݦ���T����ڡA�ֳt���F�W�h�C\n", this_player());
    this_player()->move(__DIR__"tree01.c");
    message_vision("$N���Y�j�����q�U�����F�W�ӡC\n", this_player());
    return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
