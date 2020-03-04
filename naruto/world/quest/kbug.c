/*  TestQuest.c
        
        一個用來測試任務系統正確性的測試用任務，也是任務撰寫的範例。
        
        目前任務支援類型：
                1. 殺死某些數量的怪物
                2. 取得某些數量的物品
                3. 造訪性任務  (意指某A要你去找某B，即可完成任務)
        
        注意：因為以檔名做識別，在設定時檔名記得加上 .c 
        
    write by Acme       - 2007.02.04
 */

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
    return "清除害蟲";
}

// 任務描述
string getDetail() {
    string msg;
        
    msg  = "木葉村下水道害蟲越來越多了，使得益蟲生存空間遭到嚴重威脅。\n";
    msg += "幫忙協助消除一些害蟲吧！\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 1;
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
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/muye/npc/nai.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N深深的嘆了一口氣。\n"NOR,
        "$N對著$n說道：木葉村下水道害蟲越來越多了，使得益蟲生存空間遭到嚴重威脅。\n",
        "$N對著$n說道：你能夠幫忙協助消除一些害蟲嗎？\n",
    });
        
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/cockroach.c": 20,  // 蟑螂
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
    return "/world/area/muye/npc/nai.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：真是太感謝你了，讓這世界上生物之間取得平衝！\n",
        CYN"$N快樂的手舞足蹈。\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 100 點。\n";
    msg += "銀子 100 兩。\n";
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
    player->add_point("learn", 100);
    tell_object(player, HIY"(你獲得了 100 點學習點數。)\n"NOR);
    player->add("bank", 100);
    tell_object(player, HIY"(你獲得了 100 兩銀子。)\n"NOR);
}
