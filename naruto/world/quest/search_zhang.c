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
    return "尋找老張";
}

// 任務描述
string getDetail() {
    string msg;
        
    msg  = "因為一直拜託別人去帶回牛肉麵實在是太沒效率了！王百萬這次決\n";
    msg += "定請人把老張帶回家中，只要能夠把老張帶回獎金肯定豐富！\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 2;
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
    if( player->query("level") < 2 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/echo/npc/wang.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N眨眨眼! 一對會說話的眼睛閃閃動人!\n"NOR,
        "$N對著$n說道："HIG"$n就是來幫我找老張的嗎？\n"NOR,
        "$N對著$n說道："HIG"只要能把老張帶回來幫我煮麵，獎金不是問題！\n"NOR,
        "$N對著$n說道："HIG"聽說有人在咆哮墓林看過他！快去快回喔！\n"NOR,
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
    return 1;
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/world/area/echo/npc/zhang.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N「唉」的一聲嘆了口氣。\n"NOR,
        "$N難過地說道："HIG"我的女兒被蛇人抓去了！現在哪有心情做麵呢？\n"NOR,
        "$N對著$n說道："HIG"不過$n這麼辛苦的跑來了，讓$n空手回去也不好意思。\n"NOR,
        "$N對著$n說道："HIG"這點東西你就收下吧。\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 100 點。\n";
    msg += "銀子 500 兩。\n";
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
    player->add_point("learn", 100);
    tell_object(player, HIY"(你獲得了 100 點學習點數。)\n"NOR);
    player->add("bank", 500);
    tell_object(player, HIY"(你獲得了 500 兩銀子。)\n"NOR);
}

