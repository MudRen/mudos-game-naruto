#include <ansi.h>
#define SKILL_NAME "super star"
#define SKILL_NAME_C "����"
#define SKILL_CLASS "activity"

inherit SKILL;

void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

string query_class() { return SKILL_CLASS; }

void skill_advanced(object me, string skill)
{
    int lv = me->query_skill(skill, 1);
    switch( lv ) {
        case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
        case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
        case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*27/100;
}

// �p��O�_�R��
int isHit(object me, object target, int sk)
{
    int hit, meHit, targetHit;

    if( sk < 80 ) meHit = 0;
    else {
        meHit = me->query_ability("intimidate");
        if( sk > 150 ) {
            meHit += me->query_skill(SKILL_NAME, 1);
        }
    }
    targetHit = target->query_ability("wittiness");

    me->add_temp("apply/exact", meHit);
    target->add_temp("apply/evade", targetHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -meHit);
    target->add_temp("apply/evade", -targetHit);

    return hit;
}

// �W�w�H�ޡA�P�_
int check_busy(object me, object target, int sk)
{
    if( sk < 61 ) target->start_busy(1);
    else if( sk < 101 ) target->start_busy(2);
    else if( sk < 141 ) target->start_busy(3);
    else if( sk < 181 ) target->start_busy(4);
    else if( sk < 200 ) target->start_busy(5);
    else target->start_busy(6);
}

int autoCasting(object me, object target, object weapon)
{
    string *msg = ({ "���_�w�`�`�����J���Ҧ׸�...",
                     "�ȹ��}�F��������`...",
                     "�������ˤf�����F�m�Y�}�ߪ�����...",
                     "��ո̪��i�F�@������Φbį��...",
                     "�{���y�X�F���ƤS���ߪ��@....",
                     "���Y��M�����Q���ۤv���y�f��...",
                     "���p�߽�}�ۤv�����]...�y�F���a���G��...",
                  });

    string msgin, msgout;
    int sk, check;

    sk = me->query_skill(SKILL_NAME, 1);

    // �P�_�O�_�Ұ�
    if( target->is_busy() ) return 1;
    if( me->query_stat("mp") < sk/4 ) return 1;
    if( me->query_skill("activity", 1) < 200 ) return 1;
    if( sk < 50 ) return 1;

    if( sk < 80 ) {                          // 20~80 �� 10%
        if( random(sk) < sk*9/10 ) return 1;
    } else if( sk < 150 ) {                  // 81~150 �� 15%
        if( random(sk) < sk*17/20 ) return 1;
    } else {                                 // 151~200 �� 20%
        if( random(sk) < sk*8/10 ) return 1;
    }
    // �P�_�ԭz��
    if( sk > 150 ) check = 3;
    else if( sk > 80 ) check = 2;
    else check = 1;

    // �ԭz�Τ@�g�b�o�̡A��ֵ{��
    switch( check ) {
        case 1:
            msgin = "$N���M�S�X�D�`�V�������j�ۡG"HIW"�y"HIY+me->query("name")+"��ֵ�"HIW"�z"NOR"�I\n";
            msgout = "$n�~���������A�߸̤�����ë�i�d�U���n�Q�����C\n";
            break;
        case 2:
            msgin = "$N���X�@���ªO�A�ΤO���Ϋ��Ҩ�X�o�H��"HIC"�y"HIM"����"HIC"�z"NOR"�A�s�ۤv���֨����F�F...\n"NOR;
            msgout = "$n���G�����F�o�}�����A����\\�ۦզ������������C\n";
            break;
        case 3:
            msgin = "$N���b���x�W�ϥX"HIM"�y"HIB+BLINK+me->query("name")+"�G��"NOR+HIM"�z"NOR"�A�j�ۡG" + msg[random(sizeof(msg))] + "\n";
            msgout = "$n�h�W���˦b�a�W�A�y�����Q�����ݡA���G����F����믫�����I\n";
            break;
        default: return notify_fail("�P�_�����D��C\n"); break;
    }
    message_vision(msgin, me, target);
    if( !isHit(me, target, sk) ) {
        message_vision("���O$n�L�᪺���ۻ�աA���������D$N�b�Fԣ�C\n", me, target);
        me->damage_stat("mp", sk/8, me);
    } else {
        message_vision(msgout, me, target);
        check_busy(me, target, sk);
        me->damage_stat("mp", sk/4, me);
    }
    me->improve_skill(SKILL_NAME, 1);
    return 1;
}