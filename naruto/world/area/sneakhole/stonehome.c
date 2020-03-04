#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�ۤ��");
    set("long", @long
�|�P�Ѥ�O�ҷf�ت��p�ж��A�V�V�|�P����O���ܵ���A�ݨ�
��O�᭱�٬O�o�}�������ۡC�ߤ@���P���a��N�O�Щ�������W��
�ۤ@���޲����۪��A�۪����|�P����ۤ��P�����šA�ݤ[�F�ٯu�O
���H�P���Y�w�دt���Ἲ�áA�ϩ��Q�g�b��F�A�������h�N�ѡC
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"hole_2b.c",
                      "x_axis": 17,
                      "y_axis": 1,
                 ]),
    ]));
    set("detail", ([
        "�۪�": "�۪��W�g�F�u�L�n�v�G�r�A���G�i�H����(push)�C",
    ]));
    setup();
}
void init()
{
    add_action("do_push", "push");
}
int do_push(string arg)
{
    string area_file = __DIR__"music.c";
    int i;
    object area;
    if( arg == "�۪�" ) {
        if( this_player()->query_temp("quest/music_F") >= 1 &&
            this_player()->query_temp("quest/music_A") == 0 &&
            this_player()->query_temp("quest/music_B") == 0 &&
            this_player()->query_temp("quest/music_C") == 0 &&
            this_player()->query_temp("quest/music_D") == 0 &&
            this_player()->query_temp("quest/music_E") == 0 ) {

            if( !objectp(area = load_object(area_file)) ) return 0;
            if( !area->is_area() ) return 0;
            message_vision("$N�ΤO���۪��A�}�U���M�X�{�@�Ӥj�}���F�U�h�C\n", this_player());
            if( !area_move(area, this_player(), 7, 19) ) return 0;
            message_vision("$N�q�K�D�^�F�i�ӡC\n", this_player());
            this_player()->delete_temp("quest/music_A");
            this_player()->delete_temp("quest/music_B");
            this_player()->delete_temp("quest/music_C");
            this_player()->delete_temp("quest/music_D");
            this_player()->delete_temp("quest/music_E");
            this_player()->delete_temp("quest/music_F");
            return 1;
        } else
        if( this_player()->query_temp("quest/music_F") >= 1 ) {
            message_vision("$N�ΤO�����ۥ۪��A���F�����n�o�S����Ʊ��o�͡C\n", this_player());
            return 1;
        }
        message_vision("$N�ΤO�����ʥ۪��A�u���|�P���M�T�_�F���Ӱ��C���P������C\n", this_player());
        i = random(10)+1;
        this_player()->add_temp("quest/music_A", i);
        message_vision("�c�����G"HIR+i+NOR"\n"NOR, this_player());
        i = random(10)+1;
        this_player()->add_temp("quest/music_B", i);
        message_vision("�Ӥ����G"HIR+i+NOR"\n"NOR, this_player());
        i = random(10)+1;
        this_player()->add_temp("quest/music_C", i);
        message_vision("�������G"HIR+i+NOR"\n"NOR, this_player());
        i = random(10)+1;
        this_player()->add_temp("quest/music_D", i);
        message_vision("�x�����G"HIR+i+NOR"\n"NOR, this_player());
        i = random(10)+1;
        this_player()->add_temp("quest/music_E", i);
        message_vision("�Ф����G"HIR+i+NOR"\n"NOR, this_player());
        this_player()->add_temp("quest/music_F", 1);
        return 1;
    }
    return notify_fail("�A�Q���ʤ���H\n");
}
