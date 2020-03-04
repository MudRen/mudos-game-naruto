#include <ansi.h>
#define SKILL_NAME "destory fist"
#define SKILL_NAME_C "�}�a��"
#define SKILL_CLASS "strength"

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

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "attack" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� attack �\\��C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�å��M���b�԰���...\n");
        return 0;
    }

    if( me->query_skill("strength", 1) < 80 || sk < 40 ) {
        tell_object(me, "�A�ٵL�k�t��}�a�����j�j���O�C\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/4 ) {
        tell_object(me, "�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1);
    j = COMBAT_D->wittiness(target, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// �p��O�_�X�{�P�R�@��
int isSock(object me, object target)
{
    // �W�L 59 �Ť~���P�R�@�����v�T
    if( me->query_skill("body strength", 1) < 60 ) return 0;

    // �[�P�R�@�����v
    return (COMBAT_D->sock(me, target, 1) > random(100));
}

// ���o�ˮ`
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    // �����O�q�v�T�̰� 800 �ˮ`
    if( me->query_ability("attack") < 400 ) raiseDamage = sk*4 + me->query_skill("strength") + me->query_skill("body strength") + me->query_ability("attack")*2;
    else raiseDamage = sk*4 + me->query_skill("strength") + me->query_skill("body strength") + 800;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk)
{
    me->damage_stat("mp", sk/4, me);
    me->start_busy(4);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int hit, sock, sk, damage;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    // �O�_�P�R�@��
    sock = isSock(me, target);

    // �O�_�R��
    hit = isHit(me, target);

    // �����T��
    if( sock ) message_vision(HIR"\n(�P�R�@��) "NOR"$N"HIY"�������O�z���A�k���@�O�u"HIR"�W"NOR"�E"HIY+BLINK"�}�a��"NOR+HIY"�v�µ�"NOR"$n"HIY"�������h�I"NOR"\n", me, target);
    else message_vision("\n$N�������O�z����$n���X�@�O�u"HIY"�}�a��"NOR"�v�I"NOR"\n", me, target);

    // ���R��
    if( !hit ) {
        // �p�G�X�{�P�R�@���A�٬O�|���ˮ`
        if( sock ) {
            // �W�[1/10���ˮ`
            damage = getDamage(me, target, sk)/10;
            target->receive_damage(damage, me);
            message_vision( sprintf("$N�@�����������a���A�o���o�X�ּu�몺�z���¤O���ˤF$n(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);

        // �_�h��������
        } else message_vision("$N�@�����������a���A���X�F�@�Ӥj�}�C\n\n", me, target);

    // �R��
    } else {
        // �P�R�@��
        if( sock ) {
            // �W�[�ˮ`
            damage = getDamage(me, target, sk);
            target->receive_damage(damage, me);
            message_vision( sprintf("$n�Q�k�����������A�]���j�j���O�D�e���Y��������������(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);

        // ���P�R�@��
        } else {
           damage = getDamage(me, target, sk)/2;
           target->receive_damage(damage, me);
           message_vision( sprintf("$n�Q�k�����������A�G�z�@�n���G�O��ٳQ���_�F(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
        }
    }
    setEffect(me, sk);
    return 1;
}