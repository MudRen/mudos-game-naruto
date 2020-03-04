#include <ansi.h>
#define SKILL_NAME "attack star"
#define SKILL_NAME_C "�����P"
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

// �p��O�_�R��
int isHit(object me, object target, int sk)
{
    int hit, raiseHit;

    if( sk > 100 ) raiseHit = me->query_skill(SKILL_NAME, 1);
    else raiseHit = me->query_skill(SKILL_NAME, 1)/3;

    me->add_temp("apply/exact", raiseHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -raiseHit);

    return hit;
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

    if( sk < 100 ) return damage/2;          // 50%
    else if( sk < 120 ) return damage*3/5;   // 60%
    else if( sk < 150 ) return damage*7/10;  // 70%
    else if( sk < 180 ) return damage*4/5;   // 80%
    else if( sk < 199 ) return damage*9/10;  // 90%
    else return damage;                      // 100%
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int hit)
{
    if( !hit ) {
        me->damage_stat("mp", sk/10, me);
    } else {
        me->damage_stat("mp", sk/5, me);
    }
    me->improve_skill(SKILL_NAME, 1);
}

int autoCasting(object me, object target, object weapon)
{
    string msgin, msgout;
    int damage, sk, check, hit;
    object staff;

    sk = me->query_skill(SKILL_NAME, 1);

    // ���������W���S���u�}
    if( !objectp(staff = present("_CATAPULT_", me)) ) return 1;

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < sk/5 ) return 1;
    if( me->query_skill("activity", 1) < 60 ) return 1;
    if( sk < 80 ) return 1;

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

    // �ԭz�Τ@�g�b�o�̡A��ֵ{��
    switch( check ) {
        case 1:
            msgin = "$N�ϥX"HIW"�y"NOR"�]�P"HIW"�z"NOR"���X�@���]�l�u�Ԥ}�g�V$n�I\n";
            msgout = "�u�N�v�a�@�n$n���Y�W�Q�{�X�@�Ӥj�]...(%d) %s\n";
            break;
        case 2:
            msgin = "$N�������F�@�U�A���_�@�����Z�L�_��"HIR"�l�u"NOR"�A�ֳt���g�V$n�I\n"NOR;
            msgout = "�u�S�v�I�l�u�R��$n���᩿�M�o���z���A��ӬO"HIY"�y"HIR"���ĬP"HIY"�z"NOR"�I(%d) %s\n";
            break;
        case 3:
            msgin = "$N���_�|���l�u���g�ӥX�A�l�u�b���Ť��z�}�{�p"HIC"�y"RED"����"HIC"�z"NOR"�A�ֳt�����V$n�I\n";
            msgout = "�u�F�v�a�@�n���T�A$n�Q�z���������O���᭱½�F�X��(%d) %s\n";
            break;
        case 4:
            msgin = "$N�µ�$n����V�s��g�X�X�ح��q���P��"HIR"�y"HIY"����"HIR"�z"NOR"�I\n";
            msgout = "���ݼu�u�R�E�԰աv�a���b$n�����W�A�h��$n�ۦb�a�W�o��(%d) %s\n";
            break;
        default: return notify_fail("�P�_�����D��C\n"); break;
    }
    // �����ԭz�B�ˮ`�P�w
    if( sk > 100 + random(200) ) {
        damage = getDamage(me, target, sk, staff)*2;
        message_vision(HIW"(��Ǯg��) "NOR+msgin, me, target);
    } else {
        damage = getDamage(me, target, sk, staff);
        message_vision(msgin, me, target);
    }
    if( !hit ) {
        message_vision("���O$N���������h�F���Y�A�����D�g����h�F�C\n", me, target);
    } else {
        // �ˮ`�ާl��
        damage = COMBAT_D->receive_damage(target, me, damage);
        target->receive_damage(damage, me);
        message_vision( sprintf(msgout, damage, COMBAT_D->report_status(target)), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}