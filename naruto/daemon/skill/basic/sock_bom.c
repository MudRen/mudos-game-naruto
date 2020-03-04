/* 這招是專門設計給 mob 使用的
   為了平衡怪物致命機率無法提升的問題
   讓一些大怪有機會增加自己的致命機率
   by mouse 2009/2/15
*/

#include <ansi.h>
#define SKILL_NAME "sock bom"
#define SKILL_NAME_C "致命爆擊"
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
    tell_object(me,"這項技能是不能學習的。\n"NOR);
    return;
}

// 致命一擊傷害提升%, 原始為(150%)
int sockPower(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME);
}
