#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

int i = 0;

string *name1 = ({ "���R", "�n�J", "�ߤl", "����", "��", "��", "����",
                   "����", "�T", "����", "�Ŵd" });

string *name2 = ({ "�q", "�g", "�{", "�m", "¶", "��", "��", "�b", "��",
                   "�Ʒn", "�W��", "�y�M", "���R", "�@��", "�L��",
                   "�M�X�l", "�n�ۦb", "�ŵL�a" });

void do_fight()
{
    int damage, raiseDamage, exact, evade;
    object enemy;
    string msg;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( i ) {
        case 0: msg = "\n$N"HIY"�µ�"NOR"$n"HIY"�g�X�@�⭸�w�A�w��L�}�ު��ӭ��ǥX����n�I\n";
                raiseDamage = 150;
                exact = COMBAT_D->exact(this_object(), enemy, 1)*1.5;
                evade = COMBAT_D->evade(enemy, this_object(), 1);
                break;
        case 1: msg = "\n$N"HIY"ť�ۨ뤤"NOR"$n"HIY"�����öǦ^�L�z�T�n�A�ֳt���n���B�Y�X�a�����M�I\n";
                raiseDamage = 250;
                exact = COMBAT_D->exact(this_object(), enemy, 1)*1.25;
                evade = COMBAT_D->evade(enemy, this_object(), 1);
                break;
        case 2: msg = "\n$n"HIM"���ʮɨϹa�L�t���o�X�n�T�A"NOR"$N"HIM"ť�D��@���Ҽ{�a�­����Y�X�Ƨ���w�t���I\n";
                raiseDamage = 500;
                exact = COMBAT_D->exact(this_object(), enemy, 1);
                evade = COMBAT_D->evade(enemy, this_object(), 1);
                break;
        default: msg = "\n$N"HIM"�@�ɶ��䤣�쭸�M�A�~�M��_�v���g�V$n�I\n";
                 raiseDamage = 20;
                 exact = 0;
                 evade = 0;
                 break;
    }
    message_vision(msg+""NOR, this_object(), enemy);
    this_object()->damage_stat("mp", 5, this_object());
    if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        add_temp("apply/attack", raiseDamage); 
        damage = COMBAT_D->isDamage(this_object(), enemy, 0);
        add_temp("apply/attack", -raiseDamage);

        if( damage < 50 ) damage = 35 + random(15);

        // �ˮ`�ާl��
        damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
        enemy->receive_damage(damage, this_object());
        message_vision( sprintf("$n�Q$N���t���뤤�A�t���ߨ�o�X���n�T�A��$N�A���o�{$n����m(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        i++;
        if( i >= 2 ) i = 2;
    } else {
        message_vision("���O$n�o���ݷǤF�����A���֪��q�@�ǰ{�F�}�ӡC\n\n", this_object(), enemy);
        i = 0;
    }
    return;
}
void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "ninja" }));
    set_race("human");
    set_level(28+random(3));
    set("gender", "female");
    set("nickname",HIM"�����Ԫ�"NOR);
    set("age", 10+random(51));
    set("camp", "music");
    set("long", "���������Ԫ̡A���G���b�o�̶i�椰��u�{�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: command, "say �p�ݧڷ|���A�ᮬ���I" :),
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":5, "amount":1, "p1":12, "p2":100 ]),               // �W�L
        ([ "type":"obj", "id":29, "amount":50+random(100), "p1":80, "p2":100 ]),// �Ȥl
        ([ "type":"food", "id":51, "amount":1, "p1":7, "p2":100 ]),             // �N��
        ([ "type":"food", "id":10, "amount":1, "p1":6, "p2":100 ]),             // �b��
        ([ "type":"food", "id":11, "amount":1, "p1":2, "p2":100 ]),             // ���o
        ([ "type":"eq", "id":89, "amount":1, "p1":1, "p2":400 ]),               // �@�y
        ([ "type":"eq", "id":90, "amount":1, "p1":1, "p2":300 ]),               // �@�B
    }) );
    setup();
    // �W�j
    add_temp("apply/hp", 500);
    add_temp("apply/armor", 50);
    add_temp("apply/exact", 20);
    add_temp("apply/intimidate", 20);
    do_heal();
}