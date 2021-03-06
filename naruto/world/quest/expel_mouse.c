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
    return "破壞鼠";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "鯨魚島藥品商人為了收集藥材時常奔走各地，最近卻發現許多的野\n";
    msg += "生藥材都被破壞了，罪魁禍首就是回音山洞裡的地鼠們。\n";

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
    return "/world/area/whale_island/npc/piller.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N「唉」的一聲嘆了口氣。\n"NOR,
        "$N說道："HIG"最近藥材短缺，大部份都被地鼠破壞了。\n"NOR,
        "$N說道："HIG"真希望有人能治一治這些地鼠。\n"NOR,
    });
        
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/echo/npc/mouse1.c": 10, // 地鼠
        "/world/area/echo/npc/mouse2.c": 7,  // 肥地鼠
        "/world/area/echo/npc/mouse3.c": 4,  // 胖地鼠
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
    return "/world/area/whale_island/npc/piller.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"$n真的消滅了那些地鼠？！\n"NOR,
        "$N興奮地說道："HIG"這下子不用擔心藥材的問題啦！\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 180 點。\n";
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
    player->add_point("learn", 180);
    tell_object(player, HIY"(你獲得了 180 點學習點數。)\n"NOR);
}
