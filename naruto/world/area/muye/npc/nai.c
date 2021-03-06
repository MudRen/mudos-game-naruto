#include <npc.h>
#include <ansi.h>

void do_fight()
{
    mapping cnd = ([]);
    object target, bug;
    object *enemy;
    int damage, raiseDamage, ntar, i, j, check;

    this_object()->charge_ob(query_temp("charge_ob"));

    // 沒有敵人
    target = this_object()->query_charging();
    enemy = this_object()->query_enemy();
    ntar = sizeof(enemy);

    if( !target ) target = this_object()->query_opponent();
    if( !target ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), target) ) return;
    } else {
        if( environment(target) != environment(this_object()) ) return;
    }
    if( query_condition("fang_cd") ) return;
    if( query_stat_current("hp") < query_stat_maximum("hp")/2 ) check = random(6);
    else check = random(3);

    cnd["name"] = HIK+"(CD)蟲術"+NOR;

    switch( check ) {
        case 0:  // 蟲柱之術 (一般攻擊)
            command("say 去吧，蟲子們！");
            message_vision(HIK"\n$N舉起雙手施展"NOR"『"GRN"蟲柱之術"NOR"』"HIK"從袖口射出兩條黑色巨柱衝向$n！\n"NOR, this_object(), target);
            if( !COMBAT_D->isHit(this_object(), target) ) {
                message_vision("結果$n驚險閃過攻擊，卻發現巨柱撞在樹上居然是一大堆的黑色小蟲...\n\n"NOR, this_object(), target);
            } else {
                raiseDamage = 800;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), target, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 300 ) damage = 250 + random(51);

                target->receive_damage(damage, this_object());
                message_vision( sprintf("巨柱撞擊在$n身上造成傷害，隨後柱端居然擴散開來"HIK"『寄壞蟲』"NOR"爬滿$n全身！(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), this_object(), target);
                target->query_temp("add_bug", 1);
            }
            cnd["duration"] = 3;
            this_object()->set_condition("fang_cd", cnd);
            break;
        case 1:  // 蟲壁之術 (擋路不給逃)
            if( target->query_temp("bug_exit") ) break;
            command("say 想要除掉寄壞蟲，只能將牠們拔(rid)掉。");
            message_vision(HIK"\n$N右手揮袖施展"NOR"『"HIM"蟲壁之術"NOR"』"HIK"門口居然被一堆黑色小蟲堵住，無路可逃了！\n\n"NOR, this_object());
            for(i=0;i<ntar;i++) {
                enemy[i]->set_temp("bug_exit", 1);
            }
            bug = new(__DIR__"bug.c");
            bug->move(environment(this_object()));
            break;
        case 2:  // 蟲縛之術 (busy)
            command("say 寄壞蟲可是攻守一體的技巧，"+target->query("name")+"已經被我前後包圍了。");
            message_vision(HIK"\n$N向後一跳，運用查克拉控制對手身上寄生的寄壞蟲"NOR"『"HIB"蟲縛之術"NOR"』"HIK"利用蟲子防礙行動！\n"NOR, this_object());
            for(i=0;i<ntar;i++) {
                if( enemy[i]->is_busy() ) continue;
                if( bug = present("_GI_BUG_", enemy[i]) ) {
                    message_vision(HIC"$N"HIC"被爬滿全身的寄壞蟲纏住無法動彈！\n"NOR, enemy[i]);
                    j = bug->query_amount()/20;
                    if( j < 0 ) j = 1;
                    if( j > 5 ) j = 5;
                    enemy[i]->start_busy(j);
                } else {
                    message_vision("$N身上沒有寄壞蟲，因此不受到影響。\n"NOR, enemy[i]);
                }
            }
            message_vision("\n"NOR, this_object());
            cnd["duration"] = 10;
            this_object()->set_condition("fang_cd", cnd);
            break;
        default: // 寄壞蟲•蝕 (破壞寵物)
            if( ntar <= 0 ) break;
            command("say 有點實力...這樣的話...");
            message_vision(HIK"\n$N看狀況差不多了，施展出"HIW"『"BLINK+NOR"寄壞蟲"HIK"•"HIR"蝕"NOR+HIW"』"HIK"利用寄壞蟲咬斷控制分身的魔力線！\n"NOR, this_object());
            bug = new("/world/npc/disco.c");
            for(i=0;i<ntar;i++) {
                if( enemy[i]->query_owner() && present("_GI_BUG_", enemy[i]) ) {
                    message_vision("$N"HIC"因為所含能量被"HIK"寄壞蟲"NOR+HIC"消耗殆盡而像個斷線木偶一樣停止了...\n"NOR, enemy[i]);
                    remove_killer(enemy[i]);
                    enemy[i]->remove_killer(this_object());
                    enemy[i]->guard_ob(0);
                    if( !enemy[i]->query_food() ) enemy[i]->set_owner(bug);
                    set_temp("bug_ok", 1);
                    heal_stat("hp", query_stat_maximum("hp")/10);
                } else {
                    heal_stat("hp", query_stat_maximum("hp")/20);
                }
            }
            if( !query_temp("bug_ok") ) {
                message_vision(HIW"但是似乎沒有發生什麼事情。\n"NOR, this_object());
                heal_stat("hp", query_stat_maximum("hp")/8);
            }
            delete_temp("bug_ok");
            message_vision("\n"NOR, this_object());
            destruct(bug);
            break;
    }
    // 放完技能就要去掉，不然玩家絡跑會一直追
    this_object()->charge_ob(0);

    // 寄壞蟲是在 perform 使用完後偷偷放在身上的
    for(i=0;i<ntar;i++) {
        if( enemy[i]->query_temp("add_bug") ) j = 20+random(51);
        else j = random(6);
        if( bug = present("_GI_BUG_", enemy[i]) ) {
            bug->add_amount(j);
        } else {
            if( file_size(__DIR__"item/gi_bug.c") < 0 ) return;
            if( catch(bug = new(__DIR__"item/gi_bug.c")) ) return;
            if( !bug->move(enemy[i]) ) {
                destruct(bug);
            } else {
                bug->set_amount(j);
                bug->set_owner(enemy[i]);
                bug->set("changed", 1);
            }
        }
    }
    return;
}

void to_do_say()
{
    object bug;

    if( bug = present("_BUG_WALL_", environment(this_object())) ) {
        message_vision(CYN"結束戰鬥後，$N立刻將$n"CYN"收回了。\n"NOR, this_object(), bug);
        destruct(bug);
    }
    if( query_temp("charge_ob") ) delete_temp("charge_ob");
    do_heal();
    return;
}

void create()
{
    set_name("油女志乃", ({ "you ni zhi nai", "nai" }));
    set_race("human");
    set_level(55);
    set("camp", "muye");
    set_class("middle");            // 中忍
    set("classify", "strengthen");  // 強化
    set("age", 16);
    set("gender", "male");

    set("long", "沉默少言的他，戰鬥力絕對不弱，在中忍選拔試煉，與薩克鐙戰鬥中\n"
                "看到他那可怕的獨門戰法－－寄壞蟲，從而得知他乃蟲使一族的後人\n"
                "，與蟲族定下契約，提供查克拉給蟲，而蟲則幫助他戰鬥。\n");

    set("chat_chance", 30);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    set_skill("continual hit", 180);
    set_skill("heavy hit", 160);
    set_skill("ninja", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");

    add_temp("apply/exact", 250);        // 命中
    add_temp("apply/intimidate", 150);   // 攻擊技巧
    add_temp("apply/armor", 150);        // 防禦能力
    add_temp("apply/str", 5);
    add_temp("apply/con", 10);
    add_temp("apply/int", 15);
}

void die()
{
    object enemy, killer;
    int i = 15 + random(16);
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        destruct(this_object());  // 找不到對手，直接消失
        return;
    }
    // 寵物殺死算主人的
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = HIK"\n油女一族的秘術居然敗給了"+enemy->rank()+"？\n\n"HIW"這次的失敗我記住了，下次再向"+enemy->query("name")+"挑戰！\n\n"NOR;
    msg += HIG"【"HIR"木葉快訊"HIG"】"HIG"木之葉操使蟲的油女一族精英"+this_object()->query("name")+"，被強悍的"+enemy->query("name")+"給擊敗了。\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死"+this_object()->query("name")+"獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}

int accept_kill(object me, string arg)
{
    message_vision("$N說道："HIG+me->query("name")+"是吧？我已經鎖定$n了。\n"NOR, this_object(), me);
    set_temp("charge_ob", me);
}
