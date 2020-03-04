#include <ansi.h>
#include <npc.h>
#include "skill.h"

inherit F_SEABANDIT;

string *name1 = ({ "Ĭ", "�t", "��", "�x�T", "�R", "�T", "�R��", "��", "��", "��",
                   "�l", "�w", "�_", "�R�sıù", "�R", "��", "�ڹ�", "�L", "��", "��J", 
                   "�ܩR", "��", "��" , "�d", "��", "�J", "��", "��", "�ǧJ", "�ڤ�" });

string *name2 = ({ "��", "��", "�쭸", "�G��", "���", "�@", "�v����", "�|��", "�L", "�嶳",
                   "�«�", "���", "�}", "���M", "��", "�j", "�|", "��", "��", "�@��",
                   "�L����", "��", "��", "�ڦN", "�_", "��", "��", "��", "��", "�C��" });

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}

void create()
{
    set_name(name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "corsair", "_CORSAIR_" }) );
    set_race("human");
    set_level(20);
    set("attitude", "aggressive");         // �D�ʧ���
    set("class", "little_sea");
    set("age", 10+random(51));
    set("long", "�����_�c�H���n�_�c������A�@�y�ͮ�˪֩w�O������_�c�����Y�C\n");
    set("sktree", random(6)+1);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 25);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":50+random(50), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"obj", "id":110, "amount":1, "p1":15, "p2":100 ]),             // ���_�c
        ([ "type":"obj", "id":111, "amount":1, "p1":15, "p2":100 ]),             // ���_�c
    }) );
    setup();

    // ���A
    set_stat_current("hp", 800);
    set_stat_current("ap", 800);
    set_stat_current("mp", 800);
    set_stat_maximum("hp", 800);
    set_stat_maximum("ap", 800);
    set_stat_maximum("mp", 800);

    // �򥻧ޯ�
    set_skill("parry", 90);
    set_skill("dodge", 90);
    set_skill("combat", 90);
    set_skill("heavy hit", 90);
    set_skill("savage hit", 90);
    set_skill("continual hit", 90);


    // ���e���ҳ� mob ���|dodge, parry and �@��sk
    // ��_�ӬO��� sk �ҥH�o������ mob �˱�Fdodge, parry ��Ψ�� sk
    // �p�⤽���P�ޯ���w�ޯ�ۦP�A�ԭz�W�ק�ӥt�~�g
    // ������ sk �M�b mob �W���Ǧ۰ʧ޷|�o��
    // ���� sk ������������|������L sk �N��

    switch( query("sktree") ) {
        case 1: // ���A�d�ڦN
            set("nickname",HIR"���A"NOR);
            set_skill("blade", 90);                  // �M�N
            break;
        case 2: // �r�~�ϼ��_
            set("nickname",YEL"�r�~��"NOR);
            set_skill("activity", 90);               // �S��
            break;
        case 3: // �¿߲��
            set("nickname",HIK"�¿߲��"NOR);
            set_skill("martial", 90);                // �Z�N
            set_skill("noshadow step", 90);          // �L�v�}
            break;
        case 4: // �ʯv�v�ǧJ��
            set("nickname",HIM"�ʯv�v"NOR);
            set_skill("martial", 90);                // �Z�N
            break;
        case 5: // ���H����
            set("nickname",HIB"���H"NOR);
            set_skill("spurn", 90);                  // ���
            break;
        case 6: // �K���ک�
            set("nickname",HIW"�K��"NOR);
            set_skill("spurn", 90);                  // ���
            set_skill("iron wall", 90);              // �K��
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
