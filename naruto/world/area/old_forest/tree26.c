#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�ˤW�K");

    set("long", @long
�����i�H�y�L�z�i�A���H�F�ѳo�j�˪������C���Y��h�i�H�ݨ�
�W���٦��@����j�����L�A���O��~�Ҫ�����K�o�S���~��V�W����
�A�u�੹�U���Ӥw�C
long);
    set("exits", ([
        "west" : __DIR__"tree25.c",
        "east" : __DIR__"tree27.c",
    ]));
    set("detail", ([
        "��K": "��~���W�Ӫ���K�A�Q���}�N��(climb)�U�h�a�C",
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
    message_vision("$N���c�T����K�A���շȤF�U�h�C\n", this_player());
    this_player()->move(__DIR__"tree20.c");
    message_vision("$N�q�W���ȤF�U�ӡC\n", this_player());
    return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
