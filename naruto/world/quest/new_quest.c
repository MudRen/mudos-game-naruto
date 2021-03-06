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
    return "任務教學";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "查詢任務欄有沒有發現任務完成的條件阿？\n";
    msg += "沒錯！這個任務的完成條件就是布衣兩件和十兩銀子！\n\n";
    msg += "首先銀子是可以堆疊的物品，也就是一兩銀子、二兩銀子...等等\n";
    msg += "像布衣屬於不可堆疊的物品，身上只要多一件就會多佔一個空間，\n";
    msg += "記住喔！物品需在"HIY"交給委託人(ask 委託人)"NOR"後才會記數！\n";
    msg += "還要提到一點是，物品"HIY"可以分開"NOR"交給委託人喔！\n";
    msg += "所以往後如果遇到要求很多物品的任務，可以考慮分批給喔！\n";
    msg += "而殺死 Mob 就會自動記數了！\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 1;
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
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/wizard/npc/eqer.c";  // 防大師
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"看到我的名字最前面那個"BLINK+HIY"！"NOR+HIG"吧。\n"NOR,
        "$N說道："HIG"只要等級或是其他需求達到，許多 NPC 都有任務可接。\n\n"NOR,
        "$N說道："HIG"我這次是教$n有關任務事件的簡單小任務。\n"NOR,
        "$N說道："HIG"結束後會得到我做的盔甲一件。\n"NOR,
        "$N說道："HIG"想要學習就按 "HIY"y"NOR" 吧。\n\n"NOR,
        "$N說道："HIG"在接下任務後可以用 quest 指令查詢相關資訊。(help quest)\n"NOR,
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
        "/world/eq/cloth/cloth.c": 2,     // 布衣
        "/obj/money/silver.c": 10,        // 銀子
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
    return "/world/area/wizard/npc/eqer.c";  // 防大師
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"這樣應該清楚物品任務相關的事件了吧。\n"NOR,
        "$N說道："HIG"這個是剛才約好要交給你的盔甲。\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "一件新生布甲。\n";
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
    object eq;

    eq = new("/world/eq/armor/armor.c");
    if( eq->move(player) )
        tell_object(player, HIY"(你獲得了一件新生布甲。)\n"NOR);
    else {
        // 將給的物品移到與玩家同一格的area區域中
        // 如果是在 area 中，把eq移到player所處的座標位置
        if( environment(player)->is_area() ) move_side(eq, player);
        // 如果是在 room 中，把eq移到player所處的房間中
        else eq->move(environment(player));
        tell_object(player, HIY"(你獲得了一件新生布甲，但是掉在地上了。)\n"NOR);
    }
}
