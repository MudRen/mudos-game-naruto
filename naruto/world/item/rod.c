#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

// �@�몺��
string *fish_list = ({
    "/world/item/fish1.c", "/world/item/fish2.c", "/world/item/fish3.c",
    "/world/item/fish4.c", "/world/item/fish5.c", "/world/item/fish6.c",
});

// �S���~
string *spec_list = ({
    "/world/area/wild/npc/eq/wolf_head.c",     // �T�Y
    "/world/area/wild/npc/eq/pig_head.c",      // ���Y
    "/world/area/muye/npc/eq/mouse_head.c",    // ���Y
    "/world/eq/head/boiler.c",                 // ��l
    "/world/eq/face/fglasses.c",               // ����
    "/world/eq/belt/hoop.c",                   // �I�԰�
    "/world/wp/radish.c",                      // �ڽ�
    "/world/wp/rattan.c",                      // �ñ�
    "/world/wp/sword.c",                       // �u�C
    "/world/wp/dagger.c",                      // �W�L
    "/world/wp/butcher-blade.c",               // ���ޤM
    "/world/area/muye/npc/eq/go_mouth.c",      // ���L
});


void create()
{
    set_name("����", ({ "fishing rod", "rod" }));
    set_weight(15000);
    setup_weapon(4, 8, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 1000);
        set("long", "�@�ڴ��q������A�i�H��Z���ϥΡA�]�i�H���ӳ���(fishing)�A�C\n"
                    "��A���֤F�i�H���(giveup)�����C\n" );
    }

    setup();
}
void init()
{
    if( environment(this_object()) && userp(environment(this_object())) ) {
        add_action("do_fishing", "fishing");
        add_action("do_giveup", "giveup");
    }
}

int do_giveup(string arg)
{
if( !this_player()->query_temp("is_fishing") )
return notify_fail("�A�S���b�����C\n");
    tell_object(this_player(), "�A����~�򳨳��C\n");
    this_player()->delete_temp("is_fishing");
    return 1;
}

int do_fishing(string arg)
{
int delay;
    object env, me = this_player();

    if( !objectp(env = environment(me)) ) return 0;

    if( !this_object()->query("equipped") ) 
        return notify_fail("�����˳�(wield)�����~�i�H�����C\n");

    if( me->query_temp("weapon/righthand") != this_object() ) 
        return notify_fail("�����˳�(wield)�����~�i�H�����C\n");
    if( me->query_temp("is_fishing") ) return notify_fail("�A�w�g�b�����F�C\n");
    if( me->is_fighting() || me->is_busy() ) return notify_fail("�A���b���A�S��k�����C\n");

    if( env->is_area() ) {
        int x, y;
        x = me->query("area_info/x_axis");
        y = me->query("area_info/y_axis");
        if( !env->query_data(x, y, "fishing") ) return notify_fail("�o�̤��೨���I\n");
    } else {
        if( !env->query("fishing") ) return notify_fail("�o�̤��೨���I\n");
    }
    switch( random(3) ) {
        case 0:
            message_vision("$N�ΤO�⳨�u�Ϩ�򤤥��A�@���ѧ��b����A�}�l���۳��W�_...\n",me);
            break;
        case 1:
            message_vision("$N�H��q�a�W��F�X���L�C������A�@�ϳ��u��򤤥h�A�}�l���_����...\n",me);
            break;
        default:
            message_vision("$N�⳨�u�z�F�z�A�j�W�F�X���C�Y�h�A�H�Y�ϤF�X�h�A�}�l���_����...\n",me);
            break;
    }

    me->set_temp("is_fishing", 1);

delay = 5 + random(5);

me->start_busy(delay);

    // �i�J���� function
    call_out("fishing_2", delay, me);

    return 1;
}

int fishing_2(object me)
{
    int x=0, y=0, delay;
    object item, env;

    if( !me ) return 1;

    if( !me->query_temp("is_fishing") ) return do_giveup("");
    if( !this_object()->query("equipped") ) return do_giveup("");
    if( me->query_temp("weapon/righthand") != this_object() ) do_giveup("");
    if( !objectp(env = environment(me)) ) return do_giveup("");
    if( me->is_fighting() ) return do_giveup("");

    if( env->is_area() ) {
        x = me->query("area_info/x_axis");
        y = me->query("area_info/y_axis");
        if( !env->query_data(x, y, "fishing") ) return do_giveup("");
    } else {
        if( !env->query("fishing") ) return do_giveup("");
    }

    switch( random(me->query_temp("is_fishing")) ) {
        case 0: message_vision("$N�r�ۤ@�ӡu���I�Y�v�A��ӬO�������쥴�ߺΤF....\n",me);  break;
        case 1: message_vision("$N���_���ӰʤF�X�U��}�A�S���b����A�}�l���_����....\n",me); break;
        case 2: message_vision("$N�o�X�@�}���q���s�A�ݨӬO�����W�_���ۤ��@�ФF....\n",me); break;
        case 3: message_vision("$N�@���W������A�~�o�{����w�g�Q�Y�����F...\n",me); break;
        case 4: message_vision("$N���^�F���u�A���G�@�������S������...\n",me); break;
        case 5: message_vision("$N��榣�������^���u�A���G����@�}�ä�A�k��h�F...\n",me); break;
        default:
            if( random(100) > 1 ) {     // �����@�볽
                item = new( fish_list[random(sizeof(fish_list))] );
                if( !objectp(item) ) {
                    message_vision("$N�o�{�o�઺���w�g�Q�����F�A�K���_�F����C\n",me);
                    me->delete_temp("is_fishing");
                    return 1;
                }
                message_vision("$N�⤤�����u�@��A��ӬO����W���F�I�I\n",me);
                message_vision("$N�n��H�v�C�C�ۦ��^���u�A�o�{���W�@"
                                + ( item->query("base_unit") ? item->query("base_unit") : item->query("unit") ) + 
                               "$n�F...\n", me, item);
            } else {                    // �����S��
                item = new( spec_list[random(sizeof(spec_list))] );
                if( !objectp(item) ) {
                    message_vision("$N�o�{�o�઺���w�g�Q�����F�A�K���_�F����C\n",me);
                    me->delete_temp("is_fishing");
                    return 1;
                }
                message_vision("$N�⤤�����u�@��A��ӬO����W���F�I�I\n", me);
                message_vision("$N�n��H�v�C�C�ۦ��^���u�A�o�{����ө_�Ǫ����~...\n", me);
            }

            if( !item->move(me) ) {
                message_vision("$N�oı���W�����O�F��A�K��$n��^�����F...\n", me, item);
                destruct(item);
            }

            me->set_temp("is_fishing", -1-random(3));
            if( me->query_temp("is_fishing") <= 0 )
                me->set_temp("is_fishing", 1);
            break;
    }

    me->add_temp("is_fishing", 1);

    delay = 5 + random(10);
me->start_busy(delay);

    // �i�J���� function
    call_out("fishing_2", delay, me);

    return 1;
}
