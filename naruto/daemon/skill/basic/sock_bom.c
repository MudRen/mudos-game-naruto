/* �o�۬O�M���]�p�� mob �ϥΪ�
   ���F���ũǪ��P�R���v�L�k���ɪ����D
   ���@�Ǥj�Ǧ����|�W�[�ۤv���P�R���v
   by mouse 2009/2/15
*/

#include <ansi.h>
#define SKILL_NAME "sock bom"
#define SKILL_NAME_C "�P�R�z��"
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

// �P�R�@���ˮ`����%, ��l��(150%)
int sockPower(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME);
}
