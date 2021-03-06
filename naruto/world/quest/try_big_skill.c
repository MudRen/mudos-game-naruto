#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

/* 此任務是否能重複解  return 0  不能重複
                       return 1  可重複
   建議最好設定不能重複。
 */
int isNewly() { return 0; }

// 任務名稱
string getName() {
    return "大挑戰";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "這次的任務是杭鐵管所交付的，目的是試驗身手，看看能不能打贏\n";
    msg += "大型的生物們。如果不敵可千萬別逞強。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 15;
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
    if( player->query("level") < 15 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/whale_island/npc/teacher.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N正上下打量著$n，似乎正在評估$n的戰鬥能力...\n"NOR,
        "$N對著$n說道："HIG"這次的測試是針對大型的生物們。\n"NOR,
        "$N說道："HIG"算是一個試身手的任務吧，$n有興趣嗎？\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/wild/npc/bigsnake.c": 15,        // 大蛇
        "/world/area/wild/npc/bigwolf.c": 15,         // 大狼
        "/world/area/whale_island/npc/spider2.c": 15, // 大型毒蛛
        "/world/area/wild/npc/bigpig.c": 15,          // 大黑豬
    ]);
    return kill;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
    return ([]);
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
    return "/world/area/whale_island/npc/teacher.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"很好，看來這樣的任務已經難不倒$n了。\n"NOR,
        "$N對著$n說道："HIG"這次任務想必對了解各區也很有幫助吧。\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 800 點。\n";
    msg += "銀子 5000 兩。\n";
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
void reward(object player, object npc) {
    player->add_point("learn", 800);
    tell_object(player, HIY"(你獲得了 800 點學習點數。)\n"NOR);
    player->add("bank", 5000);
    tell_object(player, HIY"(你獲得了 5000 兩銀子。)\n"NOR);
}
