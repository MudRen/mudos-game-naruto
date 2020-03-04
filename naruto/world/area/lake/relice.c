inherit AREA;

void create()
{
    set("name", "�򩳿�}");
    set("x_axis_size", 40);            // ��V�j�p
    set("y_axis_size", 20);            // �a�V�j�p
    setup();
}
void init()
{
    add_action("do_out", "out");
    add_action("do_push", "push");
}
int do_out(string arg)
{
    object me, area;
    string area_file = __DIR__"lake.c";
    me = this_player();
    if( !arg ) return 0;
    if( arg != "��}" && arg != "���" && arg != "�X�J�f" ) return 0;
    if( me->query("area_info/x_axis") != 20 || me->query("area_info/y_axis") != 19 ) return 0;
    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�����񪺥X�f�B�A�w�w��F�X�h�C\n", this_player());
    if( !area_move(area, me, 6, 12) ) return 0;
    message_vision("$N�g���F��V�A���o�̤~�{�o�L�Ӫ����C\n", this_player());
    return 1;
}
int do_push(string arg)
{
    object me, area;
    string area_file = __DIR__"treasury.c";
    me = this_player();
    if( me->query("area_info/x_axis") == 23 && me->query("area_info/y_axis") == 12 ) {
        if( arg == "�Ǫ�" || arg == "��" ) {
            if( me->query_temp("quest/bighouse") == 3) {
                message_vision("$N���}�F�@�Ǫ��K���A���������F�i�h�C\n", this_player());
                me->move(__DIR__"house4.c");
                message_vision("$N�q�~�������ȤF�i�ӡC\n", this_player());
                return 1;
                }
            message_vision("$N�N�����}�A���F�i�h�C\n", this_player());
            me->move(__DIR__"house3.c");
            message_vision("$N�q�~�����i�ӡC\n", this_player());
            return 1;
            }
        return notify_fail("�A�Q������H\n");
    }
    if( me->query("area_info/x_axis") == 19 && me->query("area_info/y_axis") == 1 ) {
        if( arg == "���y" ) {
            if( me->query_temp("quest/value") == 2) {
                if( !objectp(area = load_object(area_file)) ) return 0;
                if( !area->is_area() ) return 0;
                message_vision("$N�N���y���Ϥ�V���A�ǥX�i�����n���C\n", this_player());
                message_vision("��M���D�b$N�}�U�}�ҡA$N�@�Ӥ�í�����^�F�i�h�C\n", this_player());
                if( !area_move(area, me, 9, 1) ) return 0;
                message_vision("$N�q�W���@���u�F�i�ӡC\n", this_player());
                return 1;
            }
            if( me->query_temp("quest/opengold") == 3) {
                message_vision("$N�w�w�����}���y�A���i�U�����a�U�ǥh�C\n", this_player());
                me->move(__DIR__"wine.c");
                message_vision("$N�q�W�����U�ӡC\n", this_player());
                return 1;
            }
        message_vision("$N�κɦU�ؤ�k���ʤ��y�A�����y�̵M�@�L���R�C\n", this_player());
        return 1;
        }
    return notify_fail("�A�Q������H\n");
    }
    return 0;
}
