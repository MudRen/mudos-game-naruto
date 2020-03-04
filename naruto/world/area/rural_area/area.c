#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "�m���A��");
    set("x_axis_size", 41);            // ��V�j�p
    set("y_axis_size", 31);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_pull", "pull");
}
void do_check(object me)
{
    mapping cnd = ([]);
    if( random(5) > 3 ) {
        message_vision("���䪺�A�ҹ��$N�j�ۡG"HIG"�ޡI�F���򰽩ާ@���I\n"NOR, me);
        tell_object(me,CYN"�A�s���k��@�ǡA�Ȯɤ����A�өުF��F�C\n"NOR);

        cnd["name"] = HIG"����"NOR;
        cnd["duration"] = 180;

        me->set_condition("pull_pill", cnd);
    }
}
int do_pull(string arg)
{
    object me, area, item;
    int x, y;

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->query_level() < 15 ) return notify_fail("�A�S���x�l���޹A�@���C\n");
    if( me->query_condition("pull_pill") != 0 ) return notify_fail("�A�ҥ��n�ۧA�O�A���I�A�өާa�C\n");
    if( me->is_busy() ) return notify_fail("���Ӫ��ĤT����h�ި�L�@���C\n");

    if( x >= 23 && x <= 27 && y >= 4 && y <= 12 ) {
        message_vision("$N���"HIR"�ڽ��Y"NOR"�ΤO�@��A�w�O��"HIR"���ڽ�"NOR"���ޥX�ӤF�C\n", me);

        item = new(__DIR__"item/pill_obj02.c");
        if( item->move(me) ) tell_object(me,HIR"(�A�o��@�ڬ��ڽ�)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIR"(�A�o��@�ڬ��ڽ��A���O���b�a�W�F)\n"NOR);
        }
        me->start_busy(2);
        do_check(me);
        return 1;
    } else if( x >= 29 && x <= 36 && y >= 8 && y <= 12 ) {
        message_vision("$N����W�J�g�[���A���"RED"�p����"NOR"���y���A�N"RED"�p����"NOR"��X�ӤF�C\n", me);

        item = new(__DIR__"item/pill_obj04.c");
        if( item->move(me) ) tell_object(me,HIR"(�A�o��@���p����)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIR"(�A�o��@���p���ԡA���O���b�a�W�F)\n"NOR);
        }
        me->start_busy(2);
        do_check(me);
        return 1;
    } else if( x >= 27 && x <= 36 && y >= 18 && y <= 20 ) {
        message_vision("$N���X����"HIG"�Ե�"NOR"������A�ΤO�@�ޱN"HIG"�Ե�"NOR"��ʩޤF�X�ӡC\n", me);

        item = new(__DIR__"item/pill_obj01.c");
        if( item->move(me) ) tell_object(me,HIG"(�A�o��@�ʵԵ�)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIG"(�A�o��@�ʵԵ�A���O���b�a�W�F)\n"NOR);
        }
        me->start_busy(2);
        do_check(me);
        return 1;
    } else if( x >= 27 && x <= 36 && y >= 22 && y <= 24 ) {
        message_vision("$N����"HIG"���"NOR"�����ݡA�����a���ۤg�[����t��F�X�ӡA�����S�˨�"HIG"���"NOR"�C\n", me);

        item = new(__DIR__"item/pill_obj03.c");
        if( item->move(me) ) tell_object(me,HIG"(�A�o��@�ڪ��)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIG"(�A�o��@�ڪ��A���O���b�a�W�F)\n"NOR);
        }
        me->start_busy(2);
        do_check(me);
        return 1;
    }
    return notify_fail("�o�̦��G�u�������ޡC\n");
}
