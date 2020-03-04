#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

void create()
{
    set_name("�k�\�H", ({ "bow woman", "woman" }));
    set_race("human");
    set_level(30);
    set("gender", "female");
    set("age", 10+random(81));
    set("limbs", ({ "�Y��", "����", "����", "�L��", "����", "�զ�", "�ӳ�", "�I��" }));
    set("long", "�\�����\�ڤH�A���r�֪��ͬ��ۡC\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: random_move :),
        (: command, "say �۱q�y�H�ҳ��b�o����A�~�ӤH�U�ӷU�h�F" :),
        CYN"�k�\�H�����Y�W�������C\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"wp", "id":45, "amount":1, "p1":20, "p2":100 ]),  // ��C
        ([ "type":"wp", "id":41, "amount":1, "p1":10, "p2":100 ]),  // ���M
        ([ "type":"wp", "id":31, "amount":1, "p1":5, "p2":100 ]),   // ���Y
        ([ "type":"wp", "id":42, "amount":1, "p1":1, "p2":100 ]),   // ���j
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
