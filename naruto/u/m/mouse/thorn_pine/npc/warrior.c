#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

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
    message_vision("$N�۵۰��B�A�@�ۡy"HIR"�Y��"NOR"�z���V$n�ݤf�I\n"NOR, this_object(), enemy);
    damage = 20+random(56);
    if( random(enemy->query_ability("intimidate")) > 100) {
        message_vision("        $n�H�X�g��ƸѤF��աC(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n�u�I�I�v�a�@�n�h��X�B�A�L���٬y�X�A��C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void create()
{
    set_name("�\�Z��", ({ "bow warrior", "warrior" }));
    set_race("human");
    set_level(35);
    set("gender", "male");
    set("age", 20+random(51));
    set("limbs", ({ "�Y��", "����", "����", "�L��", "����", "�զ�", "�ӳ�", "�I��" }));
    set("long", "�\�ڤH�Z�̡A���`�t�d���y�B�԰��P�V�m�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":33, "amount":1, "p1":15, "p2":100 ]),  // �j���
        ([ "type":"wp", "id":34, "amount":1, "p1":5, "p2":100 ]),   // �K�M
        ([ "type":"wp", "id":42, "amount":1, "p1":1, "p2":100 ]),   // ���j
        ([ "type":"wp", "id":30, "amount":1, "p1":1, "p2":200 ]),   // �����ԤM
    }) );
    setup();
}
int accept_fight(object ob)
{
    if( this_player()->query_temp("quest/villpk") < 1) {
        do_chat(({
           (: command, "sorry" :),
           (: command, "say �ڪ����O�A���ɤ@�ߤ��ǥ��[" :),
        }));
        return 0;
    }
    return ::accept_fight(ob);
}
