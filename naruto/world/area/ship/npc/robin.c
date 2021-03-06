#include <npc.h>
#include <ansi.h>

string *name1 = ({ "三輪花", "五輪花", "六輪花", "十四輪花", "十六輪花",
                   "三十輪花", "六十輪花", "百花撩亂", "巨輪花" });

string *name2 = ({ "大飛燕草", "掌嘴", "關節技", "折枝" });

void do_fight()
{
    object enemy;
    int damage, raiseDamage, exact;

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // 已經定住就不能放
    if( enemy->is_busy() ) return;
    exact = COMBAT_D->exact(this_object(), enemy, 1)*3/10;

    add_temp("apply/exact", exact);
    message_vision("\n$N閉眼雙手交叉施展"HIM"「花花果實」"NOR"特殊能力之『"HIW+name1[random(sizeof(name1))]+NOR"』！\n"NOR, this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("$N的手忽然從地上長出來，但是被$n躲開了...\n", this_object(), enemy);
        this_object()->start_busy(1);
    } else {
        message_vision("$N的手忽然從$n身上長出來，把$n團團抓住無法動彈\n\n", this_object(), enemy);
        enemy->start_busy(4);
        if( random(3) > 0 ) {
            raiseDamage = 1000;
            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);
            message_vision("$N睜開眼睛發動『"HIY+name2[random(sizeof(name2))]+NOR"』綁在$n身上的手忽然做出了反應！\n"NOR, this_object(), enemy);
            enemy->damage_stat("hp", damage, this_object());
            message_vision( sprintf("「喀啦」一聲，$N的花之手對$n的骨骼經絡造成重創，全身疼痛不已(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        }
    }
    add_temp("apply/exact", -exact);
    return;
}
void create()
{
    set_name("羅賓", ({ "robin", "_ROBIN_" }) );
    set_race("human");
    set_level(55);
    set_class("thief_sea");         // 海賊
    set("classify", "strengthen");  // 強化
    set("age", 23);
    set("gender", "female");
    set("title", HIW"考古學家"NOR);
    set("long", "奧哈拉古歷史研究者島上唯一的生還者，也是當時的平民中唯一目\n"
                "睹奧哈拉滅亡的人，被世界政府通緝而無家可歸，只能加入海賊不\n"
                "停背叛逃亡為的就是尋找真正的歷史本文。\n" );

    set("chat_chance", 30);
    set("chat_msg", ({
        (: do_heal :),
    }) );
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("set_drop", ({
        ([ "type":"obj", "id":16, "amount":1, "p1":10, "p2":100 ]),   // 武卷體格+1
        ([ "type":"obj", "id":17, "amount":1, "p1":10, "p2":100 ]),   // 武卷敏捷+1
        ([ "type":"obj", "id":20, "amount":1, "p1":10, "p2":100 ]),   // 武卷智慧+1
        ([ "type":"obj", "id":21, "amount":1, "p1":10, "p2":100 ]),   // 武卷力量+1
    }) );

    setup();
    set_skill("combat", 180);
    set_skill("dodge", 200);
    set_skill("parry", 160);
    set_skill("heavy hit", 160);
    set_skill("savage hit", 160);
    set_skill("continual hit", 160);

    add_temp("apply/exact", 50);        // 迴避
    add_temp("apply/intimidate", 100);  // 攻擊技巧
    add_temp("apply/wittiness", 50);    // 防禦技巧
    add_temp("apply/int", 15);
    add_temp("apply/con", 5);
    add_temp("apply/dex", 5);
    add_temp("apply/str", 5);
}
int accept_kill(object me, string arg)
{
    object ob;
    if( ob = present("_NAMI_", environment(this_object())) ) {
        ob->dismiss_team();
        ob->set_team(0);
        message_vision("\n娜美說道："HIG"不准傷害$N姐姐！\n"NOR, this_object());
        ob->set_team(this_object());
        ob->add_team_member(this_object());
        ob->kill_ob(me);
        if( function_exists("accept_kill", me) && !me->is_killing(ob) && me->accept_kill(ob) ) return 1;
        me->kill_ob(ob);
    }
    if( this_object()->query_condition("elf", 1) == 0 && ob ) {
        ob->force_me("perform chimera fay.assoil");
    }
}
int accept_fight(object me, string arg)
{
    do_chat( ({
        (: command, "shake" :),
    }) );
    return 0;
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 15 + random(6);

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
    msg = "\n\n"HIW"...同伴...奧哈拉的各位...對不起...\n\n我無法完成大家的期望，將歷史公諸於世了！\n\n"NOR;
    msg += HIR"【社會新聞】"HIK"「惡魔之子」"HIR+this_object()->query("name")+"("+this_object()->query("id")+")被世界政府的走狗"+enemy->query("name")+"("+enemy->query("id")+")給殺死了！\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死羅賓獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}