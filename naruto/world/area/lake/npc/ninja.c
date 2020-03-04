#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;
int i;

string *name1 = ({ "���z", "�y�B", "���", "�e�X", "���i", "��", "�ɫB", "�e��",
                   "���C","����", "���", "�Ѫe", "�K�B", "����", "��", "�Ѵ�",
                   "�ʴ�", "�B��" });

string *name2 = ({ "�j����", "�p����", "������", "������", "�F�i", "���H", "���",
                   "��", "�ۦb", "�@��", "�G��", "�T��", "�|��", "����", "����",
                   "�x�e", "��", "����", "��", "��", "�Ӥ[", "�ۤӧg", "��" });

void do_fight()
{
    int damage, raiseDamage, exact;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->exact(this_object(), 1)/5;
    add_temp("apply/exact", exact);

    message_vision("\n$N����ֳt���y"CYN"���P"NOR"�z���L��$n�Q�X�j�O���W�u"HIC"���Īi"NOR"�v�I\n", this_object(), enemy);
    this_object()->damage_stat("mp", 10, this_object());
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("$n����L�I���q�@���פF�}�ӡI\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    raiseDamage = 250;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 50 ) damage = 25 + random(25);

    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("$n�{������A�Q���i�ĦV�ƤV���~�A�����h�W���w(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    add_temp("apply/exact", -exact);
    enemy->start_busy(1);
    return;
}
void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "rain ninja", "ninja" }));
    set_race("human");
    set_level(25+random(3));
    set("age", 15+random(50));
    set("nickname",HIC"�B���Ԫ�"NOR);
    set("long", "�B�����Ԫ̡A���W�I�F�\�h�_�îw���_�÷ǳƯO�]�C\n");
    set("camp", "rain");

    // �H������
    set("chat_chance", 6);
    set("chat_msg", ({
        (: random_move :),
    }));
    // �԰��ʧ@
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: command, "say �����ڪ����P�N�a�I" :),
    }) );

    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":50+random(50), "p1":60, "p2":100 ]),  // �Ȥl
        ([ "type":"wp", "id":5, "amount":1, "p1":10, "p2":100 ]),                // �W�L
        ([ "type":"obj", "id":49, "amount":1, "p1":40, "p2":100 ]),              // �j����~
        ([ "type":"obj", "id":41, "amount":1, "p1":30, "p2":100 ]),              // ��o����
        ([ "type":"obj", "id":45, "amount":1, "p1":20, "p2":100 ]),              // ��������
        ([ "type":"obj", "id":48, "amount":1, "p1":10, "p2":100 ]),              // ��y��
        ([ "type":"obj", "id":40, "amount":1, "p1":5, "p2":100 ]),               // �Ǯa���_
    }) );
    setup();

    // �W�j
    add_temp("apply/attack", 50);
    add_temp("apply/exact", 20);
    add_temp("apply/intimidate", 20);
}