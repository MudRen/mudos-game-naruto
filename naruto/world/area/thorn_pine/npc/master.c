#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

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
    exact = COMBAT_D->exact(this_object(), enemy, 1)*1.75;
    evade = COMBAT_D->evade(enemy, this_object(), 1) + COMBAT_D->wittiness(enemy, 1);

    this_object()->damage_stat("mp", 15, this_object());
    message_vision("\n$N�N���������x�A�@�ζ��⪺���~�U�ӷU�G�A���M$N��@���u"HIY"����i"NOR"�vŧ�V$n�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n²��a�B���]�O�A���P�N$N�����O�����F�C\n\n", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    if( enemy->query("guild") == "muya" ) raiseDamage = 400;
    else if( enemy->query("guild") == "hunter" ) raiseDamage = 250;
    else raiseDamage = 300;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 150 ) damage = 100 + random(50);

    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("�u�F�I�v�a�@�n�A����b$n���e���F�}�ӡA��$n����@�Ƕˮ`(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}
void create()
{
    set_name("�\���v", ({ "bow master", "master" }));
    set_race("human");
    set_level(35);
    set("gender", "male");
    set("age", 20+random(51));
    set("camp", "bow");
    set("limbs", ({ "�Y��", "����", "����", "�L��", "����", "�զ�", "�ӳ�", "�I��" }));
    set("long", "�\�ڤH���v�A���`�t�d�����B�оǻP���ɡC\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":33, "amount":1, "p1":15, "p2":100 ]),  // �j���
        ([ "type":"wp", "id":34, "amount":1, "p1":5, "p2":100 ]),   // �K�M
        ([ "type":"wp", "id":42, "amount":1, "p1":1, "p2":100 ]),   // ���j
        ([ "type":"wp", "id":30, "amount":1, "p1":1, "p2":200 ]),   // �����ԤM
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