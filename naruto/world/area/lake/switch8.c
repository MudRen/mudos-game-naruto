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
        "west" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 35,
                      "y_axis": 16,
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
        if( this_player()->query_temp("quest/opengold") > 2) {
            message_vision("$N�ΤO���N�}�����U���C\n", this_player());
            message_vision("���O�}���w�g���쩳�F�A�S��k�b���U�h�C\n"NOR, this_player());
            return 1;
        } else
        if( this_player()->query_temp("quest/opengold") == 2) {
            message_vision("$N�ΤO���N�}�����U���C\n", this_player());
            message_vision("�uť���B�F���n����A�u�I�v���@�n���T��A�s���������F�C\n"NOR, this_player());
            this_player()->add_temp("quest/opengold", 1);
            return 1;
        }
        message_vision("$N�ΤO���N�}�����U���C\n", this_player());
        message_vision("���O�}�����G�Q���򵹥d��A�����U�h�C\n"NOR, this_player());
        return 1;
    }
    return notify_fail("�A�Q�Ұʤ���H\n");
}
int do_close(string arg)
{
    if( arg == "�}��" ) {
        if( this_player()->query_temp("quest/opengold") == 3) {
            message_vision("$N�ϺɦY�����O��N�}�����W���C\n", this_player());
            message_vision("�����S���s��ʤF�_�ӡA���B�u�F���v�n���_�C\n"NOR, this_player());
            this_player()->add_temp("quest/opengold", -1);
            return 1;
        }
        message_vision("$N�ϺɦY�����O��N�}�����W���C\n", this_player());
        message_vision("���O�}���w�g���쳻�F�A�ռo�\�ҡC\n"NOR, this_player());
        return 1;
    }
    return notify_fail("�A�Q�����H\n");
}
