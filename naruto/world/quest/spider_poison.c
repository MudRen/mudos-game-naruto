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
    return "蜘蛛懸賞";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "鯨魚島上有一個洞穴被一大群邪惡的蜘蛛佔據了，島上的居民都一直\n";
    msg += "過的不是很安心的生活。因此現任的村長決定發出懸賞公告，希望能\n";
    msg += "請有力氣的人幫忙除掉蜘蛛。\n";

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
    if( player->query_level() < 15 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/whale_island/npc/village_head.c";   // 鯨魚島村長
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N正上下打量著$n，似乎正在評估$n的戰鬥能力...\n"NOR,
        "$N微笑地問$n："HIG"$n能幫這個島上的人一件事嗎？\n"NOR,
        "$N愁眉苦臉地說："HIG"之前開鑿通往木葉村的通道...現在居然被一群蜘蛛占領了...\n"NOR,
        "$N說道："HIG"因為牠們數量眾多...我們根本沒辦法應付。\n"NOR,
        "$N說道："HIG"可以幫助我們嗎？獎金是不會少的！\n"NOR,
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
    return ([]);
}

// 完成任務的條件除了系統提供的
// 1. 搜集物品
// 2. 殺了足夠數量的怪物之外
// 有需要的話，還可以自訂完成任務條件
// return 1, 為滿足條件, return 0;為失敗
int postCondition(object player, object npc)
{
    if( !present("__QUEST_D_2__", player) ) return 0;
    return 1;
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/world/area/whale_island/npc/village_head.c";   // 鯨魚島村長
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N看著$n"CYN"高興地大叫一聲 ＯＨ　ＹＡ！！\n"NOR,
        "$N說道："HIG"幹的太好拉！這樣就能繼續開鑿山洞了！\n"NOR,
        "$N說道："HIG"獎金是一瓶毒液 500 元！\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "給予"HIM"蜘蛛毒液"NOR"的獎勵。\n";
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
    int i;

    item = present("__QUEST_D_2__", player);
    i = item->query_amount();

    if( i > 500 ) {
        i = 500;
        item->add_amount(-i);
        message_vision("$N低頭說道﹕"HIG"其實我準備的金額只能付 500 瓶的錢...\n"NOR, npc, player);
        message_vision("$N說道﹕"HIG"其他多的還麻煩$n自己處理掉吧。\n"NOR, npc, player);
    } else {
        destruct(item);
    }
    player->add("bank", i*500);
    tell_object(player, HIY"(你得到了村長給予的 "+i*500+" 元獎勵金)\n"NOR);
    return;
}
