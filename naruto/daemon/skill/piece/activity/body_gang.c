#include <ansi.h>
#define SKILL_NAME "body gang"
#define SKILL_NAME_C "�K���E��"
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

string *defend_message = ({
    HIW"$N���M�Q�����������A���O�@�v�L�ˡC\n"NOR,
    HIW"�u�N�v�a�@�n�A$n�Ϧӵh���z�z�j�s�A���G��������w���C\n"NOR,
    HIW"$N�����Φۤv�����l�w�������A���G�����S������\n"NOR,
});

// target ����ˮ`�e�A���ޯ���]�L receive_damage 
// �p��K�i�H�s�@ "�ȮɵL�ħ�" �άO "�ˮ`�l����" �������ޯ�
int receiveDamage(object me, object target, int damage)
{
    int sk;
    string msg;

    sk = me->query_skill(SKILL_NAME);

    if( me->query_skill("body iron") < 50 && me->query_skill(SKILL_NAME) < 40 ) return damage;

    if( me->query_condition("gang", 1) != 0) {
        msg = defend_message[random(sizeof(defend_message))];
        message_vision(msg, me, target);
        // �W�[�ޯ�g��
        me->improve_skill(SKILL_NAME, 1);
        return 0;
    }
    return damage;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "defence" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�� defence �o�ӥ\\��C\n");
        return 0;
    }

    if( me->query_skill("body iron", 1) < 50 || sk < 40 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/2 ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("gang_busy", 1) != 0) {
        tell_object(me, "����w�ƤӤ[�N�|�L�k�^�_�I�A���@���a�C\n");
        return 0;
    }

    return 1;
}

// ���o�N�o�ɶ�
int check_cd(object me, int sk)
{
    if( sk < 80 ) return 240;
    else if( sk < 120 ) return 210;
    else if( sk < 160 ) return 180;
    else if( sk < 200 ) return 150;
    else return 120;
}

void do_perform(object me, int sk)
{
    int busy;
    mapping cnd = ([]);

    me->damage_stat("mp", sk/2, me);
    message_vision("$N�o�ʤF�K���̱j���m���A"HIW"�y"+SKILL_NAME_C+"�z"NOR"�I\n"NOR, me);

    cnd["name"] = HIW+SKILL_NAME_C+NOR;
    cnd["duration"] = sk/20;

    me->set_condition("gang", cnd);

    busy = check_cd(me, sk);

    cnd["name"] = HIW"(�n��)"NOR;
    cnd["duration"] = busy;

    me->set_condition("gang_busy", cnd);

    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}
