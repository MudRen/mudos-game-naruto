#include <ansi.h>
inherit ROOM;
int i;

void create()
{
    set("short","�j�ˤW�K");

    set("long", @long
�g�ۭ̰l��o�̴N���M����F�}�B�A�C�C���}�F�C�J�Ӭݬݳo��
�i�H�o�{�A���e���@�ʾ𧹥��ݤ��쳻�A�u���ݨ��F�������A����
��������K���W�����ۡA�]�\�O���W�h�����a�C
long);
    set("exits", ([
        "west" : __DIR__"tree29.c",
        "east" : __DIR__"tree31.c",
    ]));
    set("detail", ([
        "��K": "������K��������W�Y�A���M���|�q�V����A�H�K��@����(climb)�W�h�a�C",
    ]));
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    i = random(4);
    if( arg == "��K") {
    if(i==1) {
    message_vision("$N��_�䤤�@�ھ�K�C�C���F�W�h�C\n", this_player());
    this_player()->move(__DIR__"tree13.c");
    message_vision("$N�����D�q���̪��F�L�ӡC\n", this_player());
    return 1;
    }
    else if(i==2) {
    message_vision("$N��_�䤤�@�ھ�K�C�C���F�W�h�C\n", this_player());
    this_player()->move(__DIR__"tree04.c");
    message_vision("$N�����D�q���̪��F�L�ӡC\n", this_player());
    return 1;
    }
    else if(i==3) {
    message_vision("$N��_�䤤�@�ھ�K�C�C���F�W�h�C\n", this_player());
    this_player()->move(__DIR__"tree15.c");
    message_vision("$N�����D�q���̪��F�L�ӡC\n", this_player());
    return 1;
    }
    else if(i==4) {
    message_vision("$N��_�䤤�@�ھ�K�C�C���F�W�h�C\n", this_player());
    this_player()->move(__DIR__"tree27.c");
    message_vision("$N�����D�q���̪��F�L�ӡC\n", this_player());
    return 1;
    }
    else if(i==0) {
    message_vision("$N��_�䤤�@�ھ�K�C�C���F�W�h�C\n", this_player());
    this_player()->move(__DIR__"oldtree.c");
    message_vision("$N���W�����F�W�ӡC\n", this_player());
    return 1;
            }
    }
    return notify_fail("�A�Q������F��H\n");
}

