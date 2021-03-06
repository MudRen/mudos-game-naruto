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
    return "生物突變事件";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "近來像蟑螂老鼠一類躲藏在黑暗潮溼空間中的動物昆蟲們，身上都\n";
    msg += "發生了奇特的變化，因為突變而使體積更大，更具有破壞力。上忍\n";
    msg += "童角認為這種事情再不注意，以後可能會影響到其他的生物也接著\n";
    msg += "突變，所以早在任務提出之前就已經開始研究相關的問題了，唯一\n";
    msg += "比較缺乏就是實際和牠們接觸的資料。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 10;
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
    if( player->query("level") < 10 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/world/area/bone/npc/gau.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道："HIG"最近的鼠蟑類突變發生機率愈來愈高了...\n"NOR,
        "$N對著$n說道："HIG"能幫忙我做一些調查嗎？\n"NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/world/area/muye/npc/cockroach4.c": 10,         // 突變蟑螂
        "/world/area/whale_island/npc/cockroach4.c": 10, // 突變海蟑螂
        "/world/area/muye/npc/cockroach5.c": 10,         // 突變大蟑螂
        "/world/area/whale_island/npc/cockroach5.c": 10, // 突變大海蟑螂
        "/world/area/muye/npc/cockroach6.c": 10,         // 突變巨蟑螂
        "/world/area/whale_island/npc/cockroach6.c": 10, // 突變巨海蟑螂
        "/world/area/muye/npc/mouse4.c": 10,             // 突變老鼠
        "/world/area/echo/npc/mouse4.c": 10,             // 突變地鼠
        "/world/area/muye/npc/mouse5.c": 10,             // 突變大老鼠
        "/world/area/echo/npc/mouse5.c": 10,             // 突變肥地鼠
        "/world/area/muye/npc/mouse6.c": 10,             // 突變巨老鼠
        "/world/area/echo/npc/mouse6.c": 10,             // 突變胖地鼠
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
    return "/world/area/bone/npc/gau.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N拿走資料接著說道："HIG"嗯...原來現在已經發展成如此了...\n"NOR,
        "$N高興地說道："HIG"這次任務木葉村會給予$n最高的獎勵！感謝了！\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 800 點。\n";
    msg += "銀子 16000 兩。\n";
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
    player->add_point("learn", 800);
    tell_object(player, HIY"(你獲得了 800 點學習點數。)\n"NOR);
    player->add("bank", 16000);
    tell_object(player, HIY"(你獲得了 16000 兩銀子。)\n"NOR);
}
