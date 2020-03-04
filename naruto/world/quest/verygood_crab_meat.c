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
    return "絕世好蟹";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "屠千蟹聽說在天鵝湖附近居然有種螃蟹擁有名為「蟹肉白盅」的肉\n";
    msg += "口感鮮甜有咬勁，是做螃蟹料理最棒的蟹肉。於是屠千蟹為了做出\n";
    msg += "最棒的蟹肉料理，到處找人幫忙拿回這種蟹肉。為了不破壞肉質調\n";
    msg += "理蟹肉，屠千蟹還要求你告訴他如何殺死這種螃蟹的方法。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 10;
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
    if( player->query("level") < 10 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/whale_island/npc/tu-qian-xie.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N高興地像小孩子似的蹦蹦跳跳.\n"NOR,
        "$N高興地問道："HIG"$n有聽過「蟹肉白盅」嗎？\n"NOR,
        "$N對著$n說道："HIG"聽說這種肉肉質鮮美！是夢幻的蟹肉阿！\n"NOR,
        "$N對著$n說道："HIG"不過牠們非常兇暴！我找人去拿都被夾傷了！\n"NOR,
        "$N對著$n說道："HIG"$n能幫我拿一些回來嗎？\n"NOR,
    });
        
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/lake/npc/crab.c": 5,  // 蟹將
    ]);
    return kill;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
    mapping item = ([
        "/world/area/lake/npc/item/crab.c": 10, // 蟹肉白盅
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
    return "/world/area/whale_island/npc/tu-qian-xie.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N高興的跳起舞來!!!\n"NOR,
        "$N興奮地說道："HIG"太棒啦！這就是傳說中的蟹肉白盅！\n"NOR,
        "$N對著$n說道："HIG"殺死牠的方法是這樣嗎？我知道了。\n"NOR,
        "$N對著$n說道："HIG"真是太感謝$n的幫助了！\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 400 點。\n";
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
    player->add_point("learn", 400);
    tell_object(player, HIY"(你獲得了 400 點學習點數。)\n"NOR);
}
