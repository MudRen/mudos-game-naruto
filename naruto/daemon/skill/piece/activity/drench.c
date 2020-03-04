#include <ansi.h>
#define SKILL_NAME "drench"
#define SKILL_NAME_C "���b�j�B"
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

int wittiness(object me, int ability, int type)
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

    if( act != "assoil" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� assoil �\\��C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_condition("drench_cd") ) {
        tell_object(me, "�ثe�{�q�E���٤�������C\n");
        return 0;
    }

    if( me->query_skill("activity", 1) < 80 || sk < 40 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/10 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*2;
    j = COMBAT_D->evade(target, me, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// �ޯ�ϥΫ� 
void setEffect(object me, object target, int sk, int hit)
{
    if( hit || target->query_condition("rain") ) {
        me->start_busy(1);
    } else {
        me->start_busy(2);
    }
    me->damage_stat("mp", sk/10, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit;
    object staff;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    if( !objectp(staff = present("_WEATHER_", me)) ) return notify_fail("�A���W�S���ѭԴΫ��Χޯ�C\n");

    if( !target->query_condition("rain", 1) ) {
        message_vision("\n$N���D�G"HIG"����Ѯ�N���p�B�A�ݪ`�N�v�T���u�C\n"NOR, me, target);
    }
    message_vision("\n$N�ϥX"HIW"�y"HIB"���b�j�B"HIW"�z"NOR"��W��"+staff->query("name")+"�@���A��$n�Q�X�j�q���¶�...�C\n"NOR, me, target);

    // �P�_���S���U�B�A�w�g�U�B�N���A���S���A�A�B�����R���v 100%
    // �ˮ`�֦ӥB���Q�����P�_�A�N���A���򥻶ˮ`�p��F
    if( target->query_condition("rain", 1) != 0) {
        damage = random(sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("�¶�����X�Ӥp���{�q�����F$n....(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);

        cnd["name"] = HIB+"(CD)�p�B"+NOR;
        cnd["duration"] = 2;

        me->set_condition("drench_cd", cnd);

    } else {

        // �P�_�R��
        hit = isHit(me, target);

        if( !hit ) {
            message_vision("���O���h���G��������A�èS���U�B�C\n\n", target);
        } else {
            message_vision("�¶��л\\�b$n���Y���A�M�դ@�n�U�_�ɬ֤j�B�A�v�T�F$n�����u�C\n\n", me, target);

            cnd["name"] = HIB+"�p�B�v�T"+NOR;
            cnd["duration"] = sk/4;
            cnd["intimidate"] = sk/5;
            cnd["exact"] = sk/3;

            target->set_condition("rain", cnd);
        }
    }
    setEffect(me, target, sk, hit);
    return 1;
}
