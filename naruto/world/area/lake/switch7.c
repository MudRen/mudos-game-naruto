#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @long
�Ф����F�@�ӤH�����Ŷ����~�A��B���G���F�����P�}���A�]
�����[�����Φ��G�����ǯ}�l�A�����D�Ұʳo�Ƕ}���|�o�ͤ����Y
�����ơA�]�\�o���|�I�J�����N�O�]���o�Ƕ}���]�����w�C
long);
    set("exits", ([
        "east" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 31,
                      "y_axis": 15,
                 ]),
    ]));
    set("detail", ([
        "����": "���j�������A�d�U�O�k�Q�Τ�h��ʥ��C",
        "�}��": "���G�i�H�}��(open)������(close)�C",
    ]));
    setup();
}
void init()
{
    add_action("do_open", "open");
    add_action("do_close", "close");
}
int do_open(string arg)
{
    if( arg == "�}��" ) {
        if( this_player()->query_temp("quest/opengold") != 3 ||
            this_player()->query_temp("quest/bighouse") >= 1 ||
            this_player()->query_temp("quest/value") < 1) {

            message_vision("$N�ΤO���N�}�����U���C\n", this_player());
            message_vision("�}���Q�d���ܦ��A�ڥ��L�k���ʡC\n"NOR, this_player());
            return 1;
        } else
        if( this_player()->query_temp("quest/opengold") == 3 &&
            this_player()->query_temp("quest/value") < 2) {

            message_vision("$N�ΤO���N�}�����U���C\n", this_player());
            message_vision("���þ����o�X�@�n������K��������F�A���G�S��������R�C\n"NOR, this_player());
            this_player()->add_temp("quest/value", 1);
            return 1;
        }
        message_vision("$N�ΤO���N�}�����U���C\n", this_player());
        message_vision("�}���Q�d���ܦ��A�ڥ��L�k���ʡC\n"NOR, this_player());
        return 1;
    }
    return notify_fail("�A�Q�Ұʤ���H\n");
}
int do_close(string arg)
{
    if( arg == "�}��" ) {
        if( this_player()->query_temp("quest/bighouse") >= 1 ||
            this_player()->query_temp("quest/opengold") != 1) {

             message_vision("$N�ϺɦY�����O��N�}�����W���C\n", this_player());
             message_vision("$N�O�𦭥H�κɡA�}���̵M�D�����ʡC\n"NOR, this_player());
             return 1;
        } else
        if( this_player()->query_temp("quest/value") == 2 &&
            this_player()->query_temp("quest/opengold") == 1) {

             message_vision("$N�ϺɦY�����O��N�}�����W���C\n", this_player());
             message_vision("���ê������S���s�}�l�P�~�������@�P��ʡC\n"NOR, this_player());
             this_player()->add_temp("quest/value", -1);
             return 1;
        }
        message_vision("$N�ϺɦY�����O��N�}�����W���C\n", this_player());
        message_vision("$N�O�𦭥H�κɡA�}���̵M�D�����ʡC\n"NOR, this_player());
        return 1;
    }
    return notify_fail("�A�Q�����H\n");
}
