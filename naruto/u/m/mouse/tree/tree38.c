#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�g�ۧ�");

    set("long", @long
���B���G�i�Hť��@�ǧn���n�A��ܳo���������B�۪����l����
�F�A���M�b�o�K�L�����n�������Ƕ}�C�p�G���Q�h�g�۪����l�A�i�H
�q��~����K���^�h�C
long);
    set("exits", ([
        "west" : __DIR__"tree37.c",
    ]));
    set("detail", ([
        "��K": "��~���U�Ӫ���K�A�n��(climb)�W�h�p�߭�~�l�A���g�۳�C",
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
    message_vision("$N�w�w�����F�W�h�C\n", this_player());
    this_player()->move(__DIR__"tree33.c");
    message_vision("$N�q�U�����W�ӡC\n", this_player());
    return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
