#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

string *name1 = ({ "���R", "�n�J", "�ߤl", "����", "��", "��", "����",
                   "����", "�T", "����", "�Ŵd" });

string *name2 = ({ "�q", "�g", "�{", "�m", "¶", "��", "��", "�b", "��",
                   "�Ʒn", "�W��", "�y�M", "���R", "�@��", "�L��",
                   "�M�X�l", "�n�ۦb", "�ŵL�a" });

void do_fight()
{
    int damage, raiseDamage, exact, evade;
    object enemy;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->intimidate(this_object(), 1);
    evade = COMBAT_D->wittiness(enemy, 1);

    this_object()->damage_stat("mp", 10, this_object());
    message_vision("\n$N���ֳt���X���$n��ӡA����j�q�d�J�ԡy"HIC"�T���"NOR"�z�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n�ߨ�N�l�O�����b���ӡA�B�Υ��l�N$N�������Ͼ_�F�^�h�I\n\n", this_object(), enemy);
        this_object()->start_busy(2);
    } else {
        raiseDamage = 400;

        add_temp("apply/attack", raiseDamage); 
        damage = COMBAT_D->isDamage(this_object(), enemy, 0);
        add_temp("apply/attack", -raiseDamage);

        if( damage < 150 ) damage = 100 + random(50);

        enemy->receive_damage(damage, this_object());
        message_vision( sprintf("�j�q�d�J����J$n���ӡA�_��$n�ӳ���ޯ}���A�ֽ������x��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        enemy->start_busy(2);
    }
    return;
}
void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "ninja" }));
    set_race("human");
    set_level(28+random(3));
    set("gender", "male");
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
        (: do_fight :),
        (: command, "say ���F�j�D�Y�j�H�ӾľԡI" :),
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