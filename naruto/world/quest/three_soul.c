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
    return "三魂";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "青年男子的要求，只要能夠找齊三種魂魄，他就將神獸的心臟製作\n";
    msg += "出來給你。不過為什麼這位男子擁有製作神獸心臟的能力呢？又為\n";
    msg += "什麼滿是神獸的森林中只有他一位人類，這些謎題全都不得而知了\n";
    msg += "。總之先將三魂拿到手再說吧！\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 40;
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
    if( !player->query_temp("know_dragon") ) return 0;
    if( player->query_class() == "hxh_intermediate" ) return 1;
    else if( player->query_class() == "middle" ) return 1;
    else if( player->query_class() == "thief_sea" ) return 1;
    else if( player->query_class() == "soldier_sea" ) return 1;
    else return 0;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/god_forest/npc/man.c";   // 青年男子
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$n將龍空大王被石化與胸前空洞的事情告訴$N\n"NOR,
        CYN"$N無奈地聳聳肩.\n"NOR,
        "$N說道："HIG"難怪最近的神獸森林好像特別亂...\n"NOR,
        "$N說道："HIG"會跑來找隱居的我...想必事情已經發展的很嚴重了。\n"NOR,
        "$N說道："HIG"僅此一次，去拿三魂給我，就幫$n做心臟。\n"NOR,
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
        "/world/area/lv60_area/npc/item/soul1.c": 1,      // 妖魂
        "/world/area/lv60_area/npc/item/soul2.c": 1,      // 龍魂
        "/world/area/lv60_area/npc/item/soul3.c": 1,      // 心魂
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
    return "/world/area/god_forest/npc/man.c";   // 青年男子
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"就是這三樣東西，接下來就交給我吧。\n"NOR,
        CYN"$N拿出一顆木頭雕刻的心臟，唸了一些古語，只見三枚魂魄都飛入心臟中。\n"NOR,
        CYN"接著$N伸出右手姆指往心臟一按，心臟就像擁有了生命般開始跳動。\n"NOR,
        "$N對著$n說道："HIG"好了，這顆心臟就交給你，別再來煩我了。\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = HIY"神獸"RED"心臟"NOR"一顆\n";
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

    item = new("/world/area/lv60_area/npc/item/heart.c");
    if( item->move(player) )
        tell_object(player, HIY"(你將三魂交給青年男子後，得到了神獸心臟。)\n"NOR);
    else {
        // 將給的物品移到與玩家同一格的area區域中
        // 如果是在 area 中，把item移到player所處的座標位置
        if( environment(player)->is_area() ) move_side(item, player);
        // 如果是在 room 中，把item移到player所處的房間中
        else item->move(environment(player));
        tell_object(player, HIY"(你將三魂交給青年男子後，得到了神獸心臟，但是掉在地上了。)\n"NOR);
    }
}
