#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

void create()
{
    set_name("�\�H", ({ "bow man", "man" }));
    set_race("human");
    set_level(30);
    set("gender", "male");
    set("age", 10+random(81));
    set("limbs", ({ "�Y��", "����", "����", "�L��", "����", "�զ�", "�ӳ�", "�I��" }));
    set("long", "�\�����\�ڤH�A���r�֪��ͬ��ۡC\n");
    set("camp", "bow");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: random_move :),
        (: command, "say �w��Ө�\�ڪ����l" :),
        CYN"�\�H��������ۺq���C\n"NOR,
    }));
    	
    set("set_drop", ({
      ([ "type":"wp", "id":45, "amount":1, "p1":20, "p2":100 ]),  // ��C
      ([ "type":"wp", "id":35, "amount":1, "p1":10, "p2":100 ]),  // �K��
      ([ "type":"wp", "id":44, "amount":1, "p1":5, "p2":100 ]),   // �j�۩�
      ([ "type":"wp", "id":43, "amount":1, "p1":1, "p2":100 ]),   // ����
    }));

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
