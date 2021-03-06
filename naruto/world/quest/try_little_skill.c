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
    return "小試身手";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "初來乍到，馬不繞決定交給你一個試試身手的任務，他要求你去各\n";
    msg += "地狩獵小型的動物，順便了解當地的地理環境。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 4;
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
    if( player->query("level") < 4 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/whale_island/npc/teacher2.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N正上下打量著$n，似乎正在評估$n的戰鬥能力...\n"NOR,
        "$N對著$n說道："HIG"有個任務要到處狩獵小型動物，跑的範圍很廣喔。\n"NOR,
        "$N說道："HIG"算是一個試身手的任務吧，$n有興趣嗎？\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/wild/npc/babypig.c": 20,        // 小豬仔
        "/world/area/whale_island/npc/rabbit.c": 15, // 小白兔
        "/world/area/wild/npc/smallwolf.c": 10,      // 小狼
        "/world/area/wild/npc/smallsnake.c": 10,     // 小蛇
        "/world/area/old_forest/npc/monkeyc.c": 10,  // 小猴
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
    return "/world/area/whale_island/npc/teacher2.c";
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
    string msg = "學習點數 200 點。\n";
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
    player->add_point("learn", 200);
    tell_object(player, HIY"(你獲得了 200 點學習點數。)\n"NOR);
}
