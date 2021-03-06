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
    return "雜草叢生";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "鯨魚島老婆婆的家裡長滿了雜草，但是她年事已高沒辦法做這種粗活\n";
    msg += "，所以要找尋願意幫忙他拔草的人。\n";

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
    // 鯨魚島只有獵人海賊可接
    if( player->query_class() != "little_sea" && player->query_class() != "hxh_initial" ) return 0;
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
        "$N哭著說道："HIG"後院長滿雜草看起來好亂！\n"NOR,
        "$N哭著說道："HIG"有好心人可以幫助我嗎！\n"NOR,
        "$N哭著說道："HIG"只要幫我拔一百根就可以了！\n"NOR,
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
    if( player->query_temp("woman_herb") < 100 ) return 0;
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
        CYN"$N高興地放聲大哭。\n"NOR,
        "$N對著$n說道："HIG"就是有像$n這樣的「好人」！婆婆太感動了！\n"NOR,
        CYN"$n彷彿聽到什麼不對勁的話...顏面有些抽搐。\n"NOR,
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

    item = new("/world/area/benthal/npc/wp/gaff.c");

    player->delete_temp("woman_herb");
    if( item->move(player) )
        tell_object(player, HIY"(老婆婆拿出一把珍藏多年的魚叉交給了你。)\n"NOR);
    else {
        // 將給的物品移到與玩家同一格的area區域中
        // 如果是在 area 中，把item移到player所處的座標位置
        if( environment(player)->is_area() ) move_side(item, player);
        // 如果是在 room 中，把item移到player所處的房間中
        else item->move(environment(player));
        tell_object(player, HIY"(老婆婆拿出一把珍藏多年的魚叉交給了你，但是掉在地上了。)\n"NOR);
    }
}
