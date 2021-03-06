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
    return "年輕的滋味";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "鯨魚島的老婆婆突然很想再嘗嘗年輕的時候自己做的綠豆酥，因為\n";
    msg += "需要的材料是古老森林裡土著在吃的果實，這兩種東西憑著老婆婆\n";
    msg += "的身子骨是絕對拿不到的，別說和土著搶果實，就連樹都爬不上去\n";
    msg += "了吧！盡你的力量幫忙老婆婆吃到綠豆酥吧。\n";

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
    return "/world/area/whale_island/npc/oldwoman.c";   // 老婆婆
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N無奈地凝望著天空...\n"NOR,
        "$N兩眼無神地抓著$n："HIG"$n行行好，幫忙我這個老婆婆一個忙吧。\n"NOR,
        "$N兩眼無神地抓著$n："HIG"突然好想吃年輕的時候自己做的綠豆酥。\n"NOR,
        "$N兩眼無神地抓著$n："HIG"但需要古老森林裡土著所吃的果實，能幫我拿嗎？\n"NOR,
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
        "/world/area/old_forest/npc/item/fruit.c": 6,   // 樹果
        "/world/area/old_forest/npc/item/fruit3.c": 6,  // 乾果
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
    return "/world/area/whale_island/npc/oldwoman.c";   // 老婆婆
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N高興的跳起舞來!!!\n"NOR,
        "$N對著$n說道："HIG"是果實阿！這樣想做出好吃的綠豆就不是問題了！\n\n"NOR,
        CYN"$N升起火來，將果實丟進火堆中。\n"NOR,
        CYN"當煙竄起後...$N將綠豆放在竹簍中在煙上燻烤。\n\n"NOR,
        CYN"一會功夫...傳說中的綠豆就完成了。\n"NOR,
        "$N對著$n說道："HIG"哈哈！完成了！這些煙勳過的綠豆就給$n當做謝禮吧！\n"NOR,
        "$N說道："HIG"婆婆我要開始做綠豆酥啦！\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "一簍"HIG"煙燻綠豆"NOR"。\n";
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

    item = new("/world/item/smoke_mung.c");
    if( item->move(player) )
        tell_object(player, HIY"(你獲得了一簍煙燻綠豆。)\n"NOR);
    else {
        // 將給的物品移到與玩家同一格的area區域中
        // 如果是在 area 中，把item移到player所處的座標位置
        if( environment(player)->is_area() ) move_side(item, player);
        // 如果是在 room 中，把item移到player所處的房間中
        else item->move(environment(player));
        tell_object(player, HIY"(你獲得了一簍煙燻綠豆，但是掉在地上了。)\n"NOR);
    }
}
