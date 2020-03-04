#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

string *name1 = ({ "���R", "�n�J", "�ߤl", "����", "��", "��", "����",
                   "����", "�T", "����", "�Ŵd" });

string *name2 = ({ "�q", "�g", "�{", "�m", "¶", "��", "��", "�b", "��",
                   "�Ʒn", "�W��", "�y�M", "���R", "�@��", "�L��",
                   "�M�X�l", "�n�ۦb", "�ŵL�a" });

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight()
{
    int damage;
    object enemy;
    string msg;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_temp("quest/throw_dart") == 2) {
        message_vision("$N"HIR"���ۭ�~�g�{"NOR"$n"HIR"���a�n�A����S�Y�X��ڨ�w�I\n"NOR, this_object(), enemy);
        damage = 100+random(71);
        if( random(enemy->query_ability("evade")) > 150) {
            message_vision("        $n�ֳt���q����u�F�}�ӡC(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->delete_temp("quest/throw_dart");
            this_object()->start_busy(1);
            return;
        }
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�u�P�v���@�n�Q��w�g���A�h���z�z�j�s�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        return;
    } else
    if( this_object()->query_temp("quest/throw_dart") == 1) {
        message_vision("$N"HIG"ť�ۨ뤤"NOR"$n"HIG"���ê��n���A�ֳt�Y�X�a�����M�I\n"NOR, this_object(), enemy);
        damage = 30+random(61);
        if( random(enemy->query_ability("evade")) > 170) {
            message_vision("        $n�ֳt���q����u�F�}�ӡC(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->delete_temp("quest/throw_dart");
            this_object()->start_busy(1);
            return;
        }
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�u�P�v���@�n�Q���M�g���A��ʶw�F�@�U�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        this_object()->add_temp("quest/throw_dart", 1);
        return;
    }
    message_vision("$N"HIY"�µ�"NOR"$n"HIY"�g�X�@�⭸�w�A�w���ۭ��ǥX����n�I\n"NOR, this_object(), enemy);
    damage = 10+random(51);
    if( random(enemy->query_ability("evade")) > 230) {
        message_vision("        $n�ֳt���q����u�F�}�ӡC(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->delete_temp("quest/throw_dart");
        this_object()->start_busy(1);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n�u�P�v���@�n�Q���w�g���A�}�����F�@�I�ˮ`�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    this_object()->add_temp("quest/throw_dart", 1);
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
    set("attitude", "aggressive");
    set("long", "���������Ԫ̡A���G���b�o�̶i�椰��u�{�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: command, "say �p�ݧڷ|���A�ᮬ���I" :),
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":5, "amount":1, "p1":15, "p2":100 ]),               // �W�L
        ([ "type":"obj", "id":29, "amount":50+random(100), "p1":80, "p2":100 ]),// �Ȥl
        ([ "type":"food", "id":51, "amount":1, "p1":7, "p2":100 ]),             // �N��
        ([ "type":"food", "id":10, "amount":1, "p1":6, "p2":100 ]),             // �b��
        ([ "type":"food", "id":11, "amount":1, "p1":2, "p2":100 ]),             // ���o
        ([ "type":"eq", "id":89, "amount":1, "p1":1, "p2":400 ]),               // �@�y
        ([ "type":"eq", "id":90, "amount":1, "p1":1, "p2":300 ]),               // �@�B
    }) );
    setup();
}
