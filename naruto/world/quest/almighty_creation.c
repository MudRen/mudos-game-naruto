#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

/* 此任務是否能重複解  return 0  不能重複
                       return 1  可重複
   建議最好設定不能重複。
 */
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "名劍";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "基加美修雖然已經擁有無數的兵器，卻仍然喜愛搜集新的武器，這次\n";
    msg += "他向你所要求的武器中，有一把「神木劍」似乎在木葉村泡湯人的閒\n";
    msg += "聊中可以略知一二，其他的武器卻完全沒有情報提供，看來想完成這\n";
    msg += "個任務並沒有想像中的簡單。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 20;
}

/* 接受任務的前置條件，可能是
        1. 等級需求
        2. 職業需求
        3. 種族需求
        4. 已完成某些任務需求
    等等，應可以自由發揮才是。
    回傳非零值表示符合條件。
 */
int preCondition(object player) {
    if( player->query("guild") != "hunter" ) return 0;
    if( player->query_class() == "hxh_initial" ) return 0;
    if( player->query_skill("almighty creation", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/magic_house/npc/gilga.c";   // 基加美修
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"雖然我喜歡搜集兵器，但數千年來這對我已經感到厭煩了。\n"NOR,
        "$N說道："HIG"搜集這種事，只要提供一點利益就一票人搶著去做。\n"NOR,
        "$N說道："HIG"怎麼樣$n？我把寶庫使用權交給$n，$n幫我把武器找來。\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    return ([]);
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
    mapping item = ([
        "/world/area/bone/npc/wp/shield.c": 1,             // 盾劍
        "/world/area/thorn_pine/npc/wp/lines_sword.c": 1,  // 刻紋劍
        "/world/area/old_forest/npc/wp/tree_sword.c": 1,   // 神木劍
    ]);
    return item;
}

// 完成任務的條件除了系統提供的
// 1. 搜集物品
// 2. 殺了足夠數量的怪物之外
// 有需要的話，還可以自訂完成任務條件
// return 1, 為滿足條件, return 0;為失敗
int postCondition(object player, object npc)
{
    return 1;
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/world/area/magic_house/npc/gilga.c";   // 基加美修
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"哈哈哈！看吧，想找武器就是這麼簡單。\n"NOR,
        "$N說道："HIG"我的「王之寶庫」使用權就交給$n了！\n"NOR,
        "$N說道："HIG"不過那畢竟是王的東西，像$n這樣的人無法連續使用吧！\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "學習技能「"HIR"無限的劍製"NOR"」\n";
    return msg;
}

/*  任務獎勵
    獎勵應該能自由發揮，如：
        1. 獲得經驗
        2. 獲得物品
        3. 獲得短暫Buff
        4. 習得某技能
        5. 更改玩家狀態, ex: 轉職
 */
void reward(object player, object npc)
{
    player->set_skill("almighty creation", 2);
    tell_object(player, HIY"(你獲得了基加美修王之寶庫的使用權利)\n"NOR);
}
