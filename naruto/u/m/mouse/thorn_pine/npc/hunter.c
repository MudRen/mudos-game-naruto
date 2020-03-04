#include <npc.h>

inherit F_BANDIT;

string *name1 = ({ "�F", "��", "��", "��", "�ȼ�", "����", "��", "��", "�U", "��",
                   "��", "�v", "���", "�s", "��", "�j", "���", "�Q", "��", "�N��", 
                   "�y", "��", "�e" , "��", "��", "�d�R", "�إ�", "��", "��", "�W�V" });

string *name2 = ({ "��", "�^", "��", "��", "�z", "��", "���S", "��", "�S�S", "�]",
                   "��", "�[", "�Ϧ�", "��", "��", "�où", "§", "�p", "��", "��W",
                   "��", "�|", "��", "�R��", "�e", "����", "����", "��", "�j��", "�h" });

void do_fight()
{
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
    switch( this_object()->query("sktree") ) {
        case 1: // ����j��
            if( !mapp(this_object()->query_condition("body_strength_cond")) )
            command("perform strength.powerup");
            break;

        case 2: // �����O�ܤ�
            break;

        case 3: // �B���O�ܤ�
            break;

        case 4: // ���u
            command("perform emit.shoot on " + enemy->query_id());
            break;

        case 5: // ��y�A��
            if( !mapp(this_object()->query_condition("blood_cell_revive_cond")) )
            command("perform operation.revive on " + this_object()->query_id());
            break;

        case 6: // �t������
            if( this_object()->query_stat("hp") < 301 ) {
            command("perform special.healing on " + this_object()->query_id());
            }
            break;
    }
}
void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "hunter", "__HUNTER__" }));
    set_race("human");
    set_level(20);
    set("age", 12+random(40));
    set("long", "�L���y�H�ҥ͡A�������Ϋݪ��Q�s���A�����X�P�C\n");
    set_class("hxh_initial");
    set("attitude", "aggressive");         // �D�ʧ���
    // �H������
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));

    // �԰��ʧ@
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":50+random(50), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"obj", "id":69, "amount":1, "p1":25, "p2":100 ]),  // ���X�P
    }) );

    set("sktree", random(6)+1);

    setup();

    // ���A
    set_stat_current("hp", 800);
    set_stat_current("ap", 800);
    set_stat_current("mp", 800);
    set_stat_maximum("hp", 800);
    set_stat_maximum("ap", 800);
    set_stat_maximum("mp", 800);

    // �ޯ�, ²�ƥ��ɾ֦���sk, �N�S��sk��Jsktree���~�߱o

    delete_skill("ninja");  // �R���y�H���Ӧ���
    delete_skill("magic");
    delete_skill("force");

    set_skill("parry", 90);
    set_skill("dodge", 90);
    set_skill("combat", 90);
    set_skill("heavy hit", 90);
    set_skill("savage hit", 90);
    set_skill("continual hit", 90);
    set_skill("solid", 90);                         // ��
    switch( query("sktree") ) {
        case 1: // ����j��
            set_skill("strength", 90);              // �j�ƨt
            set_skill("body strength", 90);
            map_skill("strength", "body strength");
            break;
        case 2: // �����O�ܤ�
            set_skill("variation", 90);             // �ܤƨt
            set_skill("fire variation", 90);
            map_skill("combat", "fire variation");
            break;
        case 3: // �B���O�ܤ�
            set_skill("variation", 90);             // �ܤƨt
            set_skill("ice variation", 90);
            map_skill("combat", "ice variation");
            break;
        case 4: // ���u
            set_skill("emit", 90);                  // ��X�t
            set_skill("psychical bullet", 90);
            map_skill("emit", "psychical bullet");
            break;
        case 5: // ��y�A��
            set_skill("operation", 90);             // �ާ@�t
            set_skill("blood-cell revive", 90);
            map_skill("operation", "blood-cell revive");
            break;
        case 6: // �t������
            set_skill("special", 90);               // �S��t
            set_skill("holy hand", 90);
            map_skill("special", "holy hand");
            break;
    }
    // �W�j
    set_temp("apply/attack", 150);        // �����O�q
    set_temp("apply/armor", 50);          // ���m�O�q
    set_temp("apply/exact", 37);          // �R���v
    set_temp("apply/evade", 50);          // �j�ײv
    set_temp("apply/intimidate", 10);     // ������O
    set_temp("apply/wittiness", 10);      // ���m��O
    set_temp("apply/int", 5);
    set_temp("apply/con", 5);
    set_temp("apply/str", 5);
    set_temp("apply/dex", 5);
}
