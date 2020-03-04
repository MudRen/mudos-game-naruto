#include <npc.h>
#include <ansi.h>

string *name1 = ({ "���", "��K", "���", "�븭", "���", "���",
                   "�Q��", "�Q�K", "�Q��", "�Q��", "�Q��", "�Q��",
                   "�f��", "�f�K", "�f��", "�f��", "�f��", "�f��",
                   "�K��", "�K�K", "�K��", "�K��", "�K��", "�K��", });

string *name2 = ({ "�]", "��", "��", "��", "��", "�P", "��" });

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
    // ���ŤӧC���� perform, �w�g�Q�w�N���� perform
    if( enemy->query_level() < 5 ) return;
    if( enemy->is_busy() ) return;

    message_vision("\n$N"HIG"�K���@�i�A�p�P�ۭ��몺�ֳt��"NOR"$n"HIG"���h�I\n"NOR, this_object(), enemy);
    if( random(5) > 2) {
        message_vision("$n�ۧC���l�{�L�F�����I\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    damage = 100;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->damage_stat("hp", damage, this_object());
    message_vision( sprintf("$n�u�ԡI�v�a�@�n�Q��½�b�a�W(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    enemy->start_busy(3);
    return;
}
void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "thorn tree", "tree" }));
    set_race("beast");
    set_level(25+random(6));
    set("long", "��Q�L������ڡA�|�۰ʧ����~�Ӫ̡C\n");
    set("limbs", ({ "����", "��F", "���", "���", "���", "���", "�K�Y" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    // �H������
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    switch( random(101) ) {
        case 0..15:
            set("set_drop", ({
                ([ "type":"obj", "id":60, "amount":1, "p1":50, "p2":100 ]),  // ���
                ([ "type":"obj", "id":61, "amount":1, "p1":35, "p2":100 ]),  // ���
                ([ "type":"obj", "id":70, "amount":1, "p1":20, "p2":100 ]),  // ���
                ([ "type":"obj", "id":73, "amount":1, "p1":60, "p2":100 ]),  // �����G
            }) );
            break;
        case 16..34:
            set("set_drop", ({
                ([ "type":"obj", "id":60, "amount":1, "p1":50, "p2":100 ]),  // ���
                ([ "type":"obj", "id":61, "amount":1, "p1":35, "p2":100 ]),  // ���
                ([ "type":"obj", "id":70, "amount":1, "p1":20, "p2":100 ]),  // ���
                ([ "type":"obj", "id":72, "amount":1, "p1":60, "p2":100 ]),  // �����G
            }) );
            break;
        case 35..94:
            set("set_drop", ({
                ([ "type":"obj", "id":60, "amount":1, "p1":50, "p2":100 ]),  // ���
                ([ "type":"obj", "id":61, "amount":1, "p1":35, "p2":100 ]),  // ���
                ([ "type":"obj", "id":70, "amount":1, "p1":20, "p2":100 ]),  // ���
                ([ "type":"obj", "id":71, "amount":1, "p1":60, "p2":100 ]),  // ����G
            }) );
            break;
        default:
            set("set_drop", ({
                ([ "type":"obj", "id":60, "amount":1, "p1":50, "p2":100 ]),  // ���
                ([ "type":"obj", "id":61, "amount":1, "p1":35, "p2":100 ]),  // ���
                ([ "type":"obj", "id":70, "amount":1, "p1":20, "p2":100 ]),  // ���
                ([ "type":"obj", "id":74, "amount":1, "p1":60, "p2":100 ]),  // ������G
            }) );
            break;
    }
    setup();
}