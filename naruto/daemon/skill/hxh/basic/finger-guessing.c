// finger-guessing fist ����
// Tmr 2005/10/22
// update by Acme 2007.03.16
// ���ܯS��覡 by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME "finger-guessing fist"
#define SKILL_NAME_C "����"
#define SKILL_CLASS "psychical"
#define SKILL_BASE "combat"

inherit SKILL;

// �n�D DEMON_D �n���ޯ�
void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

// �ޯ����
string query_class() { return SKILL_CLASS; }

// �n enable �~�|���@��
int valid_enable(string base_skill) { return base_skill == SKILL_BASE; }

// �ޯ�ɯū�|�I�s���禡�A�q�`�Ψӳ]�w�ɤU�@�ũһݪ��g��
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

// �P�R�@���v�T
int sock(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

// ���o�ˮ`
int getDamage(object me, object target, int raiseDamage)
{
    int damage;
    object wp;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

int autoCasting(object me, object target, object weapon)
{
    int hit, damage, sk, i, j;
    string act, msg, fk;

    // �S��enable���|�Ұ�
    if( me->skill_mapped(SKILL_BASE) != SKILL_NAME ) return 1;
    
    sk = me->query_skill(SKILL_NAME);
    j = me->query_temp("GUESSING_FIST", 1);

    // �P�_�O�_�Ұ�
    if( sk < 20 ) return 1;
    if( sk < 80 ) {                          // 20~80 �� 10%
        if( random(sk) < sk*9/10 ) return 1;
    } else if( sk < 150 ) {                  // 81~150 �� 20%
        if( random(sk) < sk*8/10 ) return 1;
    } else {                                 // 151~200 �� 30%
        if( random(sk) < sk*7/10 ) return 1;
    }
    if( me->query_stat("ap") < 100 ) return 1;

    // �S���R���A�N���ݦA���U�B�z�F
    if( !COMBAT_D->isHit(me, target) ) return 1;

    switch( j ) {
        case 1: act = HIY"�ŤM"NOR;
                damage = me->query_skill("variation")/2 + me->query_skill("concrete")/2 + sk;
                msg = "$N�\\�X"+act+"�����աA���M���ˤF$n���ӻH�y���ˮ`...(%d) %s\n\n";
                i = random(3) + 1;
                break;
        case 2: act = HIY"���Y"NOR;
                damage = me->query_skill("strength") + sk;
                msg = "$N�۵۰��B�ΤO��`���O�A"+act+"����$n��C�y�~...(%d) %s\n\n";
                i = random(3) + 1;
                break;
        case 3: act = HIY"��"NOR;
                damage = me->query_skill("emit")/2 + me->query_skill("operation")/2 + sk;
                msg = "$N�k�ⴤ���áA����@�i"+act+"�A��X���u�N$n�F�Ӧѻ�...(%d) %s\n\n";
                i = random(3) + 1;
                break;
        default: write(HIY"�A�S���M�w�n�X���򮱡A�ҥH�M�w���q���F�C"NOR"\n");
                 return 1;
                 break;
    }
    switch( i ) {
        case 1: fk = "�ŤM"; break;
        case 2: fk = "���Y"; break;
        case 3: fk = "��"; break;
        default: write(target->query("name")+"���G���Q���q���A�A�u�n����q���F�C"NOR"\n");
                 return 1;
                 break;
    }
    me->damage_stat("ap", 10, me);
    message_vision("\n$N�j�n���D�G"HIG"�ܡI�q���I�I�ŤM�B���Y...���I\n"NOR, me, target);
    message_vision("$N�ֳt�����_�Z����X"HIY+act+NOR"�I$n�]�P�ɤ�X"HIR+fk+NOR"�I\n\n", me, target);

    if( act == HIY"�ŤM"NOR && fk == "��" ) {
        message_vision(HIW"$N"HIW"�q���qĹ�F�I�ߨ�X���o�ʧ����I\n"NOR, me, target);
        damage = getDamage(me, target, damage);
        damage = COMBAT_D->receive_damage(target, me, damage);
        target->receive_damage(damage, me);
        message_vision(sprintf(msg, damage, COMBAT_D->report_status(target) ) ,me, target);
        me->improve_skill(SKILL_NAME, 1);
        return 1;
    }
    if( (act == HIY"��"NOR && fk == "�ŤM") || i > j ) {
        damage = getDamage(target, me, 0);
        damage = COMBAT_D->receive_damage(me, target, damage);
        me->receive_damage(damage, target);
        message_vision("$n���c�����ۻ��D�G"HIG"�O$N"HIG"��F�I�Y�ڤ@�O����...\n"NOR, me, target);
        message_vision(sprintf("$n�ΤO���X�@���N$N�����F�˦�n...(%d) %s\n\n", damage, COMBAT_D->report_status(me) ) ,me, target);
    } else if( i < j ) {
        message_vision(HIW"$N"HIW"�q���qĹ�F�I�ߨ�X���o�ʧ����I\n"NOR, me, target);
        damage = getDamage(me, target, damage);
        damage = COMBAT_D->receive_damage(target, me, damage);
        target->receive_damage(damage, me);
        message_vision(sprintf(msg, damage, COMBAT_D->report_status(target) ) ,me, target);
        me->improve_skill(SKILL_NAME, 1);
    } else if( i == j ) {
        message_vision(HIW"���G����~�M�X�@�˪���...����C\n\n"NOR, me, target);
    } else {
        message_vision("���O�P�_�X���D�աI�֧�Ův�B�z�a�I\n"NOR, me, target);
    }
    return 1;
}

string *combat_actions = ({
    "$N����k���A�ϥX�u���Y�v����ݴ�V$n��$l",
    "$N���X���B������A�ϥX�u�ŤM�v�w�O�W�V$n��$l",
    "$N�ϥX�u���v�����@�ڴx�Q�V$n���y�U",
    "$N���s��ⳣ��X�u���v����աA�H�Y���k�}�}���Q�F$n��ڴx",
    "$N�쥻�O�u���Y�v��թ��M�ܦ��F�u�ŤM�v�A�q�t�@�Ӥ���W�V$n��$l",
    "$N�쥻�O�u���v��թ��M�ܦ��F�u���Y�v�A���۬����@�����V$n��$l",
});

string *combat_wp = ({
    "$N�Τ⤤��$w��$n$l���h",
    "$N����$w�A��$n$l���h",
    "$N�N�⤤$w���$n$l���h",
    "$N���ʤ⤤$w�A��V$n$l",
    "$N�M�۪ŻءA�@�ӽb�B�W�e�⤤$w�K��$n$l����",
});

// �w�]�������T���O�Ѩt�δ��ѡA�Y�O enable �b combat ���ޯ઺��
// ���ݫإ߳o�Ө禡���ѧ����T��
string getCombatAction(object me, object weapon)
{
    string skill = me->skill_mapped("combat");

    me->improve_skill(SKILL_NAME, 1);
    if( weapon->is_weapon() ) return combat_actions[random(sizeof(combat_wp))];
    else return combat_actions[random(sizeof(combat_actions))];
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    string msg;
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("�A�{�b�S���ŨϥΡC\n");

    switch( act ) {
        case "�ŤM": me->set_temp("GUESSING_FIST", 1);
                     msg = "$N�g�L�J�Ӫ���ҡA�M�w�U���q�����X"HIY+act+NOR"�C\n";
                     break;
        case "���Y": me->set_temp("GUESSING_FIST", 2);
                     msg = "$N�g�L�J�Ӫ���ҡA�M�w�U���q�����X"HIY+act+NOR"�C\n";
                     break;
        case "��": me->set_temp("GUESSING_FIST", 3);
                   msg = "$N�g�L�J�Ӫ���ҡA�M�w�U���q�����X"HIY+act+NOR"�C\n";
                   break;
        case "none": me->delete_temp("GUESSING_FIST");
                     msg = "$Nı�o�ۤv���ޥ��Ӯt�A�٬O���q���F\n";
                     break;
        default: return notify_fail("�A�������w�n�X���򮱡C\n(perform finger-guessing fist.<�ŤM|���Y|��>)\n"); break;
    }
    message_vision(msg, me);
    return 1;
}
