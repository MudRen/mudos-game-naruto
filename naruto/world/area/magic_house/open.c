#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�~��}����");
    set("long", @LONG

�o�өж��̥u���@�Ӷ}���A����g�ۡy�����H���ФűҰʶ}���z

LONG);
    set("exits", ([
        "south" : ([ "filename": __DIR__"house.c",
                    "x_axis": 3,
                    "y_axis": 5,
                 ]),
    ]));
    set("detail", ([
        "�}��": "���G�i�H���̭���(push)���ˤl�C",
    ]));
    setup();
    set("no_recall", 1);
}
void init()
{
    add_action("do_push", "push");
    add_action("do_move", "move");
    add_action("do_move", "sfly");
}
int do_move(string arg)
{
    message_vision("$N���ϭ��W�ѪšA���O����г��S�^�F�U�ӡC\n", this_player());
    return 1;
}
int do_push(string arg)
{
    int i, j, x, y;
    object mob, room;

    if( query("MONSTER_WAR") != 0 ) return notify_fail("���O�}���w�g���i�h�F�C\n");
    if( this_player()->query_level() < 21 ) return notify_fail("�A�ڥ��S�x�l�h�Ұʶ}���C\n");
    if( arg == "�}��" ) {
        message_vision("$N�ΤO���N�}���¸̭����F�i�h�I\n", this_player());
        message_vision(HIR"�u���|�Pĵ�a�T�_���G�o�ͤF�����...\n"NOR, this_player());
        this_player()->start_busy(1);
        set("MONSTER_WAR", 1);
        if( !WAR_D->doStartWar(this_player(), "/world/war/magic_house.c") ) {
            tell_object(this_player(), "�}���w�g�}�F�A�~�椺�ŪŦp�]�C\n"NOR);
        }
        return 1;
    }
    return notify_fail("�A�Q������F��H\n");
}
