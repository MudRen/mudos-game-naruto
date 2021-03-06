#include <ansi.h>
#define SKILL_NAME "powerful thunderbolt"
#define SKILL_NAME_C "雷霆萬鈞"
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
        case 189: me->set_skill_require(skill, 1500000); break; // 關卡3 : 189升190
        case 149: me->set_skill_require(skill, 1000000); break; // 關卡2 : 149升150
        case  99: me->set_skill_require(skill, 500000);  break; // 關卡1 :  99升100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// 檢查是否能使用技能
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) {
        tell_object(me, "目前" + SKILL_NAME_C + "有 compo 和 jet 兩種功\能。\n");
        return 0;
    }

    if( act != "jet" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "有 compo 和 jet 兩種功\能。\n");
        return 0;
    }

    if( me->is_busy() ) {
        tell_object(me, "你現在沒有空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( !me->is_fighting() ) {
        tell_object(me, "戰鬥都停止了還想做什麼。\n");
        return 0;
    }

    if( !me->query_condition("thunderbolt", 1) ) {
        tell_object(me, "沒有黑雲怎麼放雷電。\n");
        return 0;
    }

    if( me->query_skill("activity", 1) < 160 || sk < 40 ) {
        tell_object(me, "你能力還不足夠使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/5 ) {
        tell_object(me, "你的狀態無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    return 1;
}

// 計算是否命中
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->exact(me, target, 1) + COMBAT_D->intimidate(me, 1);
    j = COMBAT_D->evade(target, me, 1)*2;

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// 取得傷害
int getDamage(object me, object target, int sk, object staff)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk*2 + me->query_skill("activity") + me->query_skill("anemometer");

    if( wp = me->query_temp("weapon/twohanded") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else if( wp = me->query_temp("weapon/righthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else if( wp = me->query_temp("weapon/lefthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else raiseDamage -= COMBAT_D->isDamage(me, target, 0)*3/4;

    raiseDamage += staff->query("damage/twohanded/upper");

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// 技能使用後 
void setEffect(object me, int sk)
{
    // 空行 msg
    message_vision("\n", me);
    me->start_busy(2);
    me->damage_stat("mp", sk/5, me);
    me->improve_skill(SKILL_NAME, 1);
    me->delete_condition("thunderbolt");
}

void do_perform(object me)
{
    int sk;
    object staff;

    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_stat("mp") < sk/40 ) {
        write("你的狀態無法使用" + SKILL_NAME_C + "。\n");
        return;
    }

    if( me->is_busy() ) {
        tell_object(me, "你暫時無法製造黑雲。\n");
        return 0;
    }

    if( sk < 10 ) {
        write("沒學會" + SKILL_NAME_C + "不會製造黑雲。\n");
        return;
    }

    if( me->query_condition("thunderbolt", 1) != 0) {
        write("雲已經產生了，再不發動攻擊雲可能會消失。\n");
        return;
    }

    if( !me->is_fighting() ) {
        write("沒事製造什麼黑雲。\n");
        return;
    }

    // 先偵測身上有沒有天候棒
    if( !objectp(staff = present("_WEATHER_", me)) ) {
        write("你身上沒有天候棒怎麼用技能。\n");
        return;
    }

    message_vision("$N"HIK"左右手分別轉動"+staff->query("name")+NOR+HIK"，在空中製造出濃密的黑雲...\n"NOR, me);

    cnd["name"] = HIK"烏雲密佈"NOR;
    cnd["duration"] = 10;

    me->start_busy(3);
    me->damage_stat("mp", sk/40, me);
    me->set_condition("thunderbolt", cnd);
    return;
}

int perform_action(object me, string act, object target)
{
    object staff, *targets;
    int damage, sk, i, number;

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();

    if( !objectp(me) ) return 0;

    if( act == "compo") {
        do_perform(me);
        return 1;
    }
    // 檢查是否能使用技能
    if( !isCast(me, act, target, sk) ) return 1;

    if( !objectp(staff = present("_WEATHER_", me)) ) return notify_fail("沒拿天候棒怎麼放雷電。\n");

    message_vision("\n$N將"HIY"電氣泡"NOR"丟向空中黑雲"HIK"『"HIY"雷霆萬鈞"HIK"』"NOR"雷電瘋狂亂擊在四周地上！\n"NOR, me);

    number = (sk/50) - 1;
    if( number <= 0 ) number = 0;

    if( me->query_skill("activity", 1) >= 70 ) {
        for(i=0;i<sizeof(targets);i++) {
            if( i > number ) break;   // 最多攻擊四人
            if( !isHit(me, targets[i]) ) {
                message_vision("$n運氣似乎不錯，閃電幾乎將地面燒盡，卻沒有擊中$n。\n", me, targets[i]);
            } else {
                damage = getDamage(me, targets[i], sk, staff);
                targets[i]->receive_damage(damage, me);
                message_vision( sprintf(HIY"$n"HIY"被電的哇哇大叫，彷彿能看見$n"HIY"的骨骼在閃爍(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
            }
        }
    } else {
        if( !isHit(me, target) ) {
            message_vision("$n運氣似乎不錯，閃電幾乎將地面燒盡，卻沒有擊中$n。\n", me, target);
        } else {
            damage = getDamage(me, target, sk, staff);
            target->receive_damage(damage, me);
            message_vision( sprintf(HIY"$n"HIY"被電的哇哇大叫，彷彿能看見$n"HIY"的骨骼在閃爍(%d) %s\n", damage, COMBAT_D->report_status(target)), me, target);
        }
    }
    setEffect(me, sk);
    return 1;
}
