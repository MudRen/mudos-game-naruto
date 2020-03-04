#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�x����");
    set("long", @long
�p�ж��A�Ф����������Ӧ��G�i�H��ʪ������A�A�J�Ӫ���s
�F�@�U�o�Ӿ����A�o�{���i�H���W�Ω��U��ʡA�i��n���өT�w��
�W�h�h��ʾ�������w�����I�A�~�|�o�ͨƱ��a�C
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"hole_2b.c",
                      "x_axis": 11,
                      "y_axis": 4,
                 ]),
    ]));
    set("detail", ([
        "����": "���G�i�H�W��(pushup)�B�U��(pushdown)�C",
    ]));
    setup();
}
void init()
{
    add_action("do_pushup", "pushup");
    add_action("do_pushdown", "pushdown");
}
int do_pushup(string arg)
{
    int i = this_player()->query_temp("quest/music_D");
    if( arg == "����" ) {
        if( this_player()->query_temp("quest/music_D") < -4 ) {
            message_vision("�����n����쩳�F�C\n", this_player());
            return 1;
        }
        if( !this_player()->query_temp("quest/music_F") ) {
            message_vision("�������G�L�k��ʡC\n", this_player());
            return 1;
        }
        message_vision("$N�ΤO���N�������W��F�@��C\n", this_player());
        this_player()->add_temp("quest/music_D", -1);
        return 1;
    }
    return notify_fail("�ثe�ҧ�ʪ���׬� "HIY+i+NOR" �C\n");
}
int do_pushdown(string arg)
{
    int i = this_player()->query_temp("quest/music_D");
    if( arg == "����" ) {
        if( this_player()->query_temp("quest/music_D") > 14 ) {
            message_vision("�����n����쳻�F�C\n", this_player());
            return 1;
        }
        if( !this_player()->query_temp("quest/music_F") ) {
            message_vision("�������G�L�k��ʡC\n", this_player());
            return 1;
        }
        message_vision("$N�ΤO���N�������U��F�@��C\n", this_player());
        this_player()->add_temp("quest/music_D", 1);
        return 1;
    }
    return notify_fail("�ثe�ҧ�ʪ���׬� "HIY+i+NOR" �C\n");
}
