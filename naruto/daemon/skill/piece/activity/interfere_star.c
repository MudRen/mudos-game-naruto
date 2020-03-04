#include <ansi.h>
#define SKILL_NAME "interfere star"
#define SKILL_NAME_C "�z�Z�P"
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

int intimidate(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

// �p��O�_�R��
int isHit(object me, object target, int sk)
{
    int hit, meHit, targetHit;

    if( sk > 100 ) meHit = me->query_skill(SKILL_NAME, 1)/2 + me->query_ability("intimidate");
    else meHit = me->query_ability("intimidate");

    targetHit = target->query_ability("evade");

    me->add_temp("apply/exact", meHit);
    target->add_temp("apply/evade", targetHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -meHit);
    target->add_temp("apply/evade", -targetHit);

    return hit;
}

// �����H�ƧP�_
int check_number(object me, int sk)
{
    int number;

    number = (sk/100) - 1;
    if( number <= 0 ) number = 0;

    return number;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk, object staff)
{
    int damage;
    object wp;

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    damage += staff->query("damage/twohanded/upper");

    if( sk < 100 ) return damage*3/20;            // 15%
    else if( sk < 120 ) return damage*9/50;       // 18%
    else if( sk < 150 ) return damage*23/100;     // 23%
    else if( sk < 180 ) return damage*13/50;      // 26%
    else if( sk < 199 ) return damage*3/10;       // 30%
    else return damage*2/5;                       // 40%

    return damage;
}

int autoCasting(object me, object target, object weapon)
{
    string msgin, msgout;
    int damage, sk, check, i, number, hit;
    object *targets, staff;

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();

    // ���������W���S���u�}
    if( !objectp(staff = present("_CATAPULT_", me)) ) return 1;

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < sk/20 ) return 1;
    if( me->query_skill("activity", 1) < 40 ) return 1;
    if( sk < 20 ) return 1;

    if( sk < 80 ) {                          // 20~80 �� 10%
        if( random(sk) < sk*9/10 ) return 1;
    } else if( sk < 150 ) {                  // 81~150 �� 20%
        if( random(sk) < sk*8/10 ) return 1;
    } else {                                 // 151~200 �� 30%
        if( random(sk) < sk*7/10 ) return 1;
    }
    // �P�_�ԭz��
    if( sk > 100 ) check = 4 - random(2);
    else check = random(2) + 1;

    // �R���P�_
    hit = isHit(me, target, sk);

    // �����H��
    number = check_number(me, sk);

    // �ԭz�Τ@�g�b�o�̡A��ֵ{��
    switch( check ) {
        case 1:
            msgin = "$N���X�y���u�}�A�H��N�X�@��"HIW"���J"NOR"�g�V$n�I\n";
            msgout = "�u�ԡv�a�@�n���J�{��$n�A�|�P�ǥX�@�}�{���...(%d) %s\n";
            break;
        case 2:
            msgin = "$N���X�y���u�}�A��F�@��l�u�g�V$n�I"HIW"�᭱�ٲo�F�@����շ�...\n"NOR;
            msgout = "�u�I�v�a�@�n�l�u�z�}...�|�P�@�ϱK�G�A�檺$n���R�y��(%d) %s\n";
            break;
        case 3:
            msgin = "$N�԰_�u�}�j��"HIY"�y"HIG"�V�鸪�P"HIY"�z"NOR"�g�X���l�u���M�z�}�Q�V�|���K��I\n";
            msgout = "�u�����v���n�L�ƪ��l�u�����b$n���W�A�h��$n�z�z�j�s(%d) %s\n";
            break;
        case 4:
            msgin = "$N�����@�U�g�X"HIB"�y"HIM"�K��Ԧa��"HIB"�z"NOR"�u���a�W�����F�K��ԡI\n";
            msgout = "���M�ǥX�u����v�@�n�A��ӬO$n�~���a�W�������F(%d) %s\n";
            break;
        default: return notify_fail("�P�_�����D��C\n"); break;
    }
    message_vision(msgin, me, target);
    for(i=0;i<sizeof(targets);i++) {
        if( i > number ) break;   // �̦h������H
        if( !hit ) {
            message_vision("���O$N���������h�F���Y�A�����D�g����h�F�C\n", me, targets[i]);
        } else {
            damage = getDamage(me, targets[i], sk, staff);

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(target, me, damage);

            targets[i]->receive_damage(damage, me);

            // �S���Q�w�~��w�H
            if( !targets[i]->is_busy() ) targets[i]->start_busy(1);
            message_vision( sprintf(msgout, damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
        }
    }
    me->damage_stat("mp", sk/20*i, me);
    me->improve_skill(SKILL_NAME, 1);
    return 1;
}