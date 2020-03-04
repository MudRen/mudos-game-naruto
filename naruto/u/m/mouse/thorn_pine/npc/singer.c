#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

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
    if(enemy->is_busy()) {
        message_vision(CYN"$N�۵ۥO�H��ť���q�n�C\n"NOR, this_object(), enemy);
        return;
    }
    message_vision("$N�ۥX�������q�n���ϰg�b$n�I\n"NOR, this_object(), enemy);
    if( random(enemy->query_ability("intimidate")) > 100) {
        message_vision("        $n�S���Q�o�}�n���Ұg�b�C\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    message_vision("        $n�Q�n���Ҵb�I��������h�F�C\n", this_object(), enemy);
    enemy->start_busy(2);
    return;
}
void create()
{
    set_name("�\�q��", ({ "bow singer", "singer" }));
    set_race("human");
    set_level(35);
    set("gender", "female");
    set("age", 20+random(51));
    set("limbs", ({ "�Y��", "����", "����", "�L��", "����", "�զ�", "�ӳ�", "�I��" }));
    set("long", "�\�ڤH�q��A���`�t�d�ۺq�B���R�P�w���H�ߡC\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        CYN"�\�q��������q�n���|�P�\�H���s�n�C\n"NOR,
        CYN"�\�q�Ⱚ�n���۵ۺq���C\n"NOR,
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":33, "amount":1, "p1":15, "p2":100 ]),  // �j���
        ([ "type":"wp", "id":34, "amount":1, "p1":5, "p2":100 ]),   // �K�M
        ([ "type":"wp", "id":43, "amount":1, "p1":1, "p2":100 ]),   // ���j
        ([ "type":"wp", "id":36, "amount":1, "p1":1, "p2":150 ]),   // �课�C
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
