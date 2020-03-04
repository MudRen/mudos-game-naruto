#include <ansi.h>
#define SKILL_NAME "fruit"
#define SKILL_NAME_C "�c�]�G��"
#define SKILL_CLASS "fruit"

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

int intimidate(object me, int ability, int type) { return ability; }
int wittiness(object me, int ability, int type) { return ability; }
int exact(object me, object target, int ability, int type) { return ability; }
int evade(object me, object target, int ability, int type) { return ability; }
int attack(object me, object target, int ability, int type) { return ability; }
int defend(object me, object target, int ability, int type) { return ability; }
int sock(object me, object target, int ability, int type) { return ability; }
int receiveDamage(object me, object target, int damage) { return damage; }