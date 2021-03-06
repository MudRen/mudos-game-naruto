#include <ansi.h>
#define SKILL_NAME "almighty creation"
#define SKILL_NAME_C "無限的劍製"
#define SKILL_CLASS "concrete"

inherit SKILL;

string *name = ({ HIW"隼之劍"NOR, HIR"屠龍劍"NOR, HIW"維京"NOR"巨劍",
                  HIY"威廉華萊士之劍"NOR, HIK"終結者"NOR, HIC"佐羅"HIW"之劍"NOR,
                  HIW"塞得雙刃劍"NOR, YEL"獅心王"HIC"查理之劍"NOR, "鋼鐵勇士",
                  HIK"黑暗之劍"NOR, HIY"凱撒之劍"NOR, HIG"羅賓漢之劍"NOR,
                  HIM"共濟"NOR"之劍", HIW"騎士長劍"NOR, HIK"黑王子"HIW"愛德華之劍"NOR,
                  YEL"古埃及"HIY"神劍"NOR, HIW"圓桌武士"NOR, RED"魔鬼"HIK"撒旦"NOR,
                  "蒙羅托克-"RED"殺戮之劍"NOR, "巴士達劍", YEL"獅中劍"NOR,
                  "瑪爾羅斯-"HIK"黑暗之劍"NOR, HIW"守護"HIM"王者之劍"NOR, "由龍劍",
                  "石中劍", HIW"白銀"NOR"騎士劍", HIK"黑武士之劍"NOR, });

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

// 取得傷害
int getDamage(object me, object target, int sk, object sword)
{
    string msg = "";
    int damage, num, count = 0, *arr = allocate(10);

    message_vision("\n$N舉起"+sword->query("name")+"當作媒介，對$n發動固有結界"HIY"『"HIW+BLINK"王之財寶"NOR+HIY"』\n\n"NOR, me, target);

    num = sk/40 + random(3);

    while(count < num) {
        arr[count] = random(27);
        if( member_array(arr[count], arr) == count) {
            if(count == num - 1) msg += name[arr[count]];
            else msg += name[arr[count]] + "、";
            count++;
        }
    }
    // 召來的劍數量對攻擊有影響
    damage = sk*(num+1) + me->query_skill("concrete")*2;
    message_vision("只見"+msg+"等劍受到"+sword->query("name")+"召集來到四周\n"NOR, target);

    return damage;
}

// 計算是否命中
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1) + COMBAT_D->wittiness(target, 1)/2;
    j = COMBAT_D->intimidate(target, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// 技能使用後 
void setEffect(object me, int sk, object sword)
{
    mapping cnd = ([]);

    me->damage_stat("mp", 20, me);
    me->improve_skill(SKILL_NAME, 1);
    destruct(sword);

    cnd["name"] = HIY"(CD)財寶"NOR;
    cnd["duration"] = 60;

    me->set_condition("diabo_busy", cnd);
}

void do_destruct(object me)
{
    object sword;

    // 有劍會把舊劍刪去
    if( objectp(sword = present("_CREATION_SWORD_", me)) ) {
        message_vision("\n$N將劍的念力收回，"+sword->query("name")+"瞬間消失了。\n\n"NOR, me);
        destruct(sword);
    } else {
        write("你身上根本沒有投影劍。\n");
        return;
    }
    return;
}

// 創造武器
void do_perform(object me)
{
    string msg;
    int sk, concrete, i, j;
    object shadow, sword;

    sk = me->query_skill(SKILL_NAME, 1);
    concrete = me->query_skill("concrete", 1);

    if( concrete < 60 ) {
        write("你的具現化程度不足以使用投影。\n");
        return;
    }
    if( sk < 30 ) {
        write("你的技能等級不足以使用投影。\n");
        return;
    }
    // 擁有者消秏一些念力
    if( me->query_stat("mp") < 200 ) {
        write("你的念力不足。\n");
        return;
    }
    if( me->is_busy() ) {
        write("你暫時無法集中精神使用投影。\n");
        return;
    }
    // 先偵測身上是否已經有劍了, 有劍會把舊劍刪去
    if( objectp(sword = present("_CREATION_SWORD_", me)) ) {
        message_vision("\n$N將劍的念力收回，"+sword->query("name")+"瞬間消失了。\n\n"NOR, me);
        destruct(sword);
    }
    shadow = new(__DIR__"obj/sword_obj.c");

    if( !objectp(shadow) ) {
        write("你似乎無法具現成功...\n");
        destruct(shadow);
        return;
    }
    message_vision("$N閉上雙眼緩緩唸道："HIG"投影•開始...構造解明...\n"NOR, me);
    if( !shadow->move(me) ) {
        write("你的身上太重了，無法再拿動更多的武器\n");
        destruct(shadow);
        return;
    }

    i = random(4);
    j = random(4);

    shadow->set_name(name[random(sizeof(name))], ({ "famed sword", "sword", "_CREATION_SWORD_" }));
    shadow->setup_weapon(sk/3+concrete/6+random(5), sk/2+concrete/4+random(10), 100, 1);
    shadow->set("long", "經由投影所具現出來的名劍，是否擁有實際能力則不得而知。\n" );

    switch( i ) {
        case 0: shadow->set("apply_weapon/righthand/attack", sk/10); break;
        case 1: shadow->set("apply_weapon/righthand/armor", sk/10); break;
        case 2: shadow->set("apply_weapon/righthand/intimidate", sk/10); break;
        case 3: shadow->set("apply_weapon/righthand/wittiness", sk/10); break;
    }
    while( j == i ) {
        j = random(4);
    }
    switch( j ) {
        case 0: shadow->set("apply_weapon/righthand/attack", sk/20); break;
        case 1: shadow->set("apply_weapon/righthand/armor", sk/20); break;
        case 2: shadow->set("apply_weapon/righthand/intimidate", sk/20); break;
        case 3: shadow->set("apply_weapon/righthand/wittiness", sk/20); break;
    }
    switch( i + j ) {
        case 0: msg = "判斷錯誤，請找巫師處理"; break;
        case 1: msg = ""HIM"均衡之源"; break;
        case 2: msg = ""RED"兇暴之源"; break;
        case 3: if( i == 0 || i == 3 ) msg = ""HIC"穩重之源";
                else msg = ""HIG"高超之源";
                break;
        case 4: msg = ""BLU"沉著之源"; break;
        case 5: msg = ""HIB"堅忍之源"; break;
    }
    if( random(2) == 1 ) shadow->set("apply_weapon/righthand/hp", random(sk));
    else shadow->set("apply_weapon/righthand/ap", random(sk));
    shadow->wield("righthand");
    message_vision(HIW"只見一把附有"+msg+HIW"的"NOR+shadow->query("name")+HIW"在$N手中逐漸成形，最後終於盡乎完美的實體化了。\n"NOR, me);
    me->damage_stat("mp", 200, me);

    // 在戰鬥中製劍會 busy 的比較久
    if( me->is_fighting() ) {
        write("你在戰鬥中分心使用投影，一時間無法反應！\n");
        me->start_busy(6);
    } else me->start_busy(3);

    me->set_temp("CREATION_SWORD", shadow);

    // 增加技能經驗
    me->improve_skill(SKILL_NAME, 1);

    return;
}

// 使用絕招
int perform_action(object me, string act, object target)
{
    string skill;
    int damage, raiseDamage, sk, hit;
    object sword;
    mapping weapons;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("你現在沒有空使用。\n");

    if( act != "rain" ) {
        switch( act ) {
            case "gz": do_perform(me); return 1; break;
            case "destruct": do_destruct(me); return 1; break;
            default: return notify_fail("目前"+SKILL_NAME_C+"有 gz, rain, destruct 三種功\能。\n"); break;
        }
    }
    if( !objectp(me) || !objectp(target) ) return notify_fail("目前"+SKILL_NAME_C+"有 gz, rain, destruct 三種功\能。\n");

    if( !me->is_fighting(target) )
        return notify_fail("戰鬥都停止了還想做什麼。\n");

    // 借用惡魔風腳冷卻時間
    if( me->query_condition("diabo_busy", 1) != 0)
        return notify_fail("你必須經過一段時間後才能使用王之財寶。\n");

    // 偵測使用者 mp 夠不夠使用
    if( me->query_stat("mp") < 100 )
        return notify_fail("你的念力不足以使用王之財寶。\n");

    // 偵測有沒有製劍
    if( !objectp(sword = present("_CREATION_SWORD_", me)) )
        return notify_fail("想使用王之財寶必須先有媒介。\n");

    // 劍要先拿下來，不然附加能力會保留
    if( mapp(weapons = me->query_temp("weapon")) && sizeof(weapons) )
        foreach(skill, sword in weapons) sword->unequip();

    // 是否命中
    hit = isHit(me, target);

    // 計算傷害，為顯示召劍訊息所以擺在外面
    raiseDamage = getDamage(me, target, sk, sword);

    if( hit ) {
        me->add_temp("apply/attack", raiseDamage);
        damage = COMBAT_D->isDamage(me, target, sword);
        me->add_temp("apply/attack", -raiseDamage);

        target->receive_damage(damage, me);
        message_vision( sprintf(HIR"接連不斷的劍雨不停撒向"NOR"$n"HIR"，將"NOR"$n"HIR"刺成了一個血窟窿！(%d) %s\n\n", damage, COMBAT_D->report_status(target)), me, target);
        me->start_busy(1);
        target->start_busy(2);
    } else {
        message_vision("但是$N不慌不忙地發現了攻擊的破綻，化解了此招。\n\n"NOR, target);
        me->start_busy(2);
    }
    setEffect(me, sk, sword);
    return 1;
}
