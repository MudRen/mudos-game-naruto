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
    switch( random(1000) ) {
        case 0..450:
            exact = this_object()->query_level();
            evade = enemy->query_level();

            this_object()->damage_stat("mp", 20, this_object());
            message_vision("\n$N"HIR"���_����H��@���A�ֳt���X���u��"NOR"$n"HIR"�Y�ӡI\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("���O$N���G��ԯ�O�����A�g�X�����u����ѻ��h�F�C\n\n", this_object(), enemy);
                this_object()->start_busy(1);
                return;
            }
            raiseDamage = 250;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            if( damage < 100 ) damage = 50 + random(50);

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("�u�F���v�@�n�A�uť��$n�@�n�G�s�A�@��r�骺�¤H�N�ϥͤF(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            break;
        case 451..550:
            exact = this_object()->query_level();
            evade = enemy->query_level()/2;

            this_object()->damage_stat("mp", 30, this_object());
            message_vision("\n$N"HIK"���˪����_����A��_�D���G��...���G������j�ƭn�o�ͤF...\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("$n�Ѫũ��M�@�����¡A���O�L�F�ܤ[�o�u���@���𸭸��F�U��...\n\n", this_object(), enemy);
                return;
            }
            raiseDamage = 650;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            if( damage < 200 ) damage = 150 + random(50);

            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("�Ѫũ��M�@�����¡A�b�F�����T���A�@�D�¦⪺�{���N�b��������$n������(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->start_busy(1);
            break;
        case 551..999:
            exact = this_object()->query_level();
            evade = enemy->query_level()/2;

            this_object()->damage_stat("mp", 15, this_object());
            message_vision("\n$N"HIC"���_�����"NOR"$n"HIC"�@���I�o�X��D�B�붶�ۤ����V�W�h�I\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("�u���B�뭸��@�b�o���M���h�F�O�q�A������b�a�W�C\n\n", this_object(), enemy);
                return;
            }
            raiseDamage = 100;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("�u���j�v�@�n�A�B���W�b$n�����W�A�᪺$n���o��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->start_busy(1);
            break;
    }
    return;
}

void create()
{
    set_name("�ųD", ({ "wizard snake", "snake" }) );
    set_race("human");
    set("gender", "female");
    set_level(33+random(3));
    set("age", 20+random(41));
    set("limbs", ({ "�D�Y", "�D��", "����", "�ݤf", "�}��", "�ӻH", "�y��" }) );
    set("title",HIG"�D�ڧŮv"NOR);
    set("long", "����@�ڤ�����D�H�A�Y�W�a�ۤ@�����B��e�����C\n");
    set("camp", "snaker");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: command, "say �����D�ڱj�j���O�q�I" :),
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":100 ]),     // �D������
        ([ "type":"wp", "id":51, "amount":1, "p1":1, "p2":200 ]),     // �D��
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // �D��
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // �D�r
    }) );
    setup();
}