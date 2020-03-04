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
    if( this_object()->query_stat("hp") > 501 ) {
        return;
    }
    message_vision("\n$N��⵲�L�\��ˤf�u"HIM"�������N"NOR"�v�����d�J�ԥѤ�ӤռQ�X�A�o�X���G�����֡I\n"NOR, this_object());
    if( query_temp("music_heal") > 3 ) {
        message_vision("$N�Ϻɥ��O�o�w�g�L�O�A���v�����˪��ˤf�C\n\n", this_object());
        return;
    }
    this_object()->heal_stat("hp", 2000);

    if( !query_temp("music_heal") ) set_temp("music_heal", 1);
    else add_temp("music_heal", 1);

    message_vision("$N���ˤf�b���G�����֤��ֳt�^�_�A�~�M�s�@�I�ͳ��ݤ����F�I\n\n", this_object());
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
    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: command, "say �J��ڧA�i�n�p�ߤF�I" :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":5, "amount":1, "p1":12, "p2":100 ]),               // �W�L
        ([ "type":"obj", "id":29, "amount":50+random(100), "p1":80, "p2":100 ]),// �Ȥl
        ([ "type":"food", "id":51, "amount":1, "p1":7, "p2":100 ]),             // �N��
        ([ "type":"food", "id":10, "amount":1, "p1":6, "p2":100 ]),             // �b��
        ([ "type":"food", "id":11, "amount":1, "p1":2, "p2":100 ]),             // ���o
        ([ "type":"eq", "id":89, "amount":1, "p1":1, "p2":300 ]),               // �@�y
        ([ "type":"eq", "id":90, "amount":1, "p1":1, "p2":400 ]),               // �@�B
    }) );
    setup();
    // �W�j
    add_temp("apply/hp", 500);
    add_temp("apply/armor", 50);
    add_temp("apply/exact", 20);
    add_temp("apply/intimidate", 20);
    do_heal();
}