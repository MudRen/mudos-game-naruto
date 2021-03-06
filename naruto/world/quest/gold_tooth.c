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
    return "木葉村流浪忍者";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "木葉村附近的流浪忍者，為了籌措跑路資金當起了強盜，其基地在一\n";
    msg += "個秘密的地點，不是尋常人可以發現的。你必須到木葉村的任務接洽\n";
    msg += "所接下這個任務後，可以去跟木葉村上忍 伊乃森喜比 探聽有關這群\n";
    msg += "流浪忍者的秘密基地在何方。\n";

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
    if( player->query_level() < 40 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/muye/npc/bi.c";   // 伊乃森喜比
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N盯著$n看了幾眼，似乎認同$n的實力了。\n"NOR,
        "$N說道："HIG"嗯，來的好。\n"NOR,
        "$N說道："HIG"最近木葉村附近出現了一些流浪忍者，正需要高手幫忙。\n"NOR,
        "$N說道："HIG"幫我消滅他們吧，然後把盜賊黃金牙帶回來給我。\n"NOR,
        CYN"$N低頭沉思.\n"NOR,
        "$N說道："HIG"聽說他們最近拋棄忍道學習了一種名叫念的技巧。\n"NOR,
        "$N說道："HIG"$n自己注意吧。\n"NOR,
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
    if( !present("bandit's tooth", player) ) return 0;
    return 1;
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/world/area/muye/npc/bi.c";   // 伊乃森喜比
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N點點頭，似乎對$n感到十分讚賞。\n"NOR,
        "$N說道："HIG"幹的不錯，獎勵一根黃金牙 10000 元如何？\n"NOR,
        CYN"$N低頭沉思.\n"NOR,
        "$N說道："HIG"不過我沒記錯那些忍者好像只有一百位...\n"NOR,
        "$N說道："HIG"多的黃金牙我就不收了。\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "給予"HIY"盜賊黃金牙"NOR"的獎勵。\n";
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

    item = present("bandit's tooth", player);
    i = item->query_amount();

    if( i > 100 ) {
        i = 100;
        item->add_amount(-i);
    } else {
        destruct(item);
    } 
    player->add("bank", i*10000);
    tell_object(player, HIY"(你得到了伊乃森喜比給予的 "+i*10000+" 元獎勵金)\n"NOR);
    return;
}
