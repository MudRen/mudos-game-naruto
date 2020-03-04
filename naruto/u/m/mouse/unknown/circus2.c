#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void create()
{
    set_name("�p��", ({ "circus" }) );
    set_race("human");
    set_level(12);
    set("long", "�����έ��A���F�Ϊ����Ī��ӽ�R�C\n");
    set("age", 15+random(40));
    set("chat_chance", 5);
    set("chat_msg", ({
       CYN"�p����b�ֲy�W���ۡC\n"NOR,
       CYN"�p�����ۤ��⤣���ᱵ�ۡC\n"NOR,
       (: command, "say �w����w���" :),
    }) );
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
         (: command, "say �o�̡I":),
         (: command, "say �����L�I":),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":31+random(40), "p1":60, "p2":100 ]),  // �Ȥl
    //  ([ "type":"wp", "id":??, "amount":1, "p1":10, "p2":100 ]),    // �ֲy
    //  ([ "type":"wp", "id":??, "amount":1, "p1":5, "p2":100 ]),     // ���@
    }) );
    setup();
}
void init()
{
    if( this_player()->id("_HELP_BEAR_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N�@����$n�K�j�n�s�ۡG�u�����e�I�����e�I�v\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
