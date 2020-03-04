#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "���s����");
    set("x_axis_size", 21);            // ��V�j�p
    set("y_axis_size", 21);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_recall", "recall");
    add_action("do_recall", "quit");
    add_action("do_recall", "move");
    add_action("do_recall", "sfly");
    add_action("do_not", "assign");
    add_action("do_not", "remember");
}
int do_recall(string arg)
{
    if( this_player()->query_condition("calcification")) {
        tell_object(this_player(), "�A�{�b�����p�����\�A�o�˰��C\n");
        return 1;
    }
}
int do_not(string arg)
{
    tell_object(this_player(), "�o�̪��Ϫi�v�T�L�j�A�L�k�O�Х���F��C\n");
    return 1;
}
int valid_leave(object me, string dir)
{
    object ob;
    int x, y, damage;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    ob = this_object();

    // return 0; ��ܲ��ʥ���
    if( me->query_condition("calcification") ) {
        if( random(me->query_ability("exact")) > random(200) ) {
            message_vision(HIW"$N�ߨ�q�ۦǤ��ò�X�ӤF�I\n"NOR, me);
            me->start_busy(1);
            me->delete_condition("calcification");
        } else {
            message_vision(HIW"$N�Q�ۦǵ��x��F�A�ʼu���o�I\n"NOR, me);
            me->start_busy(3);
        }
        return 1;
    }
    if( userp(me) && ob->query_data(x, y, "fire") ) {
        damage = 20 + random(150);
        me->receive_damage(damage, this_object());
        message_vision(HIR"$N���p�߳Q�u�S�����߿S�ˤF�I"NOR"("HIY+damage+NOR")\n", me);
    }
    return ::valid_leave(me, dir);
}
