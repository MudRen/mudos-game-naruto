#include <ansi.h>

inherit AREA;

string *gowhere = ({ "go north", "go south", "go east", "go west",
                     "go northeast", "go northwest", "go southeast", "go southwest" });

void create()
{
    set("name", "���`����");
    set("x_axis_size", 31);            // ��V�j�p
    set("y_axis_size", 31);            // �a�V�j�p
    setup();
    set("no_recall", 1);
}
void init()
{
    add_action("do_fling", "fling");
    add_action("do_climb", "climb");
}
int do_fling(string arg)
{
    object me, obj, mob;
    int x, y, i, j;

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( userp(me) && x == 25 && y == 27 ) {

        if( !arg ) return notify_fail("�A�Q�n�ᤰ��F��H\n");
        if( me->is_busy() ) return notify_fail("�A���b���L���A����ʧ@�C\n");
        if( !objectp(obj = present(arg, me))) return notify_fail("�A���W�S���o�˪F��C\n");
        if( obj->query("no_drop") ) return notify_fail("�o�˪F�褣���H�N���C\n");
        if( obj->query("keep_this") ) return notify_fail("�o�˪F��A�w�g keep �L�k���C\n");
        if( obj->query("equipped") ) return notify_fail("�o�˪F��A�w�g�˳ƵۡA�L�k���C\n");

        if( obj->query("name") == HIM"��"HIC"��"NOR ) {

            i = random(5) + 1;

            message_vision("$N�N"+obj->query("name")+"��i�a�}���A�|�P���M�_�ʤF�_�ӡA�n���ݨ�"+chinese_number(i)+"�D�¼v«�X�I\n"NOR, me);

            if( !obj->query_amount() ) destruct(obj);
            else obj->add_amount(-1);

            for(j=0;j<=i;j++) {
                mob = new(__DIR__"npc/mindflayer.c");
                area_move(environment(me), mob, 1+random(29), 1+random(23));
            }
        } else {
            message_vision("$N�N"+obj->query("name")+"��i�a�}���A���O�S�o�ͥ���ơC\n"NOR, me);
            if( !obj->query_amount() ) destruct(obj);
            else obj->add_amount(-1);
        }
        me->start_busy(2);
        return 1;
    }
    return 0;
}
int do_climb(string arg)
{
    object me, area;
    string area_file = "/world/area/lv60_area/deadsite.c";

    me = this_player();

    if( !arg ) return 0;
    if( arg != "÷�l" && arg != "÷�Y" ) return 0;
    if( me->query("area_info/x_axis") != 27 || me->query("area_info/y_axis") != 25 ) return 0;

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N�԰_÷�l�j�b���W�A�}��������F�W�h�C\n", me);
    if( !area_move(area, me, 24, 36) ) return 0;
    message_vision("$N�q���䪺�p�_�p�F�X�ӡC\n", me);
    return 1;
}
int valid_leave(object me, string dir)
{
    object ob;
    int x, y;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    ob = this_object();

    if( userp(me) && ob->query_data(x, y, "move") && random(100) < 60 && !me->query_temp("gowhere")) {
        me->add_temp("gowhere", 1);
        me->force_me(gowhere[random(sizeof(gowhere))]);
        me->force_me(gowhere[random(sizeof(gowhere))]);
        me->delete_temp("gowhere");
        message_vision(HIW"$N�g���F����...�~�M�ۤv��B�ö]...\n"NOR, me);
        return 1;
    }
    return ::valid_leave(me, dir);
}
