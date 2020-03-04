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
    exact = COMBAT_D->wittiness(this_object(), 1);
    evade = COMBAT_D->wittiness(enemy, 1);

    this_object()->damage_stat("mp", 10, this_object());
    message_vision("\n$N"HIG"�S�X���y�U�p�M�W���e�}�A���M�@�ӭ������V$n�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n�@�}��$N�{�l��F�U�h�A�h��$N�˦b�a�W�_�_�s�C\n\n", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    raiseDamage = 150;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 20 ) damage = 10 + random(10);

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("$n�{�פ��γQ�Q�}���X�F�X�D�f�l�A�ˤf���M�Ӥp�o���w���(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}
void create()
{
    set_name(HIK"�Q�b�j��"NOR, ({ "blade spider", "spider" }) );
    set_race("beast");
    set("title","���v�j��");
    set_level(28);
    set("long", "�K���}���p�M�b�@��y�Q���������ܻj��C\n");
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
        ([ "type":"obj", "id":81, "amount":1, "p1":1, "p2":125 ]),        // �j��Х�
        ([ "type":"obj", "id":80, "amount":1, "p1":3, "p2":100 ]),        // �H�G
        ([ "type":"food", "id":19, "amount":1, "p1":5, "p2":100 ]),       // �d�J�ԤY
        ([ "type":"eq", "id":91, "amount":1, "p1":1, "p2":600 ]),         // �}�˿�
        ([ "type":"food", "id":17, "amount":1, "p1":5, "p2":100 ]),       // ��O�Y
    }) );
    setup();
    add_temp("apply/attack", 50);
    set_skill("combat", 130);
    set_skill("dodge", 130);
    set_skill("parry", 130);
    set_skill("savage hit", 130);
    set_skill("heavy hit", 130);
    set_skill("continual hit", 130);
}
