#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

void do_fight()
{
    int damage, raiseDamage;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    this_object()->damage_stat("mp", 15, this_object());
    message_vision("\n$N�`�l�F�@�f��N�R�ۤ�R�������s���A�u"HIK"�y��"NOR"�v�ֳt�����V$n�I\n"NOR, this_object(), enemy);

    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("$n�ߨ���X�����ۤF�U�ӡA�u��$N�ۤv���V$n�������^�b�a�W�C\n\n", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    if( enemy->query("guild") == "piece" ) raiseDamage = 400;
    else raiseDamage = 300;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 150 ) damage = 100 + random(50);

    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("�u�I�I�v�a�@�n$n��ӳQ��½�F�@��A�Y�������F�n��_�������M��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}
void create()
{
    set_name("�\�H�o��", ({ "bow criminal", "criminal" }));
    set_race("human");
    set_level(25+random(11));
    set("age", 5+random(81));
    set("camp", "bow");
    set("limbs", ({ "�Y��", "����", "����", "�L��", "����", "�զ�", "�ӳ�", "�I��" }));
    set("long", "�ǤF���W���\�H�A���b�F���r�o�̱����B�@�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":45, "amount":1, "p1":20, "p2":100 ]),  // ��C
        ([ "type":"wp", "id":33, "amount":1, "p1":10, "p2":100 ]),  // �j���
        ([ "type":"wp", "id":41, "amount":1, "p1":10, "p2":100 ]),  // ���M
        ([ "type":"wp", "id":39, "amount":1, "p1":1, "p2":100 ]),   // �n�j
        ([ "type":"wp", "id":36, "amount":1, "p1":1, "p2":150 ]),   // �课�C
    }) );
    setup();
}