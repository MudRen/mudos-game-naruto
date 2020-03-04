#include <ansi.h>
#include <npc.h>

void do_fight()
{
    object enemy;
    int exact, evade;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if(enemy->is_busy()) {
        message_vision(CYN"$N�o�X�u�_�_�_�v�����n�C\n"NOR, this_object(), enemy);
        return;
    }
    exact = COMBAT_D->intimidate(this_object(), 1);
    evade = COMBAT_D->intimidate(enemy, 1);

    message_vision("\n$N"HIW"�K�}�@�ޡA�ֳt����$n���e�A�Q�X�\�h�յ����$n�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n�oı�Ʊ�����A�⦣�}�ê��N�յ����}���������a�C\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    } else {
        message_vision("$n���H�������~������A���G�Q�յ��U��U��I�L�k��ʤF�C\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        enemy->start_busy(4);
    }
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
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),       // �j��L
        ([ "type":"obj", "id":81, "amount":1, "p1":1, "p2":150 ]),        // �j��Х�
        ([ "type":"obj", "id":80, "amount":1, "p1":2, "p2":100 ]),        // �H�G
        ([ "type":"food", "id":19, "amount":1, "p1":5, "p2":100 ]),       // �d�J�ԤY
        ([ "type":"eq", "id":91, "amount":1, "p1":1, "p2":600 ]),         // �}�˿�
        ([ "type":"food", "id":17, "amount":1, "p1":5, "p2":100 ]),       // ��O�Y
    }) );
    setup();
    add_temp("apply/attack", 30);
    set_skill("combat", 130);
    set_skill("dodge", 130);
    set_skill("parry", 130);
    set_skill("savage hit", 130);
    set_skill("heavy hit", 130);
    set_skill("continual hit", 130);
}
