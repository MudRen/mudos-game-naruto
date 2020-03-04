#include <npc.h>
#include <ansi.h>

void do_fight(object enemy)
{
    int damage, raiseDamage, i, exact;
    object* targets;

    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->exact(this_object(), enemy, 1)/2;
    add_temp("apply/exact", exact);

    message_vision("\n$N"HIM"����ֳt���L�A������թ��M�o�X�}�ѻ��n�y"HIY"�����i��"HIM"�z�I\n"NOR, this_object(), enemy);
    for(i=0;i<sizeof(targets);i++) {
        if( i > 4) break;   // �來�ӤH����
        if( !COMBAT_D->isHit(this_object(), targets[i]) ) {
            message_vision("$n�V��s�h�ƤV�~�n���e�����}�����d��I\n", this_object(), targets[i]);
            this_object()->start_busy(1);
        } else {
            raiseDamage = 700;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            if( damage <= 500 ) damage = 350 + random(150);

            targets[i]->damage_stat("hp", damage, this_object());
            message_vision( sprintf("�@�n�_�ե��T����$n�ݤ��L��ӡA�|�P�n����������(%d) %s\n", damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
            targets[i]->start_busy(2);
        }
    }
    add_temp("apply/exact", -exact);
    message_vision("\n", this_object());
}
void do_heal()
{
    if( this_object()->query_stat("hp") > 2000 ) return;
    message_vision("$N"HIM"�N�d�J�ԬI����ä����w�w�j���A���W���ˤf�ֳt�^�_�F�I\n"NOR, this_object());
    this_object()->heal_stat("hp", 9999);
    return;
}
void create()
{
    set_name("�y��", ({ "yu in", "in" }) );
    set_level(40);
    set_class("superior");
    set_race("human");
    set("gender", "female");
    set("age", 25);
    set("title",HIM"�����W��"NOR);
    set("long", "����ۤW�Ԧ�A�A�ݰ_�ӫD�`���n�S���ˤl�C\n");
    set("guard_exit", ({ "east" })); // �u�ۥX�f
    set("chat_chance", 100);
    set("chat_msg", ({
        (: do_heal :),
    }));
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":1+random(2), "p1":60, "p2":100 ]),   // ����
        ([ "type":"eq", "id":89, "amount":1, "p1":1, "p2":150 ]),               // �@�y
        ([ "type":"eq", "id":90, "amount":1, "p1":1, "p2":150 ]),               // �@�B
    }) );
    setup();
    set_stat_current("hp", 5400);
    set_stat_maximum("hp", 5400);
}
int give_check(object ob)
{
    if( ob->id("__WHEYA__") ) return 1;   // ���]����
    else return 0;
}
int do_guard_exit(int x, int y, string exit)
{
    if( this_player()->query_temp("quest/goinhole") != 1) {
        message_vision("$n���X��צ�$N���h���C\n", this_player(), this_object());
        do_chat((: command, "say ���X���]���ҨӡA���M�O�Q�q�L�o�̡C":));
        return 1;
    }
    this_player()->delete_temp("quest/goinhole");
    return 0;
}
int accept_object(object me, object ob)
{
    object item;

    if( is_busy() ) {
        do_chat((: command, "say ���e�@��q�L�A���C" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say ��I�䦺�I" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( this_player()->query_temp("quest/goinhole") == 1) {
                message_vision("$N�ôb���ݵ�$n���D�R"HIG"�A�w�g���L�F�A�ֹL�h�a�C\n"NOR, this_object(), this_player());
                return 0;
            }
            message_vision("$N���L$n��"HIR"���]����"NOR"���D�R"HIG"�n�F�A�A�L�h�a�C\n"NOR, this_object(), this_player());
            this_player()->add_temp("quest/goinhole", 1);
            do_chat(((: destruct, ob :)));
            break;
        default:
            do_chat((: command, "say �u�����]���ү�q�L�o�̡C" :));
            return 0;
            break;
    }
    return 1;
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = random(2) + 1;

    if( !enemy ) {
        ::die();
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            ::die();
            return;
        } else
        if( environment(enemy) != environment(this_object()) ) {
            ::die();
            return;
        }
    }
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n\n"HIM+this_object()->query("name")+"���D�G�j�D�Y�j�H�A�Ю��ڨS���������ɪ������I\n"NOR;
    msg += HIR"\n"HIR"�i���|�s�D�j"+this_object()->query("name")+"("+this_object()->query("id")+")����"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")����F�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}