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
    return "海市蜃樓";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "「"HIC"幻想妖精"NOR"」是一招改變四周氣候造成海市蜃樓幻象的招式，沒有對\n";
    msg += "天氣的了解是無法使用這招的，因此娜美要求你去找幾樣必要的物品\n";
    msg += "她才能夠教導你使用這個招式。其中有一樣天氣預測表必須要找木葉\n";
    msg += "村忍者「童角」索取，這張表單也是所有物品中最重要的，如果沒有\n";
    msg += "拿到這張表單，想要不懂氣象航海又學會操縱天氣根本不可能。\n";

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
    if( player->query_skill("chimera fay", 1) ) return 0;
    if( player->query_class() == "work_sea" ) return 0;
    if( player->query_class() == "little_sea" ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/ship/npc/nami.c";   // 娜美
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N低頭沉思.\n"NOR,
        "$N說道："HIG"$n似乎沒有航海的經驗，對天氣預測想必不是很拿手。\n"NOR,
        "$N說道："HIG"去木葉忍者村找一位名叫「童角」的忍者拿「天氣預測表」吧。\n"NOR,
        "$N說道："HIG"還有其他的物品也順便一起拿來。\n"NOR,
        "$N說道："HIG"等$n收集齊全我就教導$n有關氣候的知識。\n"NOR,
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
        "/world/eq/armor/turtle.c": 1,             // 龜甲
        "/world/area/old_forest/npc/eq/leaf.c": 1, // 樹葉
        "/world/area/ship/npc/item/paper.c": 1,    // 天氣預測表
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
    return "/world/area/ship/npc/nami.c";   // 娜美
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"物品備齊了，現在來告訴$n有關氣候的知識。\n"NOR,
        "$N說道："HIG"當氣候不明時可以查看龜甲紋路或是四周的樹葉葉痕...\n"NOR,
        "$N說道："HIG"有些樹的葉子葉痕比較不明顯，這時看樹皮也許會更清楚。\n"NOR,
        CYN"$N講解著其他有關天氣的知識...\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "學習技能「"HIC"幻想妖精"NOR"」\n";
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
    player->set_skill("chimera fay", 2);
    tell_object(player, HIY"(經過娜美的教學後，你了解幻想妖精的使用方法了)\n"NOR);
}
