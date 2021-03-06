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
    return "中忍考試衍生任務";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "尋找天地之書是個困難的任務，路上困難重重，常常打擊考生的\n";
    msg += "自信心，因此伊魯卡老師特別想出這個任務幫助考生完成考試。\n";

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
    if( player->query("guild") != "muye" ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/muye/npc/ka.c";  // 伊魯卡
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N正盯著$n看﹐不知道打些什麼主意。。\n"NOR,
        "$N說道："HIG"$n通過中忍考試了嗎？\n"NOR,
        "$N說道："HIG"我這有個任務也許能增加$n考試的興趣喔！\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/snake.c": 10,  // 大毒蛇
        "/world/area/muye/npc/spider.c": 10, // 大蜘蛛
        "/world/area/muye/npc/worm.c": 10,   // 大毛蟲
        "/world/area/muye/npc/ninja.c": 6,   // 中忍考試忍者
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
    return "/world/area/muye/npc/ka.c";  // 伊魯卡
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"有沒有幫助$n通過考試阿？\n"NOR,
        "$N說道："HIG"來！這些是任務的獎勵！\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 1000 點。\n";
    msg += "銀子 10000 兩。\n";
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
    player->add_point("learn", 1000);
    tell_object(player, HIY"(你獲得了 1000 點學習點數。)\n"NOR);
    player->add("bank", 10000);
    tell_object(player, HIY"(你獲得了 10000 兩銀子。)\n"NOR);
}
