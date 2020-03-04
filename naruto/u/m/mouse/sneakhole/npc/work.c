#include <ansi.h>
#include <npc.h>

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
        message_vision("$N"CYN"�o�X�u�_�_�_�v�����n�C\n"NOR, this_object(), enemy);
        return;
    }
    message_vision("$N"HIW"��M�Q�X�\�h�յ����$n�I\n"NOR, this_object(), enemy);
    if( random(enemy->query_ability("intimidate")) > 80) {
        message_vision("        $n�⦣�}�ê��N�յ����}�F�C\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    message_vision("        $n�Q�U��U��I�L�k��ʤF�C\n", this_object(), enemy);
    enemy->start_busy(2);
    return;
}
void create()
{
    set_name(HIK"�u�{�j��"NOR, ({ "work spider", "spider" }) );
    set_race("beast");
    set("title","���v�j��");
    set_level(27);
    set("long", "�@���ݰ_���Y���S�O�Τj�����ܻj��C\n");
    set("limbs", ({ "�j�Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),       // �j��L
        ([ "type":"obj", "id":81, "amount":1, "p1":25, "p2":100 ]),       // �j��Х�
        ([ "type":"obj", "id":80, "amount":1, "p1":50, "p2":100 ]),       // �H�G
        ([ "type":"food", "id":19, "amount":1, "p1":5, "p2":100 ]),       // �d�J�ԤY
        ([ "type":"eq", "id":91, "amount":1, "p1":1, "p2":900 ]),         // �}�˿�
        ([ "type":"food", "id":17, "amount":1, "p1":5, "p2":100 ]),       // ��O�Y
    }) );
    setup();
    set_skill("combat", 110);
    set_skill("dodge", 110);
    set_skill("parry", 110);
    set_skill("savage hit", 110);
    set_skill("heavy hit", 110);
    set_skill("continual hit", 110);
}
