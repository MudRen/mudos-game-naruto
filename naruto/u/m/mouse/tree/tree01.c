#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�˪K��");

    set("long", @long
��K�W�w�g�����Q�𸭩ұ��\�A���~�����z���i�ӡC�����ٷ|ť
��C�I�������n�P�|�P�𸭪��F�F�n�A���H��o����������s�P��`
�ȡC�C�@�B���n�p���l�l���e�i�C
long);
    set("exits", ([
        "west" : __DIR__"tree02.c",
        "east" : __DIR__"tree05.c",
        "south" : __DIR__"tree10.c",
    ]));
    set("detail", ([
        "���": "�@�ڲʤj����ڡA�A�i�H�k��(climb)�W�h�C",
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
    message_vision("$N���ۭ��ڡA�ֳt�����F�U�h�C\n", this_player());
    this_player()->move(__DIR__"tree00.c");
    message_vision("$N�y��a�ժ��q�W�����F�U�ӡC\n", this_player());
    return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
