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
    return "啟程 - 木葉村";
}

// 任務描述
string getDetail() {
    string msg;
        
    msg  = "這位可面生的很啊，肯定是新來的。來來來，讓我帶你瞧瞧這個世界\n";
    msg += "到底長個什麼樣子。\n\n";
    msg += "據說，在「天上人間」的西邊有個「木葉村」，裡頭有著一群忍者會\n";
    msg += "施展一些奇奇怪怪的忍術的，你應該要去一趟開個眼界才是啊。\n\n";
    msg += "當你在旅遊的時候不小心迷了路，我這裡有一份世界地圖，你就拿去\n";
    msg += "看看吧。(指令：help world)。另外，你可以隨時隨地的在野外查看\n";
    msg += "地圖。(指令：map)。可以馬上瞭解你所身處的位置。\n\n";
    msg += "如果你覺得木葉村太遠了，出去「新手學堂」，往南邊一些，你應該\n";
    msg += "可以找到一間叫「五行傳送館」的地方，裡頭有對新手免費傳送到世\n";
    msg += "界各地的服務。\n\n";
    msg += "什麼！？你不知道怎麼傳送？那我教教你吧，當你到達一處你覺得有\n";
    msg += "異樣的地方時，通常你可以進行搜索(指令：search)。搜索完後有時\n";
    msg += "會意外地發現有特別的事物存在。通常在這個時候，你便可以再進一\n";
    msg += "步的查看(指令：look, 例：look 牌子) 。就可以得到更仔細的訊息\n";
    msg += "了。\n\n";
    msg += "好啦，廢話不多說了，你一定迫不急待的想去「木葉村」瞧瞧了吧，\n";
    msg += "同樣的，當你到達「木葉村」後，去找當地「一樂拉麵館」的老闆說\n";
    msg += "說話吧。\n";

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
    return "/world/area/wizard/npc/zhang.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：這位可面生的很啊，肯定是新來的。來來來，讓我帶你瞧瞧這個世界到底長個什麼樣子。\n",
        "$N對著$n說道：據說，在「天上人間」的西邊有個「木葉村」，裡頭有著一群忍者會施展一些奇奇怪怪的忍術的。\n",
        "$N對著$n說道：你應該要去一趟開個眼界才是啊。\n",
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
    return "/world/area/muye/npc/fooder.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：你好！你好啊！\n",
        "$N對著$n說道：原來是辛心長介紹你來的啊，呵呵，那個老傢伙！\n",
        CYN"$N快樂的手舞足蹈。\n"NOR,
        "$N對著$n說道：來！我請你一碗精心熬煮的豚骨拉麵。\n",
    });
        
    return msg;
}

string getReward()
{
    string msg = "學習點數 50 點。\n";
    msg += "一碗豚骨拉麵。\n";
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
    object food;

    player->add_point("learn", 50);
    tell_object(player, HIY"(你獲得了 50 點學習點數。)\n"NOR);

    food = new("/world/drug/noodle.c");
    if( food->move(player) )
        tell_object(player, HIY"(你獲得了一碗豚骨拉麵。)\n"NOR);
    else {
        if( !environment(player)->is_area() ) {
            food->move(environment(player));
        } move_side(food, player);  // 將food移到與player同一格的area區域中
        tell_object(player, HIY"(你獲得了一碗豚骨拉麵，但是掉在地上了。)\n"NOR);
    }
}
