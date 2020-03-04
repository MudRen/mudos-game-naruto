#include <ansi.h>
#define SKILL_NAME "hair bind"
#define SKILL_NAME_C "��v����"
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
    return ability + me->query_skill(SKILL_NAME)*43/200;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( target->is_busy() ) {
        tell_object(me, "�A�w�g�w��" + target->query("name") + "�F�C\n");
        return 0;
    }

    if( act != "tie" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� tie �\\��C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_condition("hair_cd") ) {
        tell_object(me, "�Q�A�������Y�v�ݶ����믫�C\n");
        return 0;
    }

    if( sk < 100 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/8 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int hit, raiseHit;

    raiseHit = me->query_skill(SKILL_NAME, 1)/4;

    me->add_temp("apply/exact", raiseHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -raiseHit);

    return hit;
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, int hit)
{
    mapping cnd = ([]);

    if( !hit ) {
        me->damage_stat("mp", sk/10, me);
    } else {
        me->damage_stat("mp", sk/8, me);
    }
    cnd["name"] = HIW+"(CD)�v��"+NOR;
    cnd["duration"] = 10;

    me->set_condition("hair_cd", cnd);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    message_vision("\n$N�N�Z�����b�a�W�A���ح߷Q"HIK"�y"BRED+HIW"�ͩR�k��E��v����"NOR+HIK"�z"NOR"�u��$N���Y�v�w�w�a�ͪ��I\n", me, target);

    // �O�_�R��
    hit = isHit(me, target);

    if( !hit ) {
        message_vision("���O�Y�v�ͪ��t�׫ܺC�A���G�S�F��$N�w�����ĪG�C\n\n", me, target);
        me->start_busy(2);
    } else {
        message_vision("���M$N�Y�v�ֳt�ͪ��A�@�����N$n���A��$n�ȮɵL�k��ʡI\n\n", me, target);
        target->start_busy(sk/50);
    }
    setEffect(me, sk, hit);
    return 1;
}
