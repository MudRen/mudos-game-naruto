#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "����h�A");
    set("x_axis_size", 31);            // ��V�j�p
    set("y_axis_size", 50);            // �a�V�j�p
    setup();
}
void init()
{
    object me = this_player();

    if( me->hasCamp("snaker") == 0 ) {
        tell_object(me,HIR"�D�H��H�����@�ǼķN�C\n"NOR);
        me->setCamp("snaker", -5000);
    }
    add_action("do_climb", "climb");
    add_action("do_recall", "recall");
    add_action("do_recall", "quit");
    add_action("do_recall", "move");
    add_action("do_recall", "sfly");
}
int do_recall()
{
    if( this_player()->query_temp("quest/marsh_stop") == 1 ) {
        tell_object(this_player(), "�A���}���b�h�A���A�S��k���}�C\n");
        return 1;
    }
}
int do_climb()
{
    if(this_player()->is_busy()) {
        tell_object(this_player(), "�A���֪��L�k�ʼu�A�𮧤@�U�a�C\n");
        return 1;
    }
    if( this_player()->query_temp("quest/marsh_stop") != 1 ) return 0;
    if( random(4) == 1) {
        message_vision(HIM"$N���W���q�h�A�����F�X�ӡI\n"NOR, this_player());
        this_player()->delete_temp("quest/marsh_stop");
        return 1;
    }
    message_vision(HIM"$N�V�O�����ʡA�S�Q��U���U�`�F�I\n"NOR, this_player());
    this_player()->start_busy(2);
    return 1;
}
int valid_leave(object me, string dir)
{
    int x, y;
    object item;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( userp(this_player()) && me->is_fighting() && y >= 25 ) {
        tell_object(me,HIR"�b�h�A���԰��ٷQ���߲��ʤӦM�I�F�I\n"NOR);
        return 1;
    }
    if( me->query_temp("quest/marsh_stop") == 1 ) {
        tell_object(me,"�A�Q�h�A�x��F�L�k���ʡI�ַQ��k��(climb)�X�ӧa�I\n");
        return 1;
    }
    if( userp(this_player()) && y >= 25 ) {
        if( random(20) == 5 ) {
            me->add_temp("quest/marsh_stop", 1);
            message_vision(HIM"$N�򪺤ӥΤO�A�C�C���i�h�A���F�I\n"NOR, me);
            return 1;
        }
    }
    // return 0; ��ܲ��ʥ���
    if( !userp(me) && x == 0 && y == 24 && (dir == "south" || dir == "southeast") ) return 0;
    if( !userp(me) && x == 22 && y == 25 && (dir == "south" || dir == "southwest" || dir == "southeast") ) return 0;
    if( !userp(me) && x == 22 && y == 26 && dir == "north" ) return 0;
    if( !userp(me) && x == 21 && y == 26 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 23 && y == 26 && dir == "northwest" ) return 0;
    if( !userp(me) && x == 14 && y == 14 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 15 && y == 14 && dir == "north" ) return 0;
    if( !userp(me) && x == 16 && y == 14 && dir == "northwest" ) return 0;
    if( !userp(me) && x == 2 && y == 25 && dir == "west" ) return 0;
    if( !userp(me) && x == 8 && y == 48 && dir == "south" ) return 0;
    if( !userp(me) && x == 7 && y == 48 && (dir == "east" || dir == "southeast") ) return 0;
    return ::valid_leave(me, dir);
}
