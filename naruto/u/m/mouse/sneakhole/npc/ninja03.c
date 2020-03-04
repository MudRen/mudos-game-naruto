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
    int i;
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
    message_vision("$N��⵲�L�\��ˤf�ϥX�u"HIM"�������N"NOR"�v�I\n"NOR, this_object());
    if( i > 5 ) {
        message_vision("        $n�d�J�ԥκɤF�C(0)", this_object());
    }
    this_object()->heal_stat("hp", 300);
    i = i+1;
    message_vision("        $N�ˤf����v���A�C�C�^�_�F�C("HIG"300"NOR")\n", this_object());
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
    set("attitude", "aggressive");
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
        ([ "type":"wp", "id":5, "amount":1, "p1":15, "p2":100 ]),               // �W�L
        ([ "type":"obj", "id":29, "amount":50+random(100), "p1":80, "p2":100 ]),// �Ȥl
        ([ "type":"food", "id":51, "amount":1, "p1":7, "p2":100 ]),             // �N��
        ([ "type":"food", "id":10, "amount":1, "p1":6, "p2":100 ]),             // �b��
        ([ "type":"food", "id":11, "amount":1, "p1":2, "p2":100 ]),             // ���o
        ([ "type":"eq", "id":89, "amount":1, "p1":1, "p2":300 ]),               // �@�y
        ([ "type":"eq", "id":90, "amount":1, "p1":1, "p2":400 ]),               // �@�B
    }) );
    setup();
}
