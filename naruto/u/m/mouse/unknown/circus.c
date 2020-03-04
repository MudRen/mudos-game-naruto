#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void create()
{
    set_name("�����Ϊ�", ({ "circus man", "man" }) );
    set_race("human");
    set_level(16);
    set("long", "�a�ߪ��Ϊ��A�b�H���q��F���ְʪ����ȫ��[���ȿ��C\n");
    set("age", 50);
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
       CYN"�����Ϊ����a�L���a���R�w����w����{���C\n"NOR,
       (: command, "say �ڭ̦��ܦh�ʪ��i���[����" :),
       (: command, "say �̪��٧��@���H���q�~�������ɪ�����I" :),
    }) );
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
         (: command, "say ���n�񨫧ڪ��ʪ����I":),
         (: command, "say �����L�I":),
         (: command, "say �y�H���ͳo�̪��I" :),
         (: command, "kill bear" :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":61+random(40), "p1":60, "p2":100 ]),  // �Ȥl
    //  ([ "type":"wp", "id":??, "amount":1, "p1":20, "p2":100 ]),    // �ֲy
    //  ([ "type":"wp", "id":??, "amount":1, "p1":10, "p2":100 ]),    // ���@
    }) );
    setup();
}
void init()
{
    if( this_player()->id("_HELP_BEAR_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N�@����$n�K�j�n�s�ۡG�u�e�b�o�̡A���ଡ��]�n�����I�v\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
