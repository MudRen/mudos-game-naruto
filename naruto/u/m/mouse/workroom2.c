#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIK"���ն�"NOR);
    set("long", @long
�o�̨S�����I�Q�X�h�ܡH�ۤv�Q��k�a�I
long);
    set("exits", ([
    ]));
    set("detail", ([
        "�X�h": "��J"HIY"["HIW"gohome"HIY"]"NOR"�N��աI",
    ]));

    setup();
}
void init()
{
    add_action("do_gohome", "gohome");
}
int do_gohome(string arg)
{
    message_vision(HIY"$N�Q�@���j���F�X�h�C\n"NOR, this_player());
    this_player()->move(__DIR__"workroom.c");
    message_vision(HIY"$N���e�@�G�N�X�{�b�o�̡C\n"NOR, this_player());
    return 1;
}
