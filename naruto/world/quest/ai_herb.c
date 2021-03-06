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
    return "雜亂無章";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "木葉村愛子小姐的家裡長滿了雜草，但是她身為愛子家的大小姐，不\n";
    msg += "想做這種粗活，所以想使喚別人來幫她拔草。\n";

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
    // 木葉村只有忍者海軍可接
    if( player->query_class() != "inferior" && player->query_class() != "work_sea" ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/muye/npc/ai.c";   // 愛子小姐
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"之前請的園丁辭職之後後院就一片凌亂！\n"NOR,
        "$N說道："HIG"我需要人幫我把後面的雜草清理一下了！\n"NOR,
        "$N說道："HIG"只要拔一百根就可以了！\n"NOR,
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
    if( player->query_temp("ai_herb") < 100 ) return 0;
    return 1;
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/world/area/muye/npc/ai.c";   // 愛子小姐
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N點了點頭，表示讚揚。\n"NOR,
        "$N對著$n說道："HIG"看$n行動蠻迅速的，要不要做我們家的園丁？\n"NOR,
        CYN"$n的頭上瞬間冒出三條黑線...\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "不知道獎勵是什麼。\n";
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

    item = new("/world/item/rod.c");

    player->delete_temp("ai_herb");
    if( item->move(player) )
        tell_object(player, HIY"(愛子小姐將他老爸珍藏的釣竿送給你了。)\n"NOR);
    else {
        // 將給的物品移到與玩家同一格的area區域中
        // 如果是在 area 中，把item移到player所處的座標位置
        if( environment(player)->is_area() ) move_side(item, player);
        // 如果是在 room 中，把item移到player所處的房間中
        else item->move(environment(player));
        tell_object(player, HIY"(愛子小姐將他老爸珍藏的釣竿送給你，但是掉在地上了。)\n"NOR);
    }
}
