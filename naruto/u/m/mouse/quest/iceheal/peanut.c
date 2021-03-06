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
    return "落花生";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "古董商人嗑著花生等待客人上門，你從旁邊經過卻被落花生的香味\n";
    msg += "還有古董商人那一副落花生很好吃的樣子給吸引進去了，為了吃到\n";
    msg += "看起來好像很好吃的花生，拼了命也要拿到古董！\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 25;
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
    if( player->query("level") < 25 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/lake/npc/seller.c";   // 古董商人
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N拿著一袋落花生嗑牙中...\n"NOR,
        "$N盯著$n說道："HIG"$n有什麼事嗎？想買什麼古董？\n\n"NOR,
        CYN"$N發現$n其實是盯著他手上的落花生...\n"NOR,
        "$N隨意的說道："HIG"想吃花生？可以！去天鵝湖底密室拿古董給我吧！\n"NOR,
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
        "/world/area/lake/npc/item/vase.c": 5,     // 古董花瓶
        "/world/area/lake/npc/item/doll.c": 4,     // 精緻娃娃
        "/world/area/lake/npc/item/pottery.c": 3,  // 未知陶壺
        "/world/area/lake/npc/item/treasury.c": 1, // 木造藏
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
    return "/world/area/lake/npc/seller.c";   // 古董商人
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N仔細的鑑定著拿到的古董。\n"NOR,
        "$N對著$n說道："HIG"雖然不是假貨，但是材質也普普通通啦！\n\n"NOR,
        "$N對著$n說道："HIG"這麼想要落花生就拿去吧！\n"NOR,
        "$N對著$n說道："HIG"下次上門可別又是來買花生的！\n"NOR,
        "$N對著$n說道："HIG"我可是古董商人！不是花生商人！\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "一袋"YEL"落花生"NOR"。\n";
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
    object item;

    item = new("/world/item/peanut.c");
    if( item->move(player) )
        tell_object(player, HIY"(你獲得了一袋落花生。)\n"NOR);
    else {
        // 將給的物品移到與玩家同一格的area區域中
        // 如果是在 area 中，把item移到player所處的座標位置
        if( environment(player)->is_area() ) move_side(item, player);
        // 如果是在 room 中，把item移到player所處的房間中
        else item->move(environment(player));
        tell_object(player, HIY"(你獲得了一袋落花生，但是掉在地上了。)\n"NOR);
    }
}
