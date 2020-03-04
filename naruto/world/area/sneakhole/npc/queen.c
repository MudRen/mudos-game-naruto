#include <ansi.h>
#include <npc.h>

void do_fight()
{
    object enemy;
    int damage, raiseDamage, exact, evade;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->exact(this_object(), enemy, 1)*2;
    evade = COMBAT_D->intimidate(enemy, 1) + COMBAT_D->wittiness(enemy, 1);

    this_object()->damage_stat("mp", 25, this_object());
    message_vision("\n$N"HIR"�i�j�L�ڤ@�R�A�~�M�Q�X�@�ά���G��I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n�V����@���A��a�����@�n�_�_�·ϡA�~�M�N�X�F�@�Ӭ}�C\n\n", this_object(), enemy);
        this_object()->start_busy(1);
    } else {
        raiseDamage = 400;

        add_temp("apply/attack", raiseDamage); 
        damage = COMBAT_D->isDamage(this_object(), enemy, 0);
        add_temp("apply/attack", -raiseDamage);

        if( damage < 200 ) damage = 150 + random(50);

        enemy->receive_damage(damage, this_object());
        message_vision( sprintf("$n�Q�G��Q��A�ֽ��~�M�C�C����A�n������T�׿N��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        this_object()->start_busy(1);
        enemy->start_busy(2);
    }
    return;
}
void create()
{
    set_name(RED"�j��ӦZ"NOR, ({ "queen spider", "spider" }) );
    set_race("beast");
    set("title","���v�j��");
    set_level(30);
    set("long", "���l�����j�ﳣ�٭n���j�A�������Q�X�����n���n�N�A�ͧ]�C\n");
    set("limbs", ({ "�j�Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),       // �j��L
        ([ "type":"obj", "id":81, "amount":1, "p1":80, "p2":100 ]),       // �j��Х�
        ([ "type":"obj", "id":80, "amount":1+random(4), "p1":70, "p2":100 ]), // �H�G
        ([ "type":"food", "id":19, "amount":1, "p1":5, "p2":100 ]),       // �d�J�ԤY
        ([ "type":"eq", "id":91, "amount":1, "p1":1, "p2":300 ]),         // �}�˿�
        ([ "type":"eq", "id":92, "amount":1, "p1":1, "p2":100 ]),         // �j����
        ([ "type":"food", "id":17, "amount":1, "p1":5, "p2":100 ]),       // ��O�Y
    }) );
    setup();
    add_temp("apply/attack", 50);
    set_skill("combat", 140);
    set_skill("dodge", 140);
    set_skill("parry", 140);
    set_skill("savage hit", 140);
    set_skill("heavy hit", 140);
    set_skill("continual hit", 140);
}