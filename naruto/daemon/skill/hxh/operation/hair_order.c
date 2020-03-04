#include <ansi.h>
#define SKILL_NAME "hair order"
#define SKILL_NAME_C "��v����"
#define SKILL_CLASS "operation"

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

// �R����O�v�T
int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "lunge" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� lunge �\\��C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_skill("operation", 1) < 40 || sk < 60 ) {
        tell_object(me, "�A���ޯ�{�׵L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/5 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( target->query_condition("hairstick", 1) != 0) {
        tell_object(me, "���w�g���ۤF�A���|�A�Χa�C\n");
        return 0;
    }
    return 1;
}

// ���o�ˮ`
int getDamage(object me, object target)
{
    int raiseDamage, damage;
    object wp;

    raiseDamage = me->query_skill(SKILL_NAME) + me->query_skill("operation")/2;
    me->add_temp("apply/attack", raiseDamage); 

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);
    damage = (damage*100)/(400-raiseDamage);

    return damage;
}

// �j�ׯ�O�v�T
int evade(object me, object target, int ability, int type)
{
    int damage;

    if( !target->query_condition("hairstick", 1) ) return ability;

    if( random(3) != 1 ) {
        damage = getDamage(me, target);
        target->receive_damage(damage, me);
        message_vision("\n$N"HIW"�H�N��ʨ�"NOR"�Q�b�몺��v"HIW"��ˤF$N"HIR"("+damage+")\n"NOR, target);
    }
    return ability;
}

// ��b�ˮ`�e�]�X�A�Ω�s�@�L�ĩάި��m
int receiveDamage(object me, object target, int damage)
{
    int Adamage;

    if( !target->query_condition("hairstick", 1) ) return damage;

    if( COMBAT_D->isHit(me, target) ) {
        Adamage = getDamage(me, target);
        target->receive_damage(Adamage, me);
        message_vision("\n$N"HIW"�H�N����ʨ�"NOR"�Q�b�몺��v"HIW"��ˤF$N"HIR"("+Adamage+")\n"NOR, target);
    }
    return damage;
}

int perform_action(object me, string act, object target)
{
    mapping cnd = ([]);
    int sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !isCast(me, act, target, sk) ) return 1;

    hit = COMBAT_D->isHit(me, target);

    message_vision("$N"HIW"���M�N��������A"NOR+BLINK"�������Y�v�֤�"NOR+HIW"�~�M���p�Ӱw���V"NOR"$n�I\n"NOR, me, target);
    if( !hit ) {
        message_vision("\t���O$n���_���V�Ჾ�ʡA�̫�k�X�F$N�������d��C\n", me, target);
        me->damage_stat("mp", sk/10, me);
        me->start_busy(2);
        return 1;
    } else {
        message_vision("\t$n�{�פ���A�Q$N����v�������A�u�n�H�K���ʴN�|����ˮ`�I\n"NOR, me, target);
        me->damage_stat("mp", sk/5, me);
        me->start_busy(1);

        cnd["name"] = HIW+"��v�v�T"+NOR;
        cnd["duration"] = sk*3/10;
        cnd["from"] = me;

        target->set_condition("hairstick", cnd);
    }
    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);
    return 1;
}