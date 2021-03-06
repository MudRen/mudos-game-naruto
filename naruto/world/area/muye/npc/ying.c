#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;         // 訓練忍者

void do_fight()
{
    mapping buff, cnd_data;
    string cnd;
    object enemy;
    int damage, raiseDamage, exact, evade;

    // 沒有敵人
    enemy = this_object()->query_opponent();
    buff = query_all_conditions();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( random(4) ) {
        case 0:  // 細胞活化
            if( !query_condition("ca2") ) {
                command("perform cell activation.ca");
                break;
            }
        case 1:  // 治癒術
            if( !query_condition("heal_buff") ) {
                command("perform heal buff.heal");
                break;
            }
        case 2:  // 怪力
            exact = COMBAT_D->exact(this_object(), enemy, 1) + COMBAT_D->wittiness(this_object(), 1);
            evade = COMBAT_D->evade(enemy, this_object(), 1) + COMBAT_D->intimidate(enemy, 1);

            message_vision(HIM"\n$N運用醫療忍術控制查克拉的技巧，將所有力量集中在拳端"HIW"『怪力』"HIM"一拳朝$n"HIM"砸去！\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("$n滿臉驚恐地看著一旁被$N擊中的巨大岩石碎塊，慶幸還好沒打中。\n\n"NOR, this_object(), enemy);
                start_busy(5);
            } else {
                raiseDamage = 1200;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 600 ) damage = random(100) + 500;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("在攻擊擊中$N的同時，強大的查克拉從體內爆開，造成非常嚴重的創傷(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                start_busy(3);
            }
            break;
        case 3:  // buff 解除
            if( !buff ) break;
            message_vision(HIG"\n$N左手凝聚出綠色的查克拉，開始檢查自己身體有無異常症狀...\n"NOR, this_object());
            foreach(cnd, cnd_data in buff) {
                if( cnd != "ca" && cnd != "ca2" && cnd != "heal_buff" ) {
                    message_vision("$N在戰鬥中瞬間調出解藥，解除了 "+cnd_data["name"]+" 的不良狀態。\n"NOR, this_object());
                    delete_condition(cnd);
                    set_temp("delete_buff", 1);
                }
            }
            if( !query_temp("delete_buff") ) message_vision(CYN"$N並無發現身上有任何狀況。\n\n"NOR, this_object());
            else {
                message_vision(CYN"$N將身體不良狀態都去除了。\n\n"NOR, this_object());
                delete_temp("delete_buff");
            }
            break;
    }
    return;
}

void to_do_say()
{
    if( query_stat("hp") < query_stat_maximum("hp") && !query_condition("ca2") ) command("perform cell activation.ca");
    else if ( !query_condition("heal_buff") ) command("perform heal buff.heal");

    do_heal();
    return;
}

void create()
{
    set_name("春野櫻", ({ "ying" }));
    set_race("human");
    set_level(50);
    set("gender", "female");
    set_class("middle");            // 中忍
    set("classify", "strengthen");  // 強化
    set("camp", "muye");
    set("long", "其潛藏的能力連卡卡西也認同。在查克拉的調節、幻術才能、中忍\n"
                "考試時的記憶力等各方面，都顯露出才華，將來的能力可能不在佐\n"
                "助之下。\n");

    set("age", 16);

    set("chat_chance", 10);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("guild", "muye");
    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 140, "muye", -2);              // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 120, "muye", -2);               // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 120, "muye", -2);               // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 120, "muye", -2);           // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 180, "muye", -2);          // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 120, "muye", -2);       // 連擊之術
    set_train_with_camp("ninja", 1, 10, 160, "muye", -2);              // 忍術
    set_train_with_camp("cell activation", 0, 15, 160, "muye", -1);    // 忍術：細胞活化
    set_train_with_camp("heal buff", 0, 20, 120, "muye", 0);           // 忍術：治癒術
    set_train_with_camp("hand heal", 1, 21, 140, "muye", 0);           // 忍術：掌仙術

    setup();
    set_skill("combat", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 140);
    set_skill("ninja", 180);
    set_skill("cell activation", 200);
    set_skill("heal buff", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");

    add_temp("apply/attack", 150);      // 攻擊能力
    add_temp("apply/wittiness", 150);   // 防禦能力
    add_temp("apply/exact", 150);       // 命中能力
    add_temp("apply/int", 30);
}

void die()
{
    object enemy, killer;
    int i = 25 + random(6);
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
    msg = HIM"\n綱手老師...卡卡西老師...佐助...鳴人...\n\n雖然平凡的我想追上別人的腳步...但盡頭似乎已經到了...\n\n"NOR;
    msg += HIG"【"HIR"木葉快訊"HIG"】"HIG"第五代火影綱手的醫療忍者弟子"+this_object()->query("name")+"，被殘忍的"+enemy->query("name")+"給殺死了。\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死"+this_object()->query("name")+"獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}
