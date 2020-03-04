#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // 訓練導師

void do_fight()
{
    object enemy, sword, item;

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( !objectp(sword = present("_CREATION_SWORD_", this_object())) ) {
        item = new("/daemon/skill/hxh/concrete/obj/sword_obj.c");
        item->move(this_object());
    }
    if( this_object()->query_condition("diabo_busy") != 0 ) {
        message_vision(HIW"$N發動$N之力，去除王之財寶的冷卻時間了。\n"NOR, this_object());
        this_object()->delete_condition("diabo_busy");
    }
    command("perform almighty creation.rain on " + enemy->query_id() );
    return;
}

void do_sword()
{
    object sword;
    if( !objectp(sword = present("_CREATION_SWORD_", this_object())) ) {
        command("perform almighty creation.gz" );
    }
    return;
}

void create()
{
    set_name("基加美修", ({ "gilgamesh" }) );
    set_race("human");
    set_level(80);
    set_class("hxh_star2");  // 二星獵人
    set("age", 24);
    set("camp", "hunter");
    set("nickname", HIY"英雄王"NOR);
    set("long", "神話中的王者，擁有過人的能力無人可匹敵，喜好收集各種各類的\n"
                "刀劍兵器，在死後被聖杯召喚成為英靈，並獲得了能夠召集各式各\n"
                "樣武器的能力。他是被魔術馬戲團長召喚而來的。可以利用train \n"
                "指令來學習技能。使用 list 指令查詢可學習的技能列表。\n");

    set("chat_chance", 20);
    set("chat_msg", ({
        (: do_sword :),
    }) );

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // 只教導獵人
    set("guild", "hunter");

    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 180, "hunter", -2);             // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 140, "hunter", -2);              // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 180, "hunter", -2);              // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 200, "hunter", 0);          // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 140, "hunter", -2);         // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 160, "hunter", -2);      // 連擊之術
    set_train_with_camp("concrete", 1, 10, 200, "hunter", -1);          // 具現化系程度
    set_train_with_camp("eaves family", 0, 15, 160, "hunter", -1);      // 屋簷下的一家人
    set_train_with_camp("chamber fish", 0, 21, 140, "hunter", 0);       // 密室念魚
    set_train_with_camp("almighty creation", 0, 20, 120, "hunter", 0);  // 無限的劍製

    setup();
    set_skill("combat", 140);
    set_skill("dodge", 160);
    set_skill("parry", 180);
    set_skill("heavy hit", 140);
    set_skill("savage hit", 160);
    set_skill("continual hit", 160);
    set_skill("concrete", 200);
    set_skill("eaves family", 200);
    set_skill("chamber fish", 200);
    set_skill("almighty creation", 200);
}
int accept_fight(object me, string arg)
{
    return 0;
}
