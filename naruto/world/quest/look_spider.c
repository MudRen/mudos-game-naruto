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
    return "追蹤毒蜘蛛";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "因為聽說音隱忍者開始使用毒蜘蛛訓練自己的下忍，這樣的忍者不\n";
    msg += "但對毒性抵抗比較強烈，同時也可能使用蜘蛛毒來對付其他的敵人\n";
    msg += "，上忍童角接到火影所交給的任務開始研究毒蜘蛛的習性，因為資\n";
    msg += "訊太多必須一一整理而沒時間去實地考察，現在便將任務交給你去\n";
    msg += "幫忙童角考查。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 25;
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
    if( player->query("level") < 25 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/bone/npc/gau.c";  // 童角
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"不好意思，太忙了支不開身。\n"NOR,
        "$N對著$n說道："HIG"能麻煩$n到鯨魚島山洞幫我拿些毒蜘蛛的資料嗎？\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/whale_island/npc/spider.c": 20,     // 小毒蛛
        "/world/area/whale_island/npc/spider2.c": 20,    // 大型毒蛛
        "/world/area/whale_island/npc/spider3.c": 20,    // 巨型毒蛛
        "/world/area/whale_island/npc/spider4.c": 20,    // 突變毒蛛
        "/world/area/whale_island/npc/spider5.c": 20,    // 突變劇毒蜘蛛
    ]);
    return kill;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
    mapping item = ([
        "/world/area/whale_island/npc/item/spider-leg.c": 130,   // 蜘蛛腿
        "/world/area/whale_island/npc/item/spider-eye.c": 70,   // 蜘蛛眼睛
        "/world/area/whale_island/npc/item/spider-venom.c": 30, // 蜘蛛毒液
    ]);
    return item;
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/world/area/bone/npc/gau.c";  // 童角
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

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N拿走資料接著說道："HIG"嗯...這些蜘蛛繼續在那裡果然很危險...\n"NOR,
        "$N說道："HIG"必須要告訴火影大人這事情的嚴重性。\n"NOR,
        "$N對著$n說道："HIG"這次任務辛苦$n了。\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 2500 點。\n";
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
    player->add_point("learn", 2500);
    tell_object(player, HIY"(你獲得了 2500 點學習點數。)\n"NOR);
}
