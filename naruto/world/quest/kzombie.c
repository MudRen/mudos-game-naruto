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
    return "消滅腐屍";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "天鵝湖底的遺址中，有不少的腐屍在活動，木葉忍者村有意把當地\n";
    msg += "發展成訓練忍者戰鬥技巧的地方，可是裡面的腐屍實在是太多了，\n";
    msg += "因此木葉忍者村開始召集有實力的人幫忙清除腐屍。\n";

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
    return "/world/area/muye/npc/ka.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N正上下打量著$n，似乎正在評估$n的戰鬥能力...\n"NOR,
        "$N說道："HIG"木葉村最近在尋找一批有實力的人幫忙清除腐屍。\n"NOR,
        "$N對著$n說道："HIG"$n有沒有興趣幫忙？\n"NOR,
    });
        
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/lake/npc/zombie.c": 30,  // 腐屍
        "/world/area/lake/npc/zombie2.c": 2,  // 腐屍(林北)
        "/world/area/lake/npc/zombie4.c": 2,  // 腐屍(女傭)
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
    return "/world/area/muye/npc/ka.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"這樣腐屍應該又減少了不少吧。\n"NOR,
        "$N興奮地說道："HIG"非常感謝$n的幫助。\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 1200 點。\n";
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
    player->add_point("learn", 1200);
    tell_object(player, HIY"(你獲得了 1200 點學習點數。)\n"NOR);
}
