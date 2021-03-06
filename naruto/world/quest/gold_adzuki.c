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
    return "黃金紅豆";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "御手洗家的紅豆園所種植的是最優良品質的紅豆，每年大大小小都\n";
    msg += "得了不少比賽的獎，最近這幾年卻很少聽說他們的紅豆得獎，原因\n";
    msg += "是一群盜賊亂開闢秘密基地，破壞了御手洗家土地的地質，讓能種\n";
    msg += "植紅豆的地方變少了，再加上那群盜賊還三不五十跑來田裡偷紅豆\n";
    msg += "回去充饑，頗令御手洗家煩惱。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 30;
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
    if( player->query("level") < 30 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/muye/npc/dou.c";   // 御手洗紅豆
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N低頭沉思.\n"NOR,
        "$N自言自語："HIG"該怎麼樣才能趕走那些盜賊呢...\n"NOR,
        "$N自言自語："HIG"我還要顧著中忍考場...有人能幫我就好了。\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/wild/npc/scar_bandit.c": 5,  // 刀疤盜
        "/world/area/wild/npc/lame_bandit.c": 5,  // 跛足盜
        "/world/area/wild/npc/ren_bandit.c": 5,   // 仁間盜
    ]);
    return kill;
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
    return 1;
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/world/area/muye/npc/dou.c";   // 御手洗紅豆
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"家族裡的人通知我說盜賊好像開始撤離了。\n"NOR,
        "$N對著$n說道："HIG"原來是因為$n在幫忙趕走他們。\n"NOR,
        "$N對著$n說道："HIG"為了答謝$n，我就送給$n我們家族精產的紅豆吧。\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "一罐"HIY"黃金紅豆"NOR"。\n";
    msg += "銀子 1500 兩。\n";
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

    item = new("/world/item/gold_adzuki.c");
    if( item->move(player) )
        tell_object(player, HIY"(你獲得了一罐黃金紅豆。)\n"NOR);
    else {
        // 將給的物品移到與玩家同一格的area區域中
        // 如果是在 area 中，把item移到player所處的座標位置
        if( environment(player)->is_area() ) move_side(item, player);
        // 如果是在 room 中，把item移到player所處的房間中
        else item->move(environment(player));
        tell_object(player, HIY"(你獲得了一罐黃金紅豆，但是掉在地上了。)\n"NOR);
    }
    player->add("bank", 1500);
    tell_object(player, HIY"(你獲得了 1500 兩銀子。)\n"NOR);
}
