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
    return "醫忍考驗";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "治癒術是一門基本的醫療忍術，雖然是基本，卻需要配合靈活的查克\n";
    msg += "拉運用。因此春野櫻將當初綱手所指導的練習方式告訴你，要求你去\n";
    msg += "古老森林的樹上進行一個小任務，拿回一些各種類的水果。在樹枝移\n";
    msg += "動間不但可以訓練查克拉的使用，而且古老森林中還隱藏了很多土著\n";
    msg += "，可能會突然攻擊你，藉此來訓練警戒和應變的能力。\n";

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
    if( player->query_skill("heal buff", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/muye/npc/ying.c";   // 小櫻
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"要學習治癒術必須要先給$n一個考驗。\n"NOR,
        "$N說道："HIG"這也是當初綱手大人所給我的考驗。\n"NOR,
        "$N說道："HIG"$n去古老森林的樹枝上進行任務。\n"NOR,
        "$N說道："HIG"完成了要求的任務後再回來找我吧。\n"NOR,
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
        "/world/area/old_forest/npc/item/fruit.c": 15,   // 樹果
        "/world/area/old_forest/npc/item/fruit3.c": 15,  // 乾果
        "/world/area/old_forest/npc/item/fruit2.c": 6,   // 水果
        "/world/area/old_forest/npc/item/fruit4.c": 1,   // 水果王
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
    return "/world/area/muye/npc/ying.c";   // 小櫻
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N點了點頭。\n"NOR,
        "$N說道："HIG"$n順利完成任務，治癒術也可以教$n了。\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "學習技能「"HIW"治癒術"NOR"」\n";
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
    player->set_skill("heal buff", 2);
    tell_object(player, HIY"(春野櫻將治癒術的使用方法教會你了)\n"NOR);
}
