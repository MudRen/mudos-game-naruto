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
    return "王者之風";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "這是由獵人導師藍調希凡所托的任務，目的是讓即將步入新境界的\n";
    msg += "人們體會什麼叫做王者的風範。\n";

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
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/thorn_pine/npc/hxh_adv_master.c";  // 藍調希凡
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N正上下打量著$n，似乎正在評估$n的戰鬥能力...\n"NOR,
        "$N對著$n說道："HIG"差不多也到時候了，再下去$n可能會遇到強大的敵人吧。\n"NOR,
        "$N說道："HIG"接下這個任務吧！去看看動物之王們的姿態！\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/lake/npc/zombie3.c": 1,                // 腐屍王
        "/world/area/wild/npc/kingpig.c": 1,                // 黑豬王
        "/world/area/echo/npc/mouse_king.c": 2,             // 地鼠王
        "/world/area/muye/npc/mouse_king.c": 2,             // 鼠王
        "/world/area/whale_island/npc/cockroach_king.c": 3, // 海蟑王
        "/world/area/muye/npc/cockroach_king.c": 3,         // 蟑王
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
    return "/world/area/thorn_pine/npc/hxh_adv_master.c";  // 藍調希凡
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"順利解決了嗎？\n"NOR,
        "$N對著$n說道："HIG"很好，這樣的挑戰以後可能會常遇到喔。\n"NOR,
        "$N對著$n說道："HIG"遇到任何的挑戰都要如此迎刃而解。\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "學習點數 1400 點。\n";
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
    player->add_point("learn", 1400);
    tell_object(player, HIY"(你獲得了 1400 點學習點數。)\n"NOR);
}
