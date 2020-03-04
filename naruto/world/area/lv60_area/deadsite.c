#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "���`�M��");
    set("x_axis_size", 49);            // ��V�j�p
    set("y_axis_size", 49);            // �a�V�j�p
    setup();
    set("no_recall", 1);
}

void init()
{
    add_action("do_scale", "scale");
    add_action("do_pass", "pass");
}

int do_scale(string arg)
{
    int x, y, i;
    object me, dolomite, area;
    string area_file = "/world/area/lv60_area/deadcity.c";
    me = this_player();

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;

    if( !userp(me) || x != 24 || y != 36 ) return 0;
    if( me->query_temp("dolomite_ok") ) {
        message_vision(CYN"�Ѭi��誺���o�{�F$N��A�ߨ�o�X�m���N$N�l�F�i�h�C\n"NOR, me);
        if( !area_move(area, me, 27, 25) ) return 0;
        return 1;
    }
    if( userp(me) && !me->query("dolomite_amount") ) me->set("dolomite_amount", 150+random(450));

    i = me->query("dolomite_amount");

    if( objectp(dolomite = present("_DOLOMITE_", me)) ) {
        if( me->query("dolomite_amount") <= dolomite->query_amount() ) {
            message_vision("$N���X�F"+chinese_number(i)+"��ۦǩ�b�Ѭi�W�C\n"NOR, me);
            message_vision(CYN"\n���q���G��n�A�Ѭi�����᩹�e�@���A�᭱�������}�@�D�p�_���M�N�Ů�l�J�I\n$N�]�������Ӫ�A�M�Ѭi�W���ۦǤ@�_�Q�l�J�A���h���Ū��Ѭi�S�^�_���쪬�C\n\n"NOR, me);
            if( !area_move(area, me, 27, 25) ) return 0;
            dolomite->add_amount(-i);
            if( !dolomite->query_amount() ) destruct(dolomite);
            me->delete("dolomite_amount");
            if( me->query_level() < 41 ) me->set_temp("dolomite_ok", 1);
            else if( me->query_temp("dolomite_ok") ) me->delete_temp("dolomite_ok");
        } else {
            i = me->query("dolomite_amount") - dolomite->query_amount();
            tell_object(me, "�`�@�٤֤F"+chinese_number(i)+"��ۦǡA�������A�@����a�C\n"NOR);
        }
        return 1;
    }
    tell_object(this_player(),"�Ѭi�W�B�{�X�Ʀr "HIY+i+NOR" �������D�O����N��C\n"NOR);
    return 1;
}

int do_pass(string arg)
{
    object me, area;
    string area_file = "/world/area/muye/deadforest.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "�K�L" ) return 0;
    if( me->query("area_info/x_axis") != 24 || me->query("area_info/y_axis") != 0 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�V�O�a�N�������i�Ŷ����j����L���C\n", me);
    if( !area_move(area, me, 46, 48) ) return 0;
    message_vision("$N�n���e���~���F�i�ӡC\n", me);
    return 1;
}
