#include <npc.h>

inherit F_BANDIT;

string *name1 = ({ "�K", "�y", "�p", "��", "�ʰ�", "��", "����", "�a", "�B��", "�մ�", 
                  "�a", "��", "��", "�P", "�n", "�P", "�n", "�k", "��", "Ĭ", "�]", 
                  "��]", "��", "�ܥ�", "�ѲP", "��", "��", "��", "��", "�i", "�T��", 
                  "��", "��", "��", "��", "���" });

string *name2 = ({ "�@��", "�v", "��", "��", "�]��", "����", "�E�s����", "����", "�C�l",
                  "���F", "����", "��", "��", "�P", "�ۦb", "�ԧQ", "�L", "��", "�]",
                  "����", "�q�N", "�줣", "�t��", "��", "�_�_", "�]�e", "�s��", "��",
                  "��", "��", "�m", "�I", "���", "��", "��" });

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
        case 1: // �|�}�N
            command("perform four foot.beast");
            break;
        case 2: // ���ƳN
            if( !mapp(this_object()->query_condition("dp")) )
            command("perform double physique.dp");
            break;
        case 3: // �줧���P��
            break;
        case 4: // �ʯP�x
            command("perform hundred palm.attack on " + enemy->query_id());
            break;
        case 5: // �d�~��
            command("perform thousand year kill.attack on " + enemy->query_id());
            break;
        case 6: // �ӭM����
            break;
    }
}

void do_ca()
{
    if( this_object()->query("sktree") != 6 || this_object()->query_condition("ca2") != 0 ) return;
    command("perform cell activation.ca");
    this_object()->heal_stat("mp", 200);
}

void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "ninja" }));
    set_race("human");
    set_level(20);
    set("age", 10+random(21));
    set("long", "�@�ӥ��b�������ԦҸժ��ǥ͡A�W�i���F�i���C\n");

    set("attitude", "aggressive");         // �D�ʧ���

    // �H������
    set("chat_chance", 4);
    set("chat_msg", ({
        (: do_ca :),
        (: random_move :),
    }));

    // �԰��ʧ@
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":50+random(50), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"obj", "id":9, "amount":1, "p1":15, "p2":100 ]),  // �a����
        ([ "type":"obj", "id":13, "amount":1, "p1":15, "p2":100 ]),  // �Ѥ���
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

    // �ޯ�
    set_skill("ninja", 90);
    set_skill("force", 90);
    set_skill("parry", 90);
    set_skill("dodge", 90);
    set_skill("combat", 90);
    set_skill("heavy hit", 90);
    set_skill("savage hit", 90);
    set_skill("continual hit", 90);
    set_skill("substitute", 90);
    map_skill("dodge", "substitute");      // �ϥΧޯ�u�����N�v��j�קޥ��W

    switch( query("sktree") ) {
        case 1: // �|�}�N
            set_skill("four foot", 90);
            break;
        case 2: // ���ƳN
            set_skill("double physique", 90);
            break;
        case 3: // �츭���P��
            set_skill("muye wind", 90);
            break;
        case 4: // �ʯP�x
            set_skill("hundred palm", 90);
            break;
        case 5: // �d�~��
            set_skill("thousand year kill", 90);
            break;
        case 6: // �ӭM����
            set("chat_chance", 50);
            set_skill("cell activation", 90);
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
