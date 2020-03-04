#include <ansi.h>
#define SKILL_NAME "fried cold cuts"
#define SKILL_NAME_C "�o�����A���L"
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

int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int hit, meHit, targetHit;

    meHit = me->query_ability("intimidate");
    targetHit = target->query_ability("evade");

    me->add_temp("apply/exact", meHit);
    target->add_temp("apply/evade", targetHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -meHit);
    target->add_temp("apply/evade", -targetHit);

    return hit;
}

// �p������H��
int check_number(object me, int sk)
{
    int number;

    if( me->query_skill("spurn", 1) >= 70 ) {
        number = (sk/50) - 1;
        if( number <= 0 ) number = 0;
    } else {
        number = 0;
    }
    return number;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk + me->query_skill("spurn")/2;

    if( wp = me->query_temp("weapon/twohanded") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else if( wp = me->query_temp("weapon/righthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else if( wp = me->query_temp("weapon/lefthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else raiseDamage -= COMBAT_D->isDamage(me, target, 0)*3/4;

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
    int damage, sk, i, number, hit;
    object *targets;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();

    // �P�_�O�_�Ұ�
    if( me->query_stat("mp") < sk/10 ) return 1;
    if( me->query_skill("spurn", 1) < 40 ) return 1;
    if( sk < 20 ) return 1;

    if( sk < 80 ) {                          // 20~80 �� 5%
        if( random(sk) < sk*19/20 ) return 1;
    } else if( sk < 150 ) {                  // 81~150 �� 10%
        if( random(sk) < sk*9/10 ) return 1;
    } else {                                 // 151~200 �� 20%
        if( random(sk) < sk*8/10 ) return 1;
    }
    // �R��
    hit = isHit(me, target);

    // �H��
    number = check_number(me, sk);

    cnd["name"] = YEL+"�S�˪��A"+NOR;
    cnd["duration"] = 5;
    cnd["damage"] = sk/10;
    cnd["from"] = me;

    if( me->query_condition("diabo") ) message_vision("$N���l���M�˥ߨϥX"HIR"�y"YEL+BLINK"�o�����A���L"NOR+HIR"�z"NOR"�����P�D���ĤH�I\n", me, target);
    else message_vision("$N���l���M�˥ߨϥX"HIR"�y"YEL"���A���L"NOR+HIR"�z"NOR"�����P�D���ĤH�I\n", me, target);

    for(i=0;i<sizeof(targets);i++) {
        if( i > number ) break;   // �̦h�����|�H
        if( !hit ) {
            message_vision("$n�V��@�����}�F$N�������d��...\n", me, targets[i]);
        } else {
            damage = getDamage(me, targets[i], sk);
            targets[i]->receive_damage(damage, me);
            if( me->query_condition("diabo") ) {
                targets[i]->set_condition("burn", cnd);
                message_vision( sprintf("$n���Q�N�����O�K�S��A���W�L�X�@�Ӥj�j���c�L(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
            }
            else message_vision( sprintf("$n���Q���t��p���T������A��ӤH���F�X�h�h�W����(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
        }
    }
    me->damage_stat("mp", (sk/20)*i, me);
    me->improve_skill(SKILL_NAME, 1);
    return 1;
}
