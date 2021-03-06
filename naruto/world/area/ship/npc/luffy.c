#include <npc.h>
#include <ansi.h>

string *name = ({ "槍", "鞭", "圖章", "火箭炮", "網",
                  "槍亂打", "螺旋彈", "戰斧", "攻城炮" });

void do_fight()
{
    object ob, enemy;
    int damage, raiseDamage, i, exact, evade;

    ob = this_object();
    enemy = ob->query_opponent();

    if( !enemy ) return;
    if( environment(ob)->is_area() ) {
        if( !area_environment(ob, enemy) ) return;
    } else {
        if( environment(enemy) != environment(ob) ) return;
    }
    // 二檔判斷
    if( !query("two_down") && query_stat_current("hp") < query_stat_maximum("hp")*2/3 ) {

        ob->set("nickname", HIW+BLINK"二檔"NOR);
        ob->add_temp("apply/exact", 400);
        ob->add_temp("apply/evade", 400);
        ob->set("two_down", 1);

        ob->set_stat_current("hp", ob->query_stat_maximum("hp"));
        ob->set_stat_current("ap", ob->query_stat_maximum("ap"));
        ob->set_stat_current("mp", ob->query_stat_maximum("mp"));

        message_vision("\n$N說道﹕"HIG"好痛阿！可惡！我生氣了！\n"NOR+CYN"$N雙手壓住自己的膝蓋，像個蒸氣機般不停打氣。\n"CYN"$N全身噴出白色蒸氣，發出沙沙聲響！\n"NOR"$N說道﹕"HIG"進入•二檔。\n\n"NOR, ob);

        kill_ob(enemy);
        if( function_exists("accept_kill", enemy) && !enemy->is_killing(ob) && enemy->accept_kill(ob) ) return;
        enemy->kill_ob(ob);
        return;
    }
    // 一般技能與二檔技能
    if( query("two_down", 1) ) {
        exact = COMBAT_D->exact(this_object(), enemy, 1) + COMBAT_D->exact(this_object(), enemy, 1)/5;
        evade = COMBAT_D->evade(enemy, this_object(), 1);

        message_vision("\n$N"HIR"臉上露出一絲霸氣，右腳連續輕踏地面"HIW"「剃」"HIR"突然消失在$n的眼前！！\n"NOR, this_object(), enemy);
        for(i=0;i<=3;i++) {
            message_vision(CYN"\n$N一個瞬間出現在$n的身旁！\n"NOR, ob, enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("$N一招"HIY"橡膠 JET "+name[random(sizeof(name))]+NOR"像風一般掃過$n的臉頰，在地上轟出個大洞。\n", ob, enemy);
                ob->start_busy(2);
            } else {
                raiseDamage = 1200;
                ob->add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(ob, enemy, 0);
                ob->add_temp("apply/attack", -raiseDamage);
                enemy->receive_damage(damage, ob);
                message_vision( sprintf("$N使出"HIY"橡膠 JET "+name[random(sizeof(name))]+NOR"！強勁的力道立刻把$n擊飛了出去！(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), ob, enemy);
                ob->start_busy(1);
            }
        }
        message_vision(HIR"\n$N收回了連續攻擊！\n\n"NOR, ob, enemy);
    } else {
        message_vision("\n$N怒吼著："HIG"想拿我的草帽！不可原諒！看我的"HIY"橡膠"+name[random(sizeof(name))]+NOR+HIG"！！！\n"NOR, ob, enemy);
        if( !COMBAT_D->isHit(ob, enemy) ) {
            message_vision("$n好不容易驚險萬分的閃了開來！\n\n", ob, enemy);
            ob->start_busy(3);
        } else {
            raiseDamage = 1500;
            ob->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(ob, enemy, 0);
            ob->add_temp("apply/attack", -raiseDamage);
            enemy->receive_damage(damage, ob);
            message_vision( sprintf("$n不知道被打中了幾拳，全身沒一處是完整的(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), ob, enemy);
            ob->start_busy(1);
        }
    }
    return;
}

void to_do_say()
{
    if( query("two_down", 1) ) {
        message_vision(CYN"$N喘了口氣，身上二檔的效果漸漸消失了。\n"NOR, this_object());
        delete("nickname");
        add_temp("apply/exact", -400);
        add_temp("apply/evade", -400);
        delete("two_down");
    }
    if( random(200) == 100 ) {
        do_chat( ({
            CYN"魯夫無聊的唸著：怎麼還不能吃飯∼\n"NOR,
            CYN"魯夫大叫著：我要吃肉！吃肉！\n"NOR,
            CYN"魯夫大叫著：香吉！開飯拉∼∼∼∼∼！\n"NOR,
        }) );
    }
    do_heal();
}

void create()
{
    set_name("魯夫", ({ "luffy" }) );
    set_race("human");
    set_level(60);
    set_class("money_sea");         // 通緝海賊
    set("classify", "strengthen");  // 強化
    set("age", 17);
    set("title", HIY"帶草帽的"NOR);
    set("long", "被世界政府重金懸賞的可怕海賊，但是看他滿臉笑容的樣子一點也不\n"
                "像是十惡不赦的大海賊。只見他悠閒的躺在黃金梅莉號的羊頭上休息\n"
                "臉上蓋著他的標準配備，也是與某人重要約定的無價之寶─"HIY"草帽"NOR"。\n");

    // 一般時動作
    set("chat_chance", 20);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":103, "amount":1, "p1":1, "p2":100 ]),               // 草帽
        ([ "type":"eq", "id":115, "amount":1, "p1":1, "p2":800 ]),               // 草帽
        ([ "type":"food", "id":47, "amount":1+random(5), "p1":60, "p2":100 ]),   // 蟹肉
        ([ "type":"food", "id":68, "amount":1+random(21), "p1":80, "p2":100 ]),  // 魚肉
        ([ "type":"food", "id":75, "amount":1+random(11), "p1":80, "p2":100 ]),  // 鯊魚肉
        ([ "type":"food", "id":76, "amount":1, "p1":60, "p2":100 ]),             // 海賊便當
    }) );

    setup();
    set_skill("combat", 200);
    set_skill("parry", 200);
    set_skill("dodge", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 200);

    // 附加能力，等高能力有點差
    add_temp("apply/exact", 100);       // 命中
    add_temp("apply/evade", 100);       // 迴避
    add_temp("apply/intimidate", 150);  // 攻擊能力
    add_temp("apply/wittiness", 150);   // 防禦能力
    add_temp("apply/con", 20);
    add_temp("apply/str", 10);

    // 裝備
    carry_object(__DIR__"eq/boater2.c")->wear();
}

void die()
{
    object enemy, killer;
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        destruct(this_object());  // 找不到對手，直接消失
        return;
    }
    if( query("two_down", 1) ) {  // 二檔才殺的死
        int i = 120 + random(31);
        // 寵物殺死算主人的
        if( !userp(enemy) && objectp(enemy->query_owner()) ) {
            killer = enemy->query_owner();
        } else {
            killer = enemy;
        }
        msg = "\n\n"YEL"\t魯夫臉上露出開朗的笑容對著自己的海賊團員說..."NOR"\n\n"HIW"\t『各位∼∼真對不起∼∼我要∼∼"BLINK"死了！"NOR+HIW"』"NOR"\n\n"YEL"\t草帽海賊團成員一擁而上，卻仍然救不了魯夫..."NOR"\n\n"HIR"\t大鬧海軍的草帽小子，居然被"HIW+enemy->rank()+enemy->query("name")+HIR"殺死了！"NOR"\n\n\n"NOR;

        killer->add("exchange", i);
        CHANNEL_D->say_channels(this_object(), "news", msg, 1);
        tell_object(killer, HIY"(因為你殺死魯夫獲得了 "+i+" 點兌換點數。)\n"NOR);
        ::die();
        return;
    } else {
        message_vision("\n$N邊跑邊說道﹕"HIG"$n真是太強了，還是趕快逃走吧！"NOR"\n$N邊跑邊說道﹕"HIG"我沒有理由跟$n打架！\n\n"NOR, this_object(), enemy);
        message_vision("$N一溜煙地就不見人了。\n\n"NOR, this_object(), enemy);
        destruct(this_object());
        return;
    }
    return;
}

int accept_fight(object me, string arg)
{
    do_chat( ({
        (: command, "shake" :),
        (: command, "say 我餓了不想打架" :),
    }) );
    return 0;
}
