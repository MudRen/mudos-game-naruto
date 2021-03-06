/* continual_hi.c 連擊
*/

#include <ansi.h>
#define SKILL_NAME  "continual hit"
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
    switch( lv ) {
        case 189: me->set_skill_require(skill, 1500000); break; // 關卡3 : 189升190
        case 149: me->set_skill_require(skill, 1000000); break; // 關卡2 : 149升150
        case  99: me->set_skill_require(skill, 500000);  break; // 關卡1 :  99升100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

// 自動施展技，判斷是否要多打一下
int autoCasting(object me, object target, object weapon)
{
    int lv;

    // 這一個attack是由連擊發起的，所以不應該再判斷是不是要連擊
    if( me->query_temp("skill/" + SKILL_NAME) ) return 1;

    // 沒有成攻發動連擊
    lv = me->query_skill(SKILL_NAME);
    if( random(lv) < random(400) ) return 1;

    message_vision(HIW"$N看到了$n的破綻，隨即再補上一擊...\n"NOR, me, target);

    // 設定暫存資料，用來阻止連擊打出去的那一招也觸動連擊
    me->set_temp("skill/" + SKILL_NAME, 1);
    
    // 再次攻擊
    me->attack(target);
    
    // 清除暫存資料
    me->delete_temp("skill/" + SKILL_NAME);
    
    // 增加技能經驗
    me->improve_skill(SKILL_NAME, 1);

    return 1;
}
