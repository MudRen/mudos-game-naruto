#include <npc.h>
#include <ansi.h>

void do_fight(string arg)
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
    exact = COMBAT_D->evade(this_object(), enemy, 1);
    evade = COMBAT_D->evade(enemy, this_object(), 1);

    this_object()->damage_stat("mp", 30, this_object());
    message_vision("\n$N�����a�������l�A�o�X�j�P���ۭ��I"HIC"�u�P�ɭ��v"NOR"�ֳt���j�V$n�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("�ۭ��q$n�����W���h�A���O$n�a����H���N�ӤO����F�C\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    raiseDamage = 750;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 300 ) damage = 200 + random(100);

    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("�ۭ������N$n���ܪŤ��A$N�K���ծi�}�@�s�ꪺ����(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    enemy->start_busy(1);
    return;
}
void create()
{
    set_name("�a����", ({ "fly owl", "owl" }) );
    set_race("beast");
    set("title", HIY"�p���l����" NOR);
    set_level(40+random(6));
    set("age", 100+random(251));
    set("camp", "owl");
    set("long", @LONG
�����q��B���Ӫ����t���l���A�ͩʳ��w�����j�B�W�ɮ�y�j�P���a
��A�o�F���r���N���n�����F�e�̨̳Ϊ��Ϯ����a�C���س����]���M
��Ϯ��a�D�`���e���A�ҥH�C��e�̧��@�B�Ϯ����a��A�K�|�ܺ�
�ү઺�����쥻�Ϯ��b��a������ͪ��C
LONG);

    set("limbs", ({ "�Y��", "����", "�{�l", "�ͻH", "����", "���L", "�I��" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":84, "amount":1, "p1":1, "p2":600 ]),   // �����l
        ([ "type":"eq", "id":83, "amount":1, "p1":1, "p2":100 ]),   // ������
        ([ "type":"obj", "id":67, "amount":1, "p1":20, "p2":100 ]), // ������
        ([ "type":"obj", "id":68, "amount":1+random(5), "p1":40, "p2":100 ]), // ����
        ([ "type":"eq", "id":63, "amount":1, "p1":30, "p2":100 ]),  // ���L
        ([ "type":"obj", "id":27, "amount":5+random(16), "p1":100, "p2":100 ]), // �Ф�
    }) );
    setup();
}