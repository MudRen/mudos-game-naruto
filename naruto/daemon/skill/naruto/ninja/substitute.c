/* 忍術：替身術(substitute) */

#include <ansi.h>
#define SKILL_NAME "substitute"
#define SKILL_NAME_C "替身術"
#define SKILL_CLASS "ninja"

inherit SKILL;

void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

string query_class() { return SKILL_CLASS; }

// 要 enable 才會有作用
int valid_enable(string base_skill) { return base_skill == "dodge"; }

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

string *defend_message = ({
    HIW"只聽見「碰」的一聲，原來$n攻擊的是一塊大木頭。\n"NOR,
    HIW"剎那間$N的身體變成了一塊大木頭。\n"NOR,
    HIW"一陣輕煙過去，原來$n攻擊的是一塊大木頭。\n"NOR,
});

string *dodge_msg = ({
    "但是和$p$l偏了幾寸",
    "但是被$p機靈地躲開了",
    "但是$n身子一側，閃了開去",
    "但是被$p及時避開",
    "但是$n已有準備，不慌不忙的躲開",
    "但是沒中",
});

string *dodge_enable = ({
    "但是$N擊中的只是$n的幻影",
    "噗地一聲，$N打中了眼前的木頭",
    "但$n身影忽然消失，原來只是假替身",
    "$N痛的哇哇叫，居然打到了一尊地藏王菩薩",
    "結果一隻貍貓像從空中掉下來砸中$N的頭",
    "四周羽毛亂飛，原來$N打中不知哪來的枕頭",
});

// target 受到傷害前，讓技能先跑過 receive_damage 
// 如何便可以製作 "暫時無敵技" 或是 "傷害吸收盾" 之類的技能
int receiveDamage(object me, object target, int damage)
{
    int ratio;
    string msg;
    if( me->query_skill(SKILL_NAME) < 20 ) return damage;
    ratio = me->query_skill(SKILL_NAME)*10/200;
    
    // 練滿有 10% 的機會完全吸收傷害
    if( ratio < random(100) ) return damage;
    
    // 訊息
    msg = defend_message[random(sizeof(defend_message))];
    message_vision(msg, me, target);

    // 損失mp
    me->damage_stat("mp", random(damage/10) + 1, me);
    
    // 增加技能經驗
    me->improve_skill(SKILL_NAME, 1);
    
    return 0;
}

string getEvadeAction(object me)
{
    string skill = me->skill_mapped("dodge");

    // 沒有 enable 任何技能
    if( !skill || skill == "dodge" )
        return dodge_msg[random(sizeof(dodge_msg))];
    else return dodge_enable[random(sizeof(dodge_enable))];
}
