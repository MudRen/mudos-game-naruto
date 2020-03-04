#include <ansi.h>
#include <npc.h>
#include "skill.h"

void create()
{
    set_name("�����Τp��", ({ "clown" }));
    set_race("human");
    set_level(40);
    set("age", 5+random(40));

    // �H������
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));

    // �԰��ʧ@
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("set_drop", ({
        ([ "type":"eq", "id":109, "amount":1, "p1":1, "p2":100 ]),    // �j����l
        ([ "type":"eq", "id":107, "amount":1, "p1":1, "p2":400 ]),    // �]�N���
        ([ "type":"obj", "id":107, "amount":1, "p1":1, "p2":1000 ]),  // �������ѷƪO
    }) );

    set("sktree", random(5)+1);

    setup();
    switch( query("sktree") ) {
        case 1: // ���A�p��
            set("nickname",HIC"���A��t"NOR);
            set("long", "�⮳������M�������Y���p���A�y�W�a�ۤp���۵P���L���C\n");
            break;
        case 2: // �]�N�p��
            set("nickname",HIM"�]�N��t"NOR);
            set("long", "�����q�U�l���ܥX�ߤl���p���A�y�W�a�ۤp���۵P���L���C\n");
            break;
        case 3: // �Ť����H
            set("nickname",HIW"�Ť����H"NOR);
            set("long", "��ۥզ�򨭦窺�p���A�����a�V�|�P���ȤH���۩I�C\n");
            break;
        case 4: // ��y�p��
            set("nickname",HIG"��j�y"NOR);
            set("long", "��b�@����y�W�o���|���U�ӡA�y�W�a�ۤp���۵P���L���C\n");
            break;
        case 5: // ����p��
            set("nickname",HIR"������"NOR);
            set("long", "�����b���鶡��Ӭ�h���S�Q�N�ۡA���|�P�ȤH���s�n�C\n");
            break;
    }
    // �W�j
    add_temp("apply/attack", -50);         // �����O�q
    add_temp("apply/armor", 100);          // ���m�O�q
    add_temp("apply/evade", 50);          // �j�ײv
    add_temp("apply/int", 20);             // ���z
    add_temp("apply/dex", 20);             // �ӱ�
}
