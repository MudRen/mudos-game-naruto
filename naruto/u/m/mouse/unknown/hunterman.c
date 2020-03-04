#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void create()
{
    set_name("�y�H����", ({ "hunter man", "man" }) );
    set_race("human");
    set_level(20);
    set("long", "�b�˪L����F�@�����������a�H�A�ۺ�¾�~�y�H�C\n");
    set("age", 50);
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
       (: command, "say �ڥi�O¾�~�y�H��C" :),
       (: command, "say �������⤰��I���Ŧb�h�찦�j���ӵ��j�a�[��I" :),
    }) );
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
         (: command, "say �o�å�Q�񨫪������I":),
         (: command, "say �ڥi�O¾�~�y�H�I":),
         (: command, "say �A�ٴ����ڶܡH�I" :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":61+random(40), "p1":60, "p2":100 ]),  // �Ȥl
        ([ "type":"wp", "id":11, "amount":1, "p1":5, "p2":100 ]),     // �u�C
    //  ([ "type":"obj", "id":??, "amount":1, "p1":20, "p2":100 ]),   // ���~��
    //  ([ "type":"wp", "id":??, "amount":1, "p1":10, "p2":100 ]),    // �Ӻֺj
    }) );
    setup();
}
void init()
{
    if( this_player()->id("_HELP_BEAR_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N�@����$n�K�j�n�s�ۡG�u�~�M�Q��X�ӤF�I�O�Q�]�I�v\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
