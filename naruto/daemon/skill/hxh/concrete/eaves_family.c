/* eaves family 屋簷下的一家人 
   具現系 rank 1 sk
   -tmr 20051117
   update by Acme 2007.03.16
   增加附加能力 by mouse 2007/7/25
   修正家人的攻擊模式 by mouse 2007/8/11
*/

#include <ansi.h>
#define SKILL_NAME   "eaves family"
#define SKILL_NAME_C "屋簷下的一家人"
#define SKILL_CLASS  "concrete"
#define SHADOW_NUM   4

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

// 防禦技巧影響
int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/40;
}

// 迴避能力影響
int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// 創造分身函式
void construct_shadow(object me)
{
    int i, count;
    object shadow;
    mapping map;

    if( me->query_skill("concrete", 1) < 20 ) {
        write("你的能力不足以使用這個技能。\n");
        return;
    }
    
    if( me->query_skill(SKILL_NAME, 1) < 50 ) {
        write("你的技能等級不足，每多五十級可多具現一個家人。\n");
        return;
    }

    // 擁有者消秏一些查克拉
    if( me->query_stat("mp") < 20 ) {
        write("你的念力不足。\n");
        return;
    }

    map = me->query_temp("FAMILY");
    count = sizeof(map);
    
    // 尋找可用編號 count
    if( count ) {
        count = 0;
        for(i=0;i<SHADOW_NUM;i++)
            if( objectp(map["FAMILY"+i]) ) count++;
    }

    if( count >= me->query_skill(SKILL_NAME, 1)/50 ) {
        write("你目前無法再具現多餘的家人。\n");
        return;
    }
    
    shadow = new(__DIR__"obj/family_obj.c");
    if( !objectp(shadow) ) {
        write("你似乎無法具現成功...\n");
        destruct(shadow);
        return;
    }

    message_vision("$N身上的念力開始運轉，慢慢地在旁邊凝聚成一個人形！！\n", me);
    me->damage_stat("mp", 20, me);
    me->start_busy(3);

    if( environment(me)->is_area() ) {
        if( !area_move(environment(me), shadow, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) {
            write("你的家人出來後，又消失不見了...\n");
            destruct(shadow);
            return;
        }
    } else {
        if( !shadow->move(environment(me)) ) {
            write("你的家人出來後，又消失不見了...\n");
            destruct(shadow);
            return;
        }
    }

    // 設定名稱, ID
    switch( random(4) ) {
            case 0: shadow->set_name(me->query("name") + "的姐姐", ({ me->query_id() + "'s family",  "family" })); break;
            case 1: shadow->set_name(me->query("name") + "的妹妹", ({ me->query_id() + "'s family",  "family" })); break;
            case 2: shadow->set_name(me->query("name") + "的哥哥", ({ me->query_id() + "'s family",  "family" })); break;
            case 3: shadow->set_name(me->query("name") + "的弟弟", ({ me->query_id() + "'s family",  "family" })); break;
    }

    // 相同等級
    shadow->set("level", me->query_level());

    // 相同屬性
    shadow->set_attr("str", me->query_attr("str"));
    shadow->set_attr("con", me->query_attr("con"));
    shadow->set_attr("int", me->query_attr("int"));
    shadow->set_attr("dex", me->query_attr("dex"));

    // 相同狀態
    shadow->set_stat_current("ap", me->query_stat_maximum("ap"));
    shadow->set_stat_maximum("ap", me->query_stat_maximum("ap"));
    shadow->set_stat_current("hp", me->query_stat_maximum("hp"));
    shadow->set_stat_maximum("hp", me->query_stat_maximum("hp"));
    shadow->set_stat_current("mp", me->query_stat_maximum("mp"));
    shadow->set_stat_maximum("mp", me->query_stat_maximum("mp"));

    // 戰鬥設定，具現化程度小於 100 前家人不會攻擊
    if( me->query_skill("concrete") < 100 ) shadow->set("no_combat", 1); // 不能攻擊
    shadow->set("no_defend", 1); // 不能防禦
    shadow->set("no_evade", 1);  // 不能迴避

    shadow->set_leader(me);     //跟隨leader
    shadow->set_owner(me);      //設定owner

    shadow->set("skill", SKILL_NAME);

    me->set_temp("FAMILY/FAMILY"+count, shadow);
    
    // 增加技能經驗
    me->improve_skill(SKILL_NAME, 1);

    shadow->guard_ob(me);       //保護leader
    return;
}

// 刪除分身函式
void destruct_shadow(object me)
{
    object shadow, *obs;


    if( !me->query_temp("FAMILY") ) {
        write("你目前沒有任何的家人存在。\n");
        return;
    }
    if( sizeof(obs = values(me->query_temp("FAMILY"))) <= 0 ) {
        write("你目前沒有任何的家人存在。\n");
        return;
    }
    foreach(shadow in obs)
    if( objectp(shadow) ) shadow->do_destruct();
    me->delete_temp("shadow");

    write("你具現出來的所有家人都消失了。\n");

    return;
}

// 使用絕招
int perform_action(object me, string act, object target)
{
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("你現在沒有空使用。\n");

    switch( act ) {
        case "family": construct_shadow(me); break;
        case "destruct": destruct_shadow(me);  break;
        default: return notify_fail("目前屋簷下的一家人有 family, destruct 兩種功\能。\n"); break;
    }
    return 1;
}
