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
    return "頭殼壞掉";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "酷斯拉松井秀喜要求你去搜集各種動物的頭，因為「龍頭」必須要稍\n";
    msg += "微有點樣子才配稱為龍，當年松井秀喜為了召出傳說中的酷斯拉可是\n";
    msg += "費了好大的一番功夫，只要你能夠達到松井所要求的事，相信他也會\n";
    msg += "願意將這項技能教給你的。\n";

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
    if( player->query("guild") != "hunter" ) return 0;
    if( player->query_class() == "hxh_initial" ) return 0;
    if( player->query_skill("dragon-head draw", 1) ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/magic_house/npc/hideki.c";   // 松井秀喜
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N慘叫一聲, 滿臉「那也安捏?!?!?」的表情.\n"NOR,
        "$N說道："HIG"龍頭戲畫是我苦練了數十年才終於成功的技巧。\n"NOR,
        "$N說道："HIG"如果$n願意去搜集一些頭回來，我會考慮教$n的。\n"NOR,
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
        "/world/area/muye/npc/eq/mouse_head.c": 1,     // 鼠頭
        "/world/area/wild/npc/eq/wolf_head.c": 1,      // 狼頭
        "/world/area/wild/npc/eq/pig_head.c": 1,       // 黑豬頭
        "/world/area/muye/npc/item/turtle_head.c": 10, // 龜頭
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
    return "/world/area/magic_house/npc/hideki.c";   // 松井秀喜
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"都搜集來了？\n"NOR,
        CYN"$N低頭沉思.\n"NOR,
        "$N說道："HIG"好吧，我教$n龍頭戲畫。\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "學習技能「"HIG"龍頭戲畫"NOR"」\n";
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
    player->set_skill("dragon-head draw", 2);
    tell_object(player, HIY"(你努力的和松井秀喜學習，終於學會龍頭戲畫了)\n"NOR);
}
