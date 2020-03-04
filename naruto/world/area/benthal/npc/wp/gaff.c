#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

// �@�몺��
string *fish_list = ({
    "/world/area/benthal/npc/food/clam.c",
    "/world/area/benthal/npc/food/urchin.c",
    "/world/area/benthal/npc/food/cuttlefish.c",
    "/world/area/benthal/npc/food/octopus.c",
    "/world/area/benthal/npc/food/lobster.c",
});

// �S���~
string *spec_list = ({
    "/world/area/lake/npc/item/vase2.c",            // �}��~
    "/world/eq/feet/straw.c",                       // ��c
    "/world/area/old_forest/npc/eq/coco.c",         // ���l��
    "/world/eq/head/boiler.c",                      // ��l
    "/world/eq/face/fglasses.c",                    // ����
    "/world/eq/belt/hoop.c",                        // �I�԰�
    "/world/wp/radish.c",                           // �ڽ�
    "/world/area/sifa_isle/npc/wp/gun.c",           // ���x��K��
    "/world/wp/sword.c",                            // �u�C
    "/world/wp/dagger.c",                           // �W�L
    "/world/wp/pairrod.c",                          // ���I��
    "/world/area/thorn_pine/npc/wp/lines_sword.c",  // �课�C
});


void create()
{
    set_name("���e", ({ "gaff" }));
    set_weight(15000);
    setup_weapon(4, 8, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 1000);
        set("long", "�@�ڴ��q�����e�A�i�H��Z���ϥΡA�]�i�H���ӧ����(gaffing)�A�C\n"
                    "��A���֤F�i�H���(giveup)�C������u��b�u�����v������i��C\n" );
    }
    setup();
}
void init()
{
    if( environment(this_object()) && userp(environment(this_object())) ) {
        add_action("do_gaffing", "gaffing");
        add_action("do_giveup", "giveup");
    }
}

int do_giveup(string arg)
{
    if( !this_player()->query_temp("is_gaffing") )
        return notify_fail("�A�S���b������a�C\n");
    tell_object(this_player(), "�A����~�������C\n");
    this_player()->delete_temp("is_gaffing");
    return 1;
}

int do_gaffing(string arg)
{
    int delay;
    object env, me = this_player();

    if( !objectp(env = environment(me)) ) return 0;

    if( !this_object()->query("equipped") ) 
        return notify_fail("�����˳�(wield)���e��~�i�H������C\n");

    if( me->query_temp("weapon/righthand") != this_object() ) 
        return notify_fail("�����˳�(wield)���e��~�i�H������C\n");
    if( me->query_temp("is_gaffing") ) return notify_fail("�A�w�g�b������F�C\n");
    if( me->is_fighting() || me->is_busy() ) return notify_fail("�A���b���A�S��k������C\n");

    if( env->is_area() ) {
        int x, y;
        x = me->query("area_info/x_axis");
        y = me->query("area_info/y_axis");
        if( !env->query_data(x, y, "gaffing") ) return notify_fail("�o�̤��������I\n");
    } else {
        if( !env->query("gaffing") ) return notify_fail("�o�̤��������I\n");
    }
    switch( random(4) ) {
        case 0:
            message_vision("$N���_���e�A�ǳƦn�j�o�l�A���ѭn�ӭӺ������k�C\n",me);
            break;
        case 1:
            message_vision("$N�|�|���������믫�A�ֳt�a����������A�ǳƶ}�l������C\n",me);
            break;
        case 2:
            message_vision("$N�B�W�����l�F�@�j�f���S��F�U�ӡA���n�U�����ǳơC\n",me);
            break;
        default:
            message_vision("$N��w�F���e������אּ�ؼСA�b����]�U������}�l���ݮ����W��...\n",me);
            break;
    }

    me->set_temp("is_gaffing", 1);

delay = 5 + random(5);

me->start_busy(delay);

    // �i�J���� function
    call_out("gaffing_2", delay, me);

    return 1;
}

int gaffing_2(object me)
{
    int x=0, y=0, delay;
    object item, env, mob;

    if( !me ) return 1;
    if( !me->query_temp("is_gaffing") ) return do_giveup("");
    if( !this_object()->query("equipped") ) return do_giveup("");
    if( me->query_temp("weapon/righthand") != this_object() ) do_giveup("");
    if( !objectp(env = environment(me)) ) return do_giveup("");
    if( me->is_fighting() ) return do_giveup("");

    if( env->is_area() ) {
        x = me->query("area_info/x_axis");
        y = me->query("area_info/y_axis");
        if( !env->query_data(x, y, "gaffing") ) return do_giveup("");
    } else {
        if( !env->query("gaffing") ) return do_giveup("");
    }
    switch( random(me->query_temp("is_gaffing")) ) {
        case 0: message_vision("$N��F�ѥb�ѫo�䤣��b�������Aı�o�D�`�Ǥ�...\n",me);  break;
        case 1: message_vision("$N���G�ݨ�����̦��Ӽv�l�b�ʡA�@���}����o�o�{�u�O���}�c...\n",me); break;
        case 2: message_vision("$N�o�Ʀ������_���e���������W...���G�u�~�]�F�@����v�ͪ�...\n",me); break;
        case 3: message_vision("$N�o�{�������ܼv��ߨ�ΤO�@��A�o�Q�����F�����娫�F...\n",me); break;
        case 4: message_vision("$N�����G�����F�A��榣����W�����l�@�f��S��^���~��M�����...\n",me); break;
        case 5: message_vision("$N�b����襤�M������A�o���V�Q�Q��Q�F�@�y����...\n",me); break;
        case 6: message_vision("�@�����b$N���}���Ӵ�h...$N�ΤO�@�e�o�e���ۤv���}�A�h���z�z�j�s...\n",me); break;
        case 7: message_vision("$N�N�����Ǫ����Y�h�}�M������A���O�o�L�\�Ӫ�...\n",me); break;
        default:
            if( random(100) > 1 ) {     // �����@�볽
                item = new( fish_list[random(sizeof(fish_list))] );
                if( !objectp(item) ) {
                    message_vision("$N�o�{�o�઺�����w�g�S�F�A�u�n���_���e�ǳƴ���m�C\n",me);
                    me->delete_temp("is_gaffing");
                    return 1;
                }
                message_vision("$N�b����襤�o�{�F�@�Ӷ¼v�I�I�C�C����F�L�h...\n",me);
                message_vision("$N�b����ʶ¼v�����դU�ΤO�@��I���G�뤤"
                                + ( item->query("base_unit") ? item->query("base_unit") : item->query("unit") ) + 
                               "$n��i�M�l��...\n", me, item);
            } else {                    // �����S��
                item = new( spec_list[random(sizeof(spec_list))] );
                if( !objectp(item) ) {
                    message_vision("$N�o�{�o�઺�����w�g�S�F�A�u�n���_���e�ǳƴ���m�C\n",me);
                    me->delete_temp("is_gaffing");
                    return 1;
                }
                message_vision("$N�b����襤�o�{�F�@�Ӷ¼v�I�I�C�C����F�L�h...\n", me);
                message_vision("$N�b����ʶ¼v�����դU�ΤO�@��I�o�{�O�ө_�Ǫ����~...\n", me);
            }
            if( !item->move(me) ) {
                message_vision("$N�oı�M�l�w�g�˺��F�A�u�n�N$n��^����...\n", me, item);
                destruct(item);
            }
            me->add_temp("is_gaffing", -3-random(4));
            if( me->query_temp("is_fishing") <= 0 )
                me->set_temp("is_fishing", 1);
            break;
    }
    // 5%���v�۰ʰ���
    if( random(100) < 5 ) {
        switch( random(4) ) {
            case 0:
                message_vision("$N�֪��ݤ��L��ӡA�u�n���M������C\n",me);
                break;
            case 1:
                message_vision("$N���p�߽��ۤv�]������...�Q�d��S��k������F�C\n",me);
                break;
            case 2:
                message_vision("�@����q�W������g�L�A�⳽�s�����~�]...�ݨӥu�n���a��F�C\n",me);
                break;
            default:
                mob = new(_DIR_AREA_"benthal/npc/monster.c");
                if( environment(me)->is_area() ) {
                    if( area_move(environment(me), mob, x, y) ) {
                        message_vision(CYN"���M�@���e�M�j���q�F�a��«�X�I�~��$N���W����������C\n"NOR,me);
                        break;
                    }
                    message_vision("���M�@�Ӷ¼v�q$N�����ƹL�A$Nĵı���|�B�i�氱��������C\n",me);
                    break;
                } else {
                    message_vision("���M�@�Ӷ¼v�q$N�����ƹL�A$Nĵı���|�B�i�氱��������C\n",me);
                    break;
                }
        }
        me->delete_temp("is_gaffing");
        return 1;
    }
    me->add_temp("is_gaffing", 1);

    delay = 5 + random(10);
    me->start_busy(delay);

    // �i�J���� function
    call_out("gaffing_2", delay, me);
    return 1;
}
