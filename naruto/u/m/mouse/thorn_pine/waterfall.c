inherit AREA;

void create()
{
    set("name", "�F���r");
    set("x_axis_size", 21);            // ��V�j�p
    set("y_axis_size", 41);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_jump", "jump");
    add_action("do_climb", "climb");
}
int do_jump(string arg)
{
    object me, area;
    string area_file = __DIR__"waterfall.c";
    me = this_player();

    if( !arg ) return 0;
    if( arg != "�r��") return 0;

    if( me->query("area_info/y_axis") != 11 ) return 0;
    if( (me->query("area_info/x_axis") == 7) || (me->query("area_info/x_axis") == 8)  ||
        (me->query("area_info/x_axis") == 9) || (me->query("area_info/x_axis") == 10) ||
        (me->query("area_info/x_axis") == 11)|| (me->query("area_info/x_axis") == 12) ||
        (me->query("area_info/x_axis") == 13) ) {

        if( !objectp(area = load_object(area_file)) ) return 0;
        if( !area->is_area() ) return 0;
        if( !(userp(me)) ) {
            message_vision("$N���ۻ�l�A���W�������r�����F�U�h�C\n", this_player());
            if( !area_move(area, me, 7+random(7), 26) ) return 0;
            message_vision("$N�q�r���W�@���u�F�U�ӡA�h���z�z�j�s�C\n", this_player());
            return 1;
        }
        message_vision("$N���ۻ�l�A���W�������r�����F�U�h�C\n", this_player());
        if( !area_move(area, me, 7+random(7), 27+random(5)) ) return 0;
        message_vision("$N�C�}�����~�o�{�ۤv�w�g�������r���U�ݤF�C\n", this_player());
        return 1;
    }
    return 0;
}

int do_climb(string arg)
{
    object me, area;
    string area_file = __DIR__"waterfall.c";
    me = this_player();

    if( !arg ) return 0;
    if( arg != "�r��") return 0;

    if(me->is_busy()) {
        tell_object(me, "�A���b���L�A�S�Ū��r���C\n");
        return 1;
    }
    if( me->query("area_info/y_axis") != 26 ) return 0;
    if( (me->query("area_info/x_axis") == 7) || (me->query("area_info/x_axis") == 8)  ||
        (me->query("area_info/x_axis") == 9) || (me->query("area_info/x_axis") == 10) ||
        (me->query("area_info/x_axis") == 11)|| (me->query("area_info/x_axis") == 12) ||
        (me->query("area_info/x_axis") == 13) ) {

        if( random(me->query_ability("evade")) <= 100) { 
            message_vision("$N�չϪ��W�r���A���O�Q���ĤF�U�ӡI\n", this_player());
            me->damage_stat("ap", 10, me);
            me->start_busy(2);
            return 1;
        }
        if( !objectp(area = load_object(area_file)) ) return 0;
        if( !area->is_area() ) return 0;
        message_vision("$N�ֳt�����W�r���A�b�����U���M�w�w�e�i�C\n", this_player());
        if( !area_move(area, me, random(7)+7, 11) ) return 0;
        message_vision("$N�R�F�@�f��A�ש����r���W�ݤF�C\n", this_player());
        return 1;
    }
    return 0;
}
int valid_leave(object me, string dir)
{
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( !userp(me) && x == 18 && y == 1 && dir == "north" ) return 0;
    if( !userp(me) && x == 17 && y == 1 && dir == "northeast" ) return 0;
    if( !userp(me) && x == 19 && y == 1 && dir == "northwest" ) return 0;

    return ::valid_leave(me, dir);
}
