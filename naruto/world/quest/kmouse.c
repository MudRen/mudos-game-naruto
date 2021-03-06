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
    return "搗蛋的老鼠";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "木葉溫泉地原本是大家都愛去的地方，最近突然冒出許多的老鼠來\n";
    msg += "搗亂，令溫泉區的生意一落千丈。泡湯老闆請人來檢查後發現是下\n";
    msg += "水道的老鼠們咬破了管子跑進來的。雖然修好了管子老闆仍然不放\n";
    msg += "心，因此請人來幫忙滅鼠。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 2;
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
    if( player->query("level") < 2 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/muye/npc/pooler.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"老鼠！老鼠！不知道害我損失了多少生意！\n"NOR,
        CYN"$N臉上青一塊紫一塊!好像非常生氣!\n"NOR,
        "$N對著$n說道："HIG"除了消滅老鼠還要給我鼠尾證明！\n"NOR,
    });
        
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/mouse.c": 15,  // 老鼠
    ]);
    return kill;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
    mapping item = ([
        "/world/area/muye/npc/item/mouse_tail.c": 15, // 鼠尾
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
    return "/world/area/muye/npc/pooler.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"嗯∼的確是鼠尾沒錯！\n"NOR,
        "$N興奮地說道："HIG"$n做的很好！木葉溫泉感謝$n幫忙！\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 120 點。\n";
    msg += "銀子 150 兩。\n";
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
    player->add_point("learn", 120);
    tell_object(player, HIY"(你獲得了 120 點學習點數。)\n"NOR);
    player->add("bank", 150);
    tell_object(player, HIY"(你獲得了 150 兩銀子。)\n"NOR);
}
