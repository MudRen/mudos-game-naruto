#include <ansi.h>
#define SKILL_NAME "change face shot"
#define SKILL_NAME_C "�㫬��֢ݢ�"
#define SKILL_CLASS "spurn"

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
    return ability + me->query_skill(SKILL_NAME)/5;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int hit, meHit, targetHit;

    meHit = me->query_ability("exact");
    targetHit = target->query_ability("evade")/2;

    me->add_temp("apply/exact", meHit);
    target->add_temp("apply/evade",  targetHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -meHit);
    target->add_temp("apply/evade", - targetHit);

    return hit;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage;
    object wp;

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    if( sk < 100 ) return damage*2/5;        // 40%
    else if( sk < 120 ) return damage*3/5;   // 60%
    else if( sk < 150 ) return damage*4/5;   // 80%
    else if( sk < 180 ) return damage;       // 100%
    else if( sk < 199 ) return damage*11/10; // 110%
    else return damage*125/100;              // 125%
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int hit)
{
    if( !hit ) {
        me->damage_stat("mp", 10, me);
    } else {
        me->damage_stat("mp", sk/10, me);
    }
    me->improve_skill(SKILL_NAME, 1);
}

int autoCasting(object me, object target, object weapon)
{
    string *name1 = ({ "�Ӧ�", "����", "�j�L��", "�U��", "�Ϧ�", "�p����",
                       "�㫬", "����", "�ަ���", });

    string *name2 = ({ "����", "��l", "�L��", "�զ�", });

    int damage, sk, hit;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < sk/10 ) return 1;
    if( me->query_skill("spurn", 1) < 60 ) return 1;
    if( sk < 40 ) return 1;

    if( sk < 80 ) {
        if( random(sk) < sk*9/10 ) return 1; // 20~80 �� 10%
    } else if( sk < 150 ) {
        if( random(sk) < sk*3/4 ) return 1;  // 81~150 �� 25%
    } else {
        if( random(sk) < sk*3/5 ) return 1;  // 151~200 �� 40%
    }

    // �ˮ`�T�w
    damage = getDamage(me, target, sk);

    // �R��
    hit = isHit(me, target);

    // �P�_�O�_���c�]���}���A
    if( me->query_condition("diabo", 1) ) {
        message_vision("$N�˱����ĨϥX"HIY"�y"HIR"�c�]���}�E�e�s�I����֢ݢ�"HIY"�z"NOR"��V$n�I\n", me, target);
        if( !hit ) {
            message_vision("���G�ۦ��b�a�W��X�F�@�Ӥj�}...\n", target, me);
        } else {
            target->receive_damage(damage, me);
            message_vision( sprintf("�u�S�v�a�@�n�A$n���Ӷ���o�X�j�P���~��Y����a��(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);

            cnd["name"] = YEL+"�S�˪��A"+NOR;
            cnd["duration"] = 5;
            cnd["damage"] = sk/5;
            cnd["from"] = me;

            target->set_condition("burn", cnd);
        }
    } else {
        message_vision("$N���}�@�޽ĦV$n�A��X"HIW"�y"YEL + name1[random(sizeof(name1))] + "��֢ݢ�"HIW"�z"NOR"�I\n", me, target);

        if( !hit ) {
            message_vision("���O�Q$N���W�������{�}�F...\n", target);
        } else {
            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(target, me, damage);

            target->receive_damage(damage, me);
            message_vision( sprintf("$n�{�פ��ΡA" + name2[random(sizeof(name2))] + "����Q$N�𤤡A��ӥW�F�i�h...(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
        }
    }
    setEffect(me, sk, hit);
    return 1;
}