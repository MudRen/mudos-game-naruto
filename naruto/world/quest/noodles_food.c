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
    return "拉麵食材";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "木葉村拉麵店老闆想要研發新的拉麵，因此委託人幫忙他尋找新拉麵\n";
    msg += "最重要的使用材料，就是遠在秘林中熊的熊掌。\n";

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
    if( player->query_level() < 25 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/muye/npc/fooder.c";   // 拉麵店老闆
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N發呆了很久，因為$n的來到嚇了一跳差點跌到椅子下。\n"NOR,
        "$N說道："HIG"原來是$n阿！嚇了我一跳！\n"NOR,
        CYN"$N臉上露出邪惡的笑容。\n"NOR,
        "$N說道："HIG"因為$n剛才嚇到我了，就幫我個忙吧！\n"NOR,
        "$N說道："HIG"我需要大量的熊掌，如果拿回來我會給$n獎勵的！\n"NOR,
        "$N說道："HIG"不過最多只要 100 隻阿，太多恐怕會壞掉呢！\n"NOR,
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
    if( !present("_BEAR_PAW_", player) ) return 0;
    return 1;
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/world/area/muye/npc/fooder.c";   // 拉麵店老闆
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N興奮地又跳又叫，一不小心將拉麵湯鍋打翻了，燙的自己哇哇叫。\n"NOR,
        "$N說道："HIG"真是太棒了！這下子又有材料可以繼續研發拉！\n"NOR,
        "$N說道："HIG"獎勵就這樣算吧！一根熊掌 3000 元！\n"NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "給予"HIK"熊掌"NOR"的獎勵。\n";
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

    item = present("_BEAR_PAW_", player);
    i = item->query_amount();

    if( i > 100 ) {
        i = 100;
        item->add_amount(-i);
    } else {
        destruct(item);
    } 
    player->add("bank", i*3000);
    tell_object(player, HIY"(你得到了拉麵店老闆給予的 "+i*3000+" 元獎勵金)\n"NOR);
    return;
}
