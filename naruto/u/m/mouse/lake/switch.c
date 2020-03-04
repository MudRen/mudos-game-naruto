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
                      "y_axis": 3,
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
        if( this_player()->query_temp("quest/bighouse") >= 1) {
            message_vision("$N�ΤO���N�}�����U���C\n", this_player());
            message_vision("�u�O��ʪ��������G�d�줰��F��A��@��S���F�C\n"NOR, this_player());
            return 1;
        } else
        if( this_player()->query_temp("quest/opengold") < 1) {
            message_vision("$N�ΤO���N�}�����U���C\n", this_player());
            message_vision("�|�P�ǥX�u�ةԳة�....�v������n�C\n"NOR, this_player());
            this_player()->add_temp("quest/opengold", 1);
            return 1;
        }
        message_vision("$N�ΤO���N�}�����U���C\n", this_player());
        message_vision("���O�}���w�g���쩳�F�A�S��k�b���U�h�C\n"NOR, this_player());
        return 1;
    }
    return notify_fail("�A�Q�Ұʤ���H\n");
}
int do_close(string arg)
{
    if( arg == "�}��" ) {
        if( this_player()->query_temp("quest/opengold") > 1) {
            message_vision("$N�ϺɦY�����O��N�}�����W���C\n", this_player());
            message_vision("���O�}�����G�d���ܺ�A$N�������Y�j�����S�I���R�C\n"NOR, this_player());
            return 1;
        } else
        if( this_player()->query_temp("quest/opengold") == 1) {
            message_vision("$N�ϺɦY�����O��N�}�����W���C\n", this_player());
            message_vision("�u�ط�v�@�n�A���䪺�����K������ʤF�C\n"NOR, this_player());
            this_player()->delete_temp("quest/opengold");
            return 1;
        }
        message_vision("$N�ϺɦY�����O��N�}�����W���C\n", this_player());
        message_vision("���O�}���w�g���쳻�F�A�ռo�\�ҡC\n"NOR, this_player());
        return 1;
    }
    return notify_fail("�A�Q�����H\n");
}
