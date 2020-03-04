#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;
int i;

string *name1 = ({ "���z", "�y�B", "���", "�e�X", "���i", "��", "�ɫB", "�e��", "���C",
                   "����", "���", "�Ѫe", "�K�B", "����", "��", "�Ѵ�", "�ʴ�", "�B��",
                });
string *name2 = ({ "�j����", "�p����", "������", "������", "�F�i", "���H", "���","��",
                  "�ۦb", "�@��", "�G��", "�T��", "�|��", "����", "����", "�x�e", "��",
                  "����", "��", "��", "�Ӥ[", "�ۤӧg", "��",
                });
string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight()
{
    int damage;
    object enemy;
    string msg;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("$N����ֳt���y"CYN"���P"NOR"�z���L�ϥX�u"HIC"���Īi"NOR"�v\n", this_object(), enemy);
    i = (random(this_object()->query_ability("attack")) - random(enemy->query_ability("defend")));
    if(i < 1) {
    damage = random(5);
    } else {
    damage = i + random(20);
    }
    if( random(10) < random(2)) {
    message_vision("        $n����L�I���q�@���פF�}�ӡI\n", this_object(), enemy);
    this_object()->start_busy(2);
    } else if( damage < 1) {
    message_vision("        $n�Q���i�F�ӥ��ۡA�o�S����ˮ`�C(0)"+report_status(enemy)+"", this_object(), enemy);
    this_object()->start_busy(1);
    return;
    } else {
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n�{������A�Q���i�ĦV�ƤV���~�A�����h�W���w�I("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
    }
}
void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "ninja" }));
    set_race("human");
    set_level(25+random(3));
    set("age", 15+random(50));
    set("long", "�B�����Ԫ̡A���W�I�F�\�h�_�îw���_�÷ǳƯO�]�C\n");
    set("attitude", "aggressive");         // �D�ʧ���
    // �H������
    set("chat_chance", 6);
    set("chat_msg", ({
        (: random_move :),
    }));
    // �԰��ʧ@
    set("chat_chance_combat", 15);
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
    // �ޯ�
    set_skill("ninja", 90);
    set_skill("force", 90);
    set_skill("parry", 60);
    set_skill("combat", 80);
    set_skill("heavy hit", 60);
    set_skill("savage hit", 60);
    // �W�j����, �]���S�\�����Y���C���m
    set_temp("apply/attack", 100);        // �����O�q
    set_temp("apply/exact", 20);          // �R���v
    set_temp("apply/intimidate", 20);     // ������O
}
