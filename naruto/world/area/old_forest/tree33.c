#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�j�ˤW�K");

    set("long", @long
���֦ӤW���g�����H�֪��ݤ��L��A���M���o�{���䪺��K�U��
�n���٦���K�i���A���M���M���O�q�V���̡A���_�X�i�H�׶}�o�Ǻ�
�l���˪��g�ۧa�C
long);
    set("exits", ([
        "west" : __DIR__"tree32.c",
    ]));
    set("detail", ([
        "��K": "�֪�(climb)�U�h�a�I�g�۴N�n�l�ӤF�C",
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
    message_vision("$N�X�ۤg�ۤ��`�N�A���������F�U�h�C\n", this_player());
    this_player()->move(__DIR__"tree38.c");
    message_vision("$N�����N�N���q�W�����F�U�ӡC\n", this_player());
    return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
