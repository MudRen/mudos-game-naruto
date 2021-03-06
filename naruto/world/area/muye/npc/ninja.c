#include <npc.h>

inherit F_BANDIT;

string *name1 = ({ "袁", "流", "小", "承", "百鬼", "阿", "偷心", "地", "浮雲", "博斯", 
                  "靠", "湛", "滅", "嵐", "好", "嵐", "好", "法", "楊", "蘇", "魔", 
                  "闇夜", "比", "示申", "天涯", "遠", "雲", "犬", "天", "勇", "三朵", 
                  "忍", "牙", "水", "怡", "闇行" });

string *name2 = ({ "世凱", "影", "瞳", "諾", "夜行", "斯蘭", "•盜香帥", "里兒", "遊子",
                  "精靈", "的住", "藍", "牙", "嵐", "自在", "拉利", "過", "普", "夜",
                  "隱者", "司吉", "木不", "孤行", "端", "寶寶", "夜叉", "龍雲", "兒",
                  "花", "蜂", "彩", "膏", "泮月", "文", "者" });

void do_fight()
{
    object enemy;

    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( this_object()->query("sktree") ) {
        case 1: // 四腳術
            command("perform four foot.beast");
            break;
        case 2: // 倍化術
            if( !mapp(this_object()->query_condition("dp")) )
            command("perform double physique.dp");
            break;
        case 3: // 木之葉烈風
            break;
        case 4: // 百烈掌
            command("perform hundred palm.attack on " + enemy->query_id());
            break;
        case 5: // 千年殺
            command("perform thousand year kill.attack on " + enemy->query_id());
            break;
        case 6: // 細胞活化
            break;
    }
}

void do_ca()
{
    if( this_object()->query("sktree") != 6 || this_object()->query_condition("ca2") != 0 ) return;
    command("perform cell activation.ca");
    this_object()->heal_stat("mp", 200);
}

void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "ninja" }));
    set_race("human");
    set_level(20);
    set("age", 10+random(21));
    set("long", "一個正在接受中忍考試的學生，慌張的東張西望。\n");

    set("attitude", "aggressive");         // 主動攻擊

    // 隨機移動
    set("chat_chance", 4);
    set("chat_msg", ({
        (: do_ca :),
        (: random_move :),
    }));

    // 戰鬥動作
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":50+random(50), "p1":50, "p2":100 ]),  // 銀子
        ([ "type":"obj", "id":9, "amount":1, "p1":15, "p2":100 ]),  // 地之書
        ([ "type":"obj", "id":13, "amount":1, "p1":15, "p2":100 ]),  // 天之書
    }) );

    set("sktree", random(6)+1);

    setup();

    // 狀態
    set_stat_current("hp", 800);
    set_stat_current("ap", 800);
    set_stat_current("mp", 800);
    set_stat_maximum("hp", 800);
    set_stat_maximum("ap", 800);
    set_stat_maximum("mp", 800);

    // 技能
    set_skill("ninja", 90);
    set_skill("force", 90);
    set_skill("parry", 90);
    set_skill("dodge", 90);
    set_skill("combat", 90);
    set_skill("heavy hit", 90);
    set_skill("savage hit", 90);
    set_skill("continual hit", 90);
    set_skill("substitute", 90);
    map_skill("dodge", "substitute");      // 使用技能「替身術」於迴避技巧上

    switch( query("sktree") ) {
        case 1: // 四腳術
            set_skill("four foot", 90);
            break;
        case 2: // 倍化術
            set_skill("double physique", 90);
            break;
        case 3: // 木葉之烈風
            set_skill("muye wind", 90);
            break;
        case 4: // 百烈掌
            set_skill("hundred palm", 90);
            break;
        case 5: // 千年殺
            set_skill("thousand year kill", 90);
            break;
        case 6: // 細胞活化
            set("chat_chance", 50);
            set_skill("cell activation", 90);
            break;
    }
    // 增強
    set_temp("apply/attack", 150);        // 攻擊力量
    set_temp("apply/armor", 50);          // 防禦力量
    set_temp("apply/exact", 37);          // 命中率
    set_temp("apply/evade", 50);          // 迴避率
    set_temp("apply/intimidate", 10);     // 攻擊能力
    set_temp("apply/wittiness", 10);      // 防禦能力
    set_temp("apply/int", 5);
    set_temp("apply/con", 5);
    set_temp("apply/str", 5);
    set_temp("apply/dex", 5);
}
