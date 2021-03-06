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
    return "家豬培養";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "為了讓大家吃到好吃的豬肉，泰斯特希望讓目前的家豬與野生豬配\n";
    msg += "種，成為一種新型豬，不過野生豬不像家豬任憑宰割，到處亂跑讓\n";
    msg += "原本體力就不好的泰斯特累個半死，最後只好委託幫忙。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 2;
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
    if( player->query("level") < 2 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/old_forest/npc/test.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"我最近正在研究新品種的豬！\n"NOR,
        "$N對著$n說道："HIG"不過野生的豬跑的好快...追的我全身酸痛...\n"NOR,
        "$N對著$n說道："HIG"如果有空能幫我拿些資料嗎？\n"NOR,
    });
        
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/wild/npc/babypig.c": 10,  // 小豬仔
        "/world/area/wild/npc/smallpig.c": 6,  // 豬仔
    ]);
    return kill;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
// 不可數的物品數量只能設定為1, 不然任務會無法執行
mapping getItem() {
    mapping item = ([
        "/world/area/wild/npc/item/pig_gut.c": 20, // 豬腸
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
    return "/world/area/old_forest/npc/test.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N瞠目結舌，好像看到了一件不可思議的事。\n"NOR,
        "$N興奮地說道："HIG"$n真的幫我拿齊資料啦！\n"NOR,
        CYN"$N得意的作出勝利的手勢! 「 V 」  說: 「 哈哈哈...」\n"NOR,
        "$N對著$n說道："HIG"這些謝禮就交給$n啦！\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "學習點數 70 點。\n";
    msg += "銀子 1600 兩。\n";
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
    player->add_point("learn", 70);
    tell_object(player, HIY"(你獲得了 70 點學習點數。)\n"NOR);
    player->add("bank", 1600);
    tell_object(player, HIY"(你獲得了 1600 兩銀子。)\n"NOR);
}
