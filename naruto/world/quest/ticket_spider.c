#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

/* 此任務是否能重複解  return 0  不能重複
                       return 1  可重複
   建議最好設定不能重複。
 */
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "可憐的蜘蛛人";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "也許是因為獎勵提供的太少，又或者是大家都已經遺忘這位救世主\n";
    msg += "大英雄，總之現在的他已經比當年彼得帕克還要慘了，一位沒有蜘\n";
    msg += "蛛黏液的蜘蛛人，就像釘釘子沒有鐵鎚，玩遊樂器沒有搖桿一樣。\n";
    msg += "希望好心人仕不求報答，幫幫他吧。\n";

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
    if( player->query_skill("lending ticket") < 20 ) return 0;
    if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/sneakhole/npc/spiderman.c";   // 失敗的麵
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N想到傷心處, 忍不住放聲大哭.\n"NOR,
        "$N說道："HIG"我...我...\n"NOR,
        "$N說道："HIG"沒有蜘蛛黏液的我到底算什麼！\n"NOR,
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
        "/world/area/sneakhole/npc/item/mucus.c": 50,   // 蜘蛛黏液
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
    return "/world/area/sneakhole/npc/spiderman.c";   // 失敗的麵
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N瞠目結舌，好像看到了一件不可思議的事。\n"NOR,
        "$N一把鼻涕一把眼淚對著$n說道："HIG"這個世界需要$n！\n"NOR,
        "$N對著$n說道："HIG"這個人情就先欠著了！\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "好像沒什麼獎勵...\n";
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

    item = new("/daemon/skill/hxh/special/obj/spider_ticket.c");
    if( item->move(player) )
        tell_object(player, HIY"(因為失敗的麵欠了你人情，因此你得到一張借貸券。)\n"NOR);
    else {
        // 將給的物品移到與玩家同一格的area區域中
        // 如果是在 area 中，把item移到player所處的座標位置
        if( environment(player)->is_area() ) move_side(item, player);
        // 如果是在 room 中，把item移到player所處的房間中
        else item->move(environment(player));
        tell_object(player, HIY"(因為失敗的麵欠了你人情，因此你得到一張借貸券，但是掉在地上了。)\n"NOR);
    }
}
