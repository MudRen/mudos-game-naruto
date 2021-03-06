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
    return "山洞開鑿";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "因為鯨魚島人民辛苦開鑿的北邊山洞開到一半突然湧入大量的蜘\n";
    msg += "蛛而被迫放棄開鑿，村長害怕山洞裡的蜘蛛會跑進村裡危害村民\n";
    msg += "，所以決定用炸藥把洞口給封住，但是像炸藥這種危險的物品一\n";
    msg += "般商店根本不會賣，讓鯨魚島村長傷透了腦筋。\n";

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
    return "/world/area/whale_island/npc/village_head.c";  // 鯨魚島村長
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N正上下打量著$n，似乎正在評估$n的戰鬥能力...\n"NOR,
        "$N看著$n說道："HIG"$n知道我們村子北邊有個山洞吧！\n"NOR,
        "$N說道："HIG"山洞還沒有完成卻住進了一堆蜘蛛！\n"NOR,
        "$N忿怒地說道："HIG"所以我決定用炸藥把山洞給炸了！\n"NOR,
        "$N對著$n說道："HIG"可是到處都買不到炸藥！$n能不能幫我買點回來？\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    return ([]);
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
    mapping item = ([
        "/world/area/thorn_pine/npc/item/firepill.c": 10,  // 炸藥
        "/world/area/thorn_pine/npc/item/bom.c": 5,        // 炸彈
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
    return "/world/area/whale_island/npc/village_head.c";  // 鯨魚島村長
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N高興的跳起舞來!!!\n"NOR,
        "$N高興地說道："HIG"哈哈！看我怎麼炸翻那群蜘蛛！\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "學習點數 800 點。\n";
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
}
