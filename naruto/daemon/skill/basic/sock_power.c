/* �o�۬O�M���]�p�� mob �ϥΪ�
   ���F���ũǪ��P�R���v�L�k���ɪ����D
   ���@�Ǥj�Ǧ����|�W�[�ۤv���P�R���v
   by mouse 2009/2/15
*/

#include <ansi.h>
#define SKILL_NAME "sock power"
#define SKILL_NAME_C "�P�R��q"
#define SKILL_CLASS "basic"

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
    tell_object(me,"�o���ޯ�O����ǲߪ��C\n"NOR);
    return;
}

// �P�R�@���v�T
int sock(object me, object target, int ability, int type)
{
    // �P�R�@�����v�Alv200��100%
    return ability + me->query_skill(SKILL_NAME)/2;
}
