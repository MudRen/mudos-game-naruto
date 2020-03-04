#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

string *name1 = ({ "���z", "�y�B", "���", "�e�X", "���i", "��", "�ɫB", "�e��", "���C",
                   "����", "���", "�Ѫe", "�K�B", "����", "��", "�Ѵ�", "�ʴ�", "�B��",
                });
string *name2 = ({ "�j����", "�p����", "������", "������", "�F�i", "���H", "���","��",
                  "�ۦb", "�@��", "�G��", "�T��", "�|��", "����", "����", "�x�e", "��",
                  "����", "��", "��", "�Ӥ[", "�ۤӧg", "��",
                });
void do_fight()
{
    int damage;
    object enemy;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_temp("quest/watershield") == 1) {
    return notify_fail("�ۦ��٨S�h�\�A����A�ϥΡC\n");
    } else {
    message_vision("$N���X�y"CYN"���P"NOR"�z���L������b���ǵe�X�@�ӥ��j����Ρu"HIC"���پ�"NOR"�v\n", this_object(), enemy);
    message_vision("        ��κ����o�X���~���$N�A��$N�����m�W�[�F�ƭ��I\n", this_object(), enemy);
    this_object()->start_busy(2);
    set_temp("apply/armor", 150);
    this_object()->add_temp("quest/watershield", 1);
    call_out("watershield_1",120,this_object(),enemy);
    }
}
void watershield_1()
{
    object enemy;
    message_vision("$N���Ǫ����~�����h�h�A���m�]��z�F�C\n", this_object(), enemy);
    set_temp("apply/armor", 0);
    this_object()->delete_temp("quest/watershield");
    return;
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
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    // �԰��ʧ@
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: command, "say �Q��ڭ̫B���m�_�áH���I" :),
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
