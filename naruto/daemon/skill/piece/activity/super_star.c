#include <ansi.h>
#define SKILL_NAME "super star"
#define SKILL_NAME_C "必殺"
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

int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*27/100;
}

// 計算是否命中
int isHit(object me, object target, int sk)
{
    int hit, meHit, targetHit;

    if( sk < 80 ) meHit = 0;
    else {
        meHit = me->query_ability("intimidate");
        if( sk > 150 ) {
            meHit += me->query_skill(SKILL_NAME, 1);
        }
    }
    targetHit = target->query_ability("wittiness");

    me->add_temp("apply/exact", meHit);
    target->add_temp("apply/evade", targetHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -meHit);
    target->add_temp("apply/evade", -targetHit);

    return hit;
}

// 超定人技，判斷
int check_busy(object me, object target, int sk)
{
    if( sk < 61 ) target->start_busy(1);
    else if( sk < 101 ) target->start_busy(2);
    else if( sk < 141 ) target->start_busy(3);
    else if( sk < 181 ) target->start_busy(4);
    else if( sk < 200 ) target->start_busy(5);
    else target->start_busy(6);
}

int autoCasting(object me, object target, object weapon)
{
    string *msg = ({ "裁縫針深深的插入指甲肉裡...",
                     "紙劃破了手指的關節...",
                     "全身的傷口爬滿了搶吃糖漿的螞蟻...",
                     "鼻孔裡爬進了一隻毛毛蟲在蠕動...",
                     "肚臍流出了恐怖又噁心的濃....",
                     "舌頭突然伸長舔的自己滿臉口水...",
                     "不小心踩破自己的眼珠...流了滿地的液體...",
                  });

    string msgin, msgout;
    int sk, check;

    sk = me->query_skill(SKILL_NAME, 1);

    // 判斷是否啟動
    if( target->is_busy() ) return 1;
    if( me->query_stat("mp") < sk/4 ) return 1;
    if( me->query_skill("activity", 1) < 200 ) return 1;
    if( sk < 50 ) return 1;

    if( sk < 80 ) {                          // 20~80 級 10%
        if( random(sk) < sk*9/10 ) return 1;
    } else if( sk < 150 ) {                  // 81~150 級 15%
        if( random(sk) < sk*17/20 ) return 1;
    } else {                                 // 151~200 級 20%
        if( random(sk) < sk*8/10 ) return 1;
    }
    // 判斷敘述用
    if( sk > 150 ) check = 3;
    else if( sk > 80 ) check = 2;
    else check = 1;

    // 敘述統一寫在這裡，減少程式
    switch( check ) {
        case 1:
            msgin = "$N忽然露出非常慎重的表情大喊："HIW"『"HIY+me->query("name")+"橡皮筋"HIW"』"NOR"！\n";
            msgout = "$n嚇的緊閉雙眼，心裡不停的禱告千萬不要被打中。\n";
            break;
        case 2:
            msgin = "$N拿出一塊黑板，用力的用指甲刮出惱人的"HIC"『"HIM"噪音"HIC"』"NOR"，連自己都快受不了了...\n"NOR;
            msgout = "$n似乎受不了這陣噪音，雙手蓋\著耳朵完全放棄攻擊。\n";
            break;
        case 3:
            msgin = "$N站在高台上使出"HIM"『"HIB+BLINK+me->query("name")+"咒文"NOR+HIM"』"NOR"，大喊：" + msg[random(sizeof(msg))] + "\n";
            msgout = "$n痛苦的倒在地上，臉部表情十分難看，似乎受到了什麼精神攻擊！\n";
            break;
        default: return notify_fail("判斷有問題喔。\n"); break;
    }
    message_vision(msgin, me, target);
    if( !isHit(me, target, sk) ) {
        message_vision("但是$n無聊的挖著鼻孔，完全不知道$N在幹啥。\n", me, target);
        me->damage_stat("mp", sk/8, me);
    } else {
        message_vision(msgout, me, target);
        check_busy(me, target, sk);
        me->damage_stat("mp", sk/4, me);
    }
    me->improve_skill(SKILL_NAME, 1);
    return 1;
}