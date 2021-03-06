// holy_hand.c 特質系-聖療之手
// 2005/10/22 -Tmr
// 經過討論後修改為 cd 10分鐘
// 因為功能特殊，加上可能會放失敗的判斷

#include <ansi.h>
#define SKILL_NAME   "holy hand"
#define SKILL_NAME_C "聖療之手"
#define SKILL_CLASS  "special"

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

// 檢查是否能使用技能
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) ) return 0;

    // 沒有目標就指定為自己
    if( !objectp(target) ) target = me;

    if( me->query_condition("holy_hand_cond" ) ) {
        tell_object(me, "你身體的狀態還沒有恢復，暫時無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }
    if( me->is_busy() ) {
        tell_object(me, "你正忙著。\n");
        return 0;
    }
    if( act != "healing" ) {
        tell_object(me, "" + SKILL_NAME_C + "只有 healing 的功\能。\n");
        return 0;
    }
    if( sk < 25 || me->query_skill("special", 1) < 30  ) {
        tell_object(me, "你目前的能力還不足以使用" + SKILL_NAME_C + "。\n");
        return 0;
    }
    if( me->query_stat("mp") < 50 ) {
        tell_object(me, "你的念力值低於 50，無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }
    return 1;
}

// 使用絕招
int perform_action(object me, string act, object target)
{
    int sk;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    if( !isCast(me, act, target, sk) ) return 1;

    message_vision("\n$N兩手合十唸道："HIG"神愛世人...我愛你們...\n"NOR, me, target);
    message_vision(HIW"$N雙手佈滿皎潔的光輝，輕輕地觸碰了$n一下...\n\n"NOR, me, target);

    if( sk + me->query_skill("special", 1)/2 < random(250) ) {
        tell_object(target, HIG"上帝不屑地給了你左右臉各一巴掌，將你打醒了！\n\n");
    } else {
        tell_object(target, HIG"你忽然感受到上帝的恩寵，全身上下充滿了活力！！\n\n");
        target->heal_stat("ap", 9999);
        target->heal_stat("hp", 9999);
        target->heal_stat("mp", 9999);
    }

    cnd["name"] = HIW"(CD)聖療"NOR;
    cnd["duration"] = 300;

    me->set_condition("holy_hand_cond", cnd);
    me->damage_stat("mp", 50, me);
    me->improve_skill(SKILL_NAME, 1);
    me->start_busy(2);
    return 1;
}
