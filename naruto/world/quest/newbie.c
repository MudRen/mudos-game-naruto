/*  newbie.c
        
    write by Acme       - 2007.02.07
 */

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
    return "初來乍到";
}

// 任務描述
string getDetail() {
    string msg;
        
    msg  = "這位可面生得很啊，肯定是新來的。\n\n";
    msg += "如果你對這個世界不是很了解，通常你可以觀看說明文件。(指令：help)\n";
    msg += "若是在操作上的不熟悉，也可以求助指令說明。(指令：help cmds)\n\n";
    msg += "另外，你在接受任務後，可以利用 quest 指令來查詢目前已接受的任務。\n";
    msg += "並且可用 quest <編號> 看任務的詳細說明。\n\n";
    msg += "聽說在「新手學堂」的辛心長正想要找你呢！\n";
    msg += "出了「巫師神殿」後，往東走，你便可以看到「新手學堂了」。\n";

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
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/wizard/npc/chi.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：這位可面生得很啊，肯定是新來的。\n",
        "$N對著$n說道：如果你對這個世界不是很了解，通常你可以觀看說明文件。(指令：help)\n",
        "$N對著$n說道：若是在操作上的不熟悉，也可以求助指令說明。(指令：help cmds)\n",
        "$N對著$n說道：另外，你在接受任務後，可以利用 quest 指令來查詢目前已接受的任務。\n",
        "$N對著$n說道：並且可用 quest <編號> 看任務的詳細說明。\n",
        "$N對著$n說道：聽說在「新手學堂」的辛心長正想要找你呢！\n",
        "$N對著$n說道：出了「巫師神殿」後，往東走，你便可以看到「新手學堂了」。\n",
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
    return "/world/area/wizard/npc/zhang.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：你來啦！我等你很久了呢！\n",
        CYN"$N高興的笑了幾聲。\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    return "學習點數 20 點。\n";
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
    player->add_point("learn", 20);
    tell_object(player, HIY"(你獲得了20 點學習點數。)\n"NOR);
}
