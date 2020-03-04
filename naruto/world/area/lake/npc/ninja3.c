#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

string *name1 = ({ "���z", "�y�B", "���", "�e�X", "���i", "��", "�ɫB", "�e��",
                   "���C","����", "���", "�Ѫe", "�K�B", "����", "��", "�Ѵ�",
                   "�ʴ�", "�B��" });

string *name2 = ({ "�j����", "�p����", "������", "������", "�F�i", "���H", "���",
                   "��", "�ۦb", "�@��", "�G��", "�T��", "�|��", "����", "����",
                   "�x�e", "��", "����", "��", "��", "�Ӥ[", "�ۤӧg", "��" });

void do_fight()
{
    int damage, raiseDamage, i;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("\n$N�N�y"CYN"���P"NOR"�z���L����x�ߡA�]��L�ڦR�X�u"HIC"���s�u"NOR"�v\n", this_object(), enemy);
    for(i=0;i<3;i++) {
        if( !COMBAT_D->isHit(this_object(), enemy) ) {
            message_vision("$n�a�����}�F���u�������d��I\n", this_object(), enemy);
        } else {
            raiseDamage = 100;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            if( damage < 10 ) damage = random(10) + 1;

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("$n�Q���u�����ݤf�A�y�ɷPı�@�}����(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        }
    }
    this_object()->start_busy(1);
    this_object()->damage_stat("mp", 15, this_object());
    message_vision("\n", this_object(), enemy);
    return;
}
void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "ninja" }));
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
        (: command, "say �_�åѧڭ̫B���������F�I" :),
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