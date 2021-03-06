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
    return "與狗共舞";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "為了與寵物達到良好的關係，訓練也是非常重要的，因此犬塚牙要求\n";
    msg += "你到世界政府的領地「司法島」上向專門訓練狗的特殊部隊•法狗隊\n";
    msg += "進行幾場比試，了解到訓犬術的重要。\n";

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
    if( player->query_class() == "inferior" ) return 0;
    if( player->query_skill("double fang", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/muye/npc/yaa.c";   // 犬塚牙
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"牙通牙必須要寵物與主人互相搭配才能發揮效果。\n"NOR,
        CYN"$N低頭沉思.\n"NOR,
        "$N說道："HIG"司法島好像有種名叫法狗的部隊，就是專門訓練狗的。\n"NOR,
        "$N說道："HIG"$n去司法島見識見識他們的訓犬術吧。\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/sifa_isle/npc/guarddog.c": 5,  // 法狗部隊
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
    return "/world/area/muye/npc/yaa.c";   // 犬塚牙
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N「嗯」的一聲﹐一副欲言又止的樣子。\n"NOR,
        "$N說道："HIG"既然$n已經通過了考驗，這就教$n牙通牙吧。\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "學習技能「"HIC"牙通牙"NOR"」\n";
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
    player->set_skill("double fang", 2);
    tell_object(player, HIY"(經過犬塚牙的指導，你了解使用牙通牙的竅門了)\n"NOR);
}
