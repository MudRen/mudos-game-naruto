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
    return "咖哩辣椒Ｂ";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "阿飛給你的任務，叫你去天上人間殺死關公派來的三位市井無賴。\n";

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
    if( player->query("level") < 15 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/rural_area/npc/fe.c";   // 阿飛
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N非常害怕的大聲尖叫﹗﹗\n"NOR,
        "$N驚慌地說道："HIG"$n是誰！不是關公派來的殺手吧！\n"NOR,
        "$N說道："HIG"什麼！原來是想要辣椒粉！\n"NOR,
        "$N說道："HIG"去殺了天上人間的市井無賴！他們是關公派來追殺我的！\n"NOR,
        "$N說道："HIG"好像有三個人吧？...殺死他們就給$n辣椒粉！\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/npc/vagabond.c": 3,  // 市井無賴
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
    return "/world/area/rural_area/npc/fe.c";   // 阿飛
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N瞠目結舌，好像看到了一件不可思議的事。\n"NOR,
        "$N對著$n說道："HIG"$n這傢伙蠻有加入黑社會的天份麻！\n"NOR,
        "$N對著$n說道："HIG"要不要加入...不對。\n"NOR,
        CYN"$N低頭沉思.\n\n"NOR,
        "$N慚愧地對$n唱道："HIG"我阿飛勸大家說∼入黑社會沒前途∼\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "一包"HIR"辣椒粉"NOR"。\n";
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
    item = new("/world/area/rural_area/item/powder02.c");
    if( item->move(player) )
        tell_object(player, HIY"(你獲得了一包辣椒粉。)\n"NOR);
    else {
        // 將給的物品移到與玩家同一格的area區域中
        // 如果是在 area 中，把item移到player所處的座標位置
        if( environment(player)->is_area() ) move_side(item, player);
        // 如果是在 room 中，把item移到player所處的房間中
        else item->move(environment(player));
        tell_object(player, HIY"(你獲得了一包辣椒粉，但是掉在地上了。)\n"NOR);
    }
}
