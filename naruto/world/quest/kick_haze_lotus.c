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
    return "蓮花斬擊";
}

// 任務描述
string getDetail() {
    string msg;

        msg  = "「"HIM"嵐腳•蓮華"NOR"」包含了嵐腳以外的特殊攻擊，主要能力帶有火焰般的\n";
        msg += "燒傷，因此控制力變的十分重要，如果斬擊時距離算錯可是連自己都\n";
        msg += "會被火焰所吞噬。卡庫就是了解這一點，才叫你去找群居的蛇類動物\n";
        msg += "練習，練習結束之後可以找ＣＰ９成員「隈取」學習技能，卡庫的技\n";
        msg += "能太過深奧暫時無法領悟。\n";

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
    if( player->query("guild") != "piece" ) return 0;
    if( player->query_skill("kick luan", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/sifa_isle/npc/ku.c";   // 卡庫
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"想學習老朽的招式？\n"NOR,
        CYN"$N低頭沉思.\n"NOR,
        "$N說道："HIG"老朽的技巧$n可能還無法領悟。\n"NOR,
        "$N說道："HIG"只要$n去殺些蛇，再買把棘回來，我會叫隈取教$n招式的。\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/wild/npc/snake.c": 10,     // 蛇
        "/world/area/wild/npc/bigsnake.c": 3,   // 大蛇
    ]);
    return kill;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
    mapping item = ([
        "/world/area/thorn_pine/npc/item/gie.c": 1,   // 棘
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
    return "/world/area/sifa_isle/npc/wei.c";   // 隈取
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"呦伊呦伊！就是$n！\n"NOR,
        "$N說道："HIG"想學嵐腳嗎！\n"NOR,
        "$N說道："HIG"卡庫這樣講就教$n吧！呦伊呦伊！\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "學習技能「"HIM"嵐腳•蓮華"NOR"」\n";
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
    player->set_skill("kick lotus", 2);
    tell_object(player, HIY"(嘗試多次你終於領悟了蓮華的使用方法)\n"NOR);
}
