#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void do_fight()
{
    int damage, raiseDamage, exact, evade;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->intimidate(this_object(), 1)*2;
    evade = COMBAT_D->evade(enemy, this_object(), 1);

    this_object()->damage_stat("mp", 5, this_object());
    message_vision("\n$N"HIR"�����N�N���ഫ��m�A���M�q�󤤸��X��ŧ"NOR"$n"HIK"�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n���}�F$N����ŧ�A�׶}�F�����C\n\n", this_object(), enemy);
        return;
    }
    raiseDamage = 250;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 100 ) damage = 50 + random(50);

    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("$n�Q�M��F�@�U�o�䤣��$N�q��B����(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}

void create()
{
    set_name("���D", ({ "thief snake", "snake" }) );
    set_race("human");
    set("gender", "male");
    set_level(33+random(3));
    set("age", 20+random(21));
    set("limbs", ({ "�D�Y", "�D��", "����", "�ݤf", "�}��", "�ӻH", "�y��" }) );
    set("title",HIG"�D��ŧ�h"NOR);
    set("long", "����u�b�A����¦�A�M���C���b���O���C\n");
    set("camp", "snaker");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: command, "peer" :),
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":100 ]),     // �D������
        ([ "type":"wp", "id":49, "amount":1, "p1":1, "p2":300 ]),     // �s�M
        ([ "type":"wp", "id":30, "amount":1, "p1":1, "p2":200 ]),     // �����ԤM
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // �D��
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // �D�r
    }) );
    setup();
}