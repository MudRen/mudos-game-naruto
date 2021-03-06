// finger-guessing fist 邪拳
// Tmr 2005/10/22
// update by Acme 2007.03.16
// 改變特攻方式 by mouse 2007/7/25

#include <ansi.h>
#define SKILL_NAME "finger-guessing fist"
#define SKILL_NAME_C "邪拳"
#define SKILL_CLASS "psychical"
#define SKILL_BASE "combat"

inherit SKILL;

// 要求 DEMON_D 登錄技能
void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

// 技能種類
string query_class() { return SKILL_CLASS; }

// 要 enable 才會有作用
int valid_enable(string base_skill) { return base_skill == SKILL_BASE; }

// 技能升級後會呼叫的函式，通常用來設定升下一級所需的經驗
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

// 致命一擊影響
int sock(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

// 取得傷害
int getDamage(object me, object target, int raiseDamage)
{
    int damage;
    object wp;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

int autoCasting(object me, object target, object weapon)
{
    int hit, damage, sk, i, j;
    string act, msg, fk;

    // 沒有enable不會啟動
    if( me->skill_mapped(SKILL_BASE) != SKILL_NAME ) return 1;
    
    sk = me->query_skill(SKILL_NAME);
    j = me->query_temp("GUESSING_FIST", 1);

    // 判斷是否啟動
    if( sk < 20 ) return 1;
    if( sk < 80 ) {                          // 20~80 級 10%
        if( random(sk) < sk*9/10 ) return 1;
    } else if( sk < 150 ) {                  // 81~150 級 20%
        if( random(sk) < sk*8/10 ) return 1;
    } else {                                 // 151~200 級 30%
        if( random(sk) < sk*7/10 ) return 1;
    }
    if( me->query_stat("ap") < 100 ) return 1;

    // 沒有命中，就不需再往下處理了
    if( !COMBAT_D->isHit(me, target) ) return 1;

    switch( j ) {
        case 1: act = HIY"剪刀"NOR;
                damage = me->query_skill("variation")/2 + me->query_skill("concrete")/2 + sk;
                msg = "$N擺\出"+act+"的姿勢，念刀劃傷了$n的肩膀造成傷害...(%d) %s\n\n";
                i = random(3) + 1;
                break;
        case 2: act = HIY"石頭"NOR;
                damage = me->query_skill("strength") + sk;
                msg = "$N蹲著馬步用力灌注念力，"+act+"打的$n鼻青臉腫...(%d) %s\n\n";
                i = random(3) + 1;
                break;
        case 3: act = HIY"布"NOR;
                damage = me->query_skill("emit")/2 + me->query_skill("operation")/2 + sk;
                msg = "$N右手握住左腕，左手一張"+act+"，放出念彈將$n轟個老遠...(%d) %s\n\n";
                i = random(3) + 1;
                break;
        default: write(HIY"你沒有決定要出什麼拳，所以決定不猜拳了。"NOR"\n");
                 return 1;
                 break;
    }
    switch( i ) {
        case 1: fk = "剪刀"; break;
        case 2: fk = "石頭"; break;
        case 3: fk = "布"; break;
        default: write(target->query("name")+"似乎不想玩猜拳，你只好停止猜拳了。"NOR"\n");
                 return 1;
                 break;
    }
    me->damage_stat("ap", 10, me);
    message_vision("\n$N大聲說道："HIG"喝！猜拳！！剪刀、石頭...布！\n"NOR, me, target);
    message_vision("$N快速的收起武器比出"HIY+act+NOR"！$n也同時比出"HIR+fk+NOR"！\n\n", me, target);

    if( act == HIY"剪刀"NOR && fk == "布" ) {
        message_vision(HIW"$N"HIW"猜拳猜贏了！立刻趁機發動攻擊！\n"NOR, me, target);
        damage = getDamage(me, target, damage);
        damage = COMBAT_D->receive_damage(target, me, damage);
        target->receive_damage(damage, me);
        message_vision(sprintf(msg, damage, COMBAT_D->report_status(target) ) ,me, target);
        me->improve_skill(SKILL_NAME, 1);
        return 1;
    }
    if( (act == HIY"布"NOR && fk == "剪刀") || i > j ) {
        damage = getDamage(target, me, 0);
        damage = COMBAT_D->receive_damage(me, target, damage);
        me->receive_damage(damage, target);
        message_vision("$n邪惡的笑著說道："HIG"是$N"HIG"輸了！吃我一記攻擊...\n"NOR, me, target);
        message_vision(sprintf("$n用力揮出一擊將$N打的東倒西歪...(%d) %s\n\n", damage, COMBAT_D->report_status(me) ) ,me, target);
    } else if( i < j ) {
        message_vision(HIW"$N"HIW"猜拳猜贏了！立刻趁機發動攻擊！\n"NOR, me, target);
        damage = getDamage(me, target, damage);
        damage = COMBAT_D->receive_damage(target, me, damage);
        target->receive_damage(damage, me);
        message_vision(sprintf(msg, damage, COMBAT_D->report_status(target) ) ,me, target);
        me->improve_skill(SKILL_NAME, 1);
    } else if( i == j ) {
        message_vision(HIW"結果雙方居然出一樣的拳...平手。\n\n"NOR, me, target);
    } else {
        message_vision("但是判斷出問題啦！快找巫師處理吧！\n"NOR, me, target);
    }
    return 1;
}

string *combat_actions = ({
    "$N握緊右拳，使出「石頭」狠狠搥向$n的$l",
    "$N伸出食、中兩指，使出「剪刀」硬是戳向$n的$l",
    "$N使出「布」狠狠一巴掌摑向$n的臉頰",
    "$N接連兩手都比出「布」的手勢，隨即左右開弓的摑了$n兩巴掌",
    "$N原本是「石頭」手勢忽然變成了「剪刀」，從另一個方位戳向$n的$l",
    "$N原本是「布」手勢忽然變成了「石頭」，接著狠狠一拳擊向$n的$l",
});

string *combat_wp = ({
    "$N用手中的$w往$n$l揮去",
    "$N揮動$w，往$n$l打去",
    "$N將手中$w對準$n$l揮去",
    "$N揮動手中$w，攻向$n$l",
    "$N尋著空隙，一個箭步上前手中$w便往$n$l擊落",
});

// 預設的攻擊訊息是由系統提供，若是 enable 在 combat 的技能的話
// 必需建立這個函式提供攻擊訊息
string getCombatAction(object me, object weapon)
{
    string skill = me->skill_mapped("combat");

    me->improve_skill(SKILL_NAME, 1);
    if( weapon->is_weapon() ) return combat_actions[random(sizeof(combat_wp))];
    else return combat_actions[random(sizeof(combat_actions))];
}

// 使用絕招
int perform_action(object me, string act, object target)
{
    string msg;
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("你現在沒有空使用。\n");

    switch( act ) {
        case "剪刀": me->set_temp("GUESSING_FIST", 1);
                     msg = "$N經過仔細的思考，決定下次猜拳都出"HIY+act+NOR"。\n";
                     break;
        case "石頭": me->set_temp("GUESSING_FIST", 2);
                     msg = "$N經過仔細的思考，決定下次猜拳都出"HIY+act+NOR"。\n";
                     break;
        case "布": me->set_temp("GUESSING_FIST", 3);
                   msg = "$N經過仔細的思考，決定下次猜拳都出"HIY+act+NOR"。\n";
                   break;
        case "none": me->delete_temp("GUESSING_FIST");
                     msg = "$N覺得自己的技巧太差，還是不猜拳了\n";
                     break;
        default: return notify_fail("你必須指定要出什麼拳。\n(perform finger-guessing fist.<剪刀|石頭|布>)\n"); break;
    }
    message_vision(msg, me);
    return 1;
}
