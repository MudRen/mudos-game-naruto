#include <ansi.h>
#include <npc.h>

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
    exact = COMBAT_D->wittiness(this_object(), 1)*1.4;
    evade = COMBAT_D->intimidate(enemy, 1);

    this_object()->damage_stat("mp", 10, this_object());
    message_vision("\n$N"HIC"���M�����ʤj�o�A�o�X�w�I���n�A���ڤ@�Ϥ����q��B�ۨӤF�u�u�j���I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$N�B�_�ۨ������l�A�N�Ҧ����V�ۤv���j�������Ĵ��F�C\n\n", enemy, this_object());
        this_object()->start_busy(2);
    } else {
        raiseDamage = this_object()->query_level()*10;

        add_temp("apply/attack", raiseDamage); 
        damage = COMBAT_D->isDamage(this_object(), enemy, 0);
        add_temp("apply/attack", -raiseDamage);

        if( damage < 200 ) damage = 50 + random(150);

        enemy->receive_damage(damage, this_object());
        message_vision( sprintf("$n�԰դ@�n�Q�j�P�����i�Ĩ�A���V�@���R�X�j�f�A��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        this_object()->start_busy(1);
    }
    return;
}
void create()
{
    set_name("�ƳD", ({ "god monster snake", "snake" }));
    set_level(50);
    set_race("beast");
    set("long", "���~�C�H���[���A���l�A�D��A�n���p�w�I�C�ۤj���C \n");
    set("nickname", HIC"���~"NOR);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"food", "id":80, "amount":1, "p1":10, "p2":100 ]),     // �����G
        ([ "type":"food", "id":18, "amount":1, "p1":20, "p2":100 ]),     // �j��O�Y
        ([ "type":"food", "id":17, "amount":1, "p1":30, "p2":100 ]),     // ��O�Y
    }) );
    setup();
}