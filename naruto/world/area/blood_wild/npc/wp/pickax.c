#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�Q�r��", ({ "pickax" }));
    set_weight(15000);
    setup_weapon(15, 25, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 2000);
        set("long", "�K�s���u��A�i�H�Ψӫ���(digging)�g����P�n�������A�q�`�Q�Φb\n"
                    "���q�B���s�������ʭ��u�@�W�C���Q���i�H����(giveup)�C\n" );
    }
    setup();
}
void init()
{
    if( environment(this_object()) && userp(environment(this_object())) ) {
        add_action("do_digging", "digging");
        add_action("do_giveup", "giveup");
    }
}

int do_giveup(string arg)
{
    if( !this_player()->query_temp("is_digging") ) return notify_fail("�A�S���b���q�C\n");
    tell_object(this_player(), "�A�M�w������q�C\n");
    this_player()->delete_temp("is_digging");
    this_player()->start_busy(1);
    return 1;
}

int do_digging(string arg)
{
    int delay;
    object env, me = this_player();

    if( !objectp(env = environment(me)) ) return 0;

    if( !this_object()->query("equipped") ) return notify_fail("�S���˳ƤQ�r������q�I\n");
    if( me->query_temp("weapon/twohanded") != this_object() ) return notify_fail("�S���˳ƤQ�r������q�I\n");
    if( me->query_temp("is_digging") ) return notify_fail("�A�w�g�b���q�F�C\n");
    if( me->is_fighting() || me->is_busy() ) return notify_fail("�A�Ӧ��F�A�L�k���߫��q�C\n");

    if( env->is_area() ) {
        int x, y;
        x = me->query("area_info/x_axis");
        y = me->query("area_info/y_axis");
        if( !env->query_data(x, y, "dig") ) return notify_fail("�o�Ӧ�m�O������q���I\n");
    } else {
        if( !env->query("dig") ) return notify_fail("�o�Ӧ�m�O������q���I\n");
    }
    switch( random(4) ) {
        case 0:
            message_vision(CYN"$N�N�S�l���F�_�ӡA���R�ۨI����"+query("name")+"�m�m�����V���۩���...\n"NOR,me);
            break;
        case 1:
            message_vision(CYN"$N�b����U�R�F�@�f�f���i���X�U�A�ǳƺɥ��O��������...\n"NOR,me);
            break;
        case 2:
            message_vision(CYN"$N�V�V�����A�ש��w�F�@�ӳ̯ܮz���I�|�_"+query("name")+"�}�l����...\n"NOR,me);
            break;
        default:
            message_vision(CYN"$N�N"+query("name")+"���b�ӤW�A���M�@�ѧ@��©����W�ΤO�A�F�U�h...\n"NOR,me);
            break;
    }
    me->set_temp("is_digging", 1);

    delay = 5 + random(16);

    me->start_busy(delay);

    // �i�J���q function
    call_out("digging_2", delay, me);
    return 1;
}

int digging_2(object me)
{
    int x=0, y=0, i, delay;
    object mob, env;

    i = random(101);

    if( !me ) return 1;
    if( !me->query_temp("is_digging") ) return do_giveup("");
    if( !this_object()->query("equipped") ) return do_giveup("");
    if( me->query_temp("weapon/twohanded") != this_object() ) return do_giveup("");
    if( !objectp(env = environment(me)) ) return do_giveup("");
    if( me->is_fighting() ) return do_giveup("");
    if( env->is_area() ) {
        x = me->query("area_info/x_axis");
        y = me->query("area_info/y_axis");
        if( !env->query_data(x, y, "dig") ) return do_giveup("");
    } else {
        if( !env->query("dig") ) return do_giveup("");
    }
    if( i > 5 && i < 16 ) {
        message_vision(CYN"$N���p�߱N"+this_object()->query("name")+"���_�F�I\n"NOR, me);
        mob = new("/world/area/blood_wild/npc/item/unknown.c");
        mob->set_name("�_����"+this_object()->query("name"), ({ "pickax" }));
        this_object()->unequip();
        move_side(mob, me);
        me->start_busy(5);
        me->delete_temp("is_digging");
        destruct(this_object());
        return 1;
    } else if( i > 20 && i < 41 ) {
        message_vision("$N����F���q�C\n"NOR, me);
        mob = new("/world/area/old_forest/item/coal.c");
        delay = 5 + random(6);
        if( !mob->move(me) ) move_side(mob, me);
    } else if( i > 70 && i < 81 ) {
        message_vision("$N����F���q�C\n"NOR, me);
        mob = new("/world/area/old_forest/item/copper.c");
        delay = 5 + random(6);
        if( !mob->move(me) ) move_side(mob, me);
    } else if( i > 95 && i < 101 ) {
        message_vision("$N����F�K�q�C\n"NOR, me);
        mob = new("/world/area/old_forest/item/iron.c");
        delay = 5 + random(6);
        if( !mob->move(me) ) move_side(mob, me);
    } else if( i == 3 || i == 18 || i == 40 || i == 55 || i == 83 ) {
        message_vision(CYN"���G�����o�X��q�}�l����$N�I��ӬO����F�I�Τ����]�H�I\n"NOR, me);
        mob = new("/world/area/blood_wild/npc/monster.c");
        if( !area_move(environment(me), mob, x, y) ) {
            destruct(mob);
        } else {
            mob->kill_ob(me);
            if( function_exists("accept_kill", me) && !me->is_killing(mob) && me->accept_kill(mob) ) return 1;
            if( !me->is_killing(mob) ) me->kill_ob(mob);
        }
        me->delete_temp("is_digging");
        return 1;
    } else {
        delay = 5 + random(16);
    }
    call_out("digging_2", delay, me);
    me->start_busy(delay);
    return 1;
}
