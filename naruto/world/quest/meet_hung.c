/*  travel_muye.c
        
    write by Acme       - 2007.02.05
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
    return "瞭解獵人職業";
}

// 任務描述
string getDetail() {
    string msg;
        
    msg  = "如果你想瞭解獵人職業特色的話，你可以去請教「獵人補習學校」的杭鐵管。\n";
    msg += "位置就在出了「米特的酒店」的西北方，你應該很容易可以找到的。\n";

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
    return "/world/area/whale_island/npc/village_head.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：如果你想瞭解獵人職業特色的話，你可以去請教「獵人補習學校」的杭鐵管。\n",
        "$N對著$n說道：位置就在出了「米特的酒店」的西北方，你應該很容易可以找到的。\n",
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
    return "/world/area/whale_island/npc/teacher.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：你好！\n",
        CYN"$N愉快的微笑著。\n"NOR,
        "$N對著$n說道：你想瞭解獵人是什麼啊？\n",
        "$N對著$n說道：獵人就是可以利用念能力施展各種念力的職業。\n",
        "$N對著$n說道：而念能力大約可以分三大類。\n",
        "$N對著$n說道：第一：強化系、第二：變化系、第三：具現系、第四：放出系、第五：操作系、第六：特質系\n",
        "$N對著$n說道：想成為參加獵人補習嗎？我們非常歡迎你的「報名」\n",
        "$N對著$n說道：如果你已經是我們的學員，而且想試試看「模擬考」的話，可以來找我。(指令：say 模擬考)\n",
    });
        
    return msg;
}

string getReward()
{
    return "學習點數 20 點";
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
    tell_object(player, HIY"(你獲得了 20 點學習點數。)\n"NOR);
}
