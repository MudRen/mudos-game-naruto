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
    return "護身符";
}

// 任務描述
string getDetail() {
    string msg;
        
    msg  = "這位施主看起來印堂發黑，近期之內可能會發生血光之災啊，不可不\n";
    msg += "慎啊！\n\n";
    msg += "俗話說的好：有燒香有保佑，沒燒香會出事情！\n\n";
    msg += "你只要貢獻一點香油錢，我可能保證你這陣子絕對平安，不會發生任";
    msg += "何意外\n\n";
    msg += "任務需求：\n";
    msg += "    銀子 1000000 兩。\n";
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
    return "/world/area/wizard/npc/temple_master.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"這位施主看起來印堂發黑，近期之內可能會發生血光之災啊，不可不慎啊！\n"NOR,
        "$N對著$n說道："HIG"俗話說的好：有燒香有保佑，沒燒香會出事情！\n"NOR,
        "$N對著$n說道："HIG"你只要貢獻一點香油錢，我可能保證你這陣子絕對平安，不會發生任何意外。\n"NOR,
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
    if( player->query("bank") < 1000000 ) return 0;
    return 1;
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/world/area/wizard/npc/temple_master.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道："HIG"很好很好！看來你是想通了，來來來，這個護身符拿去吧。\n"NOR,
        "$N對著$n說道："HIG"它可以保佑你平安的。\n"NOR,
    });
        
    return msg;
}

string getReward()
{
    string msg = "一個護身符。\n";
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
    object amulet;

    amulet= new("/world/item/amulet.c");
    if( amulet->move(player) ) {
        tell_object(player, HIY"(你獲得了一個護身符。)\n"NOR);
    } else {
        if( !environment(player)->is_area() ) {
            amulet->move(environment(player));
            tell_object(player, HIY"(你獲得了一個護身符，但是掉在地上了。)\n"NOR);
        } else {
            move_side(amulet, player);
            tell_object(player, HIY"(你獲得了一個護身符，但是掉在地上了。)\n"NOR);
        }
    }
    player->add("bank", -1000000);
}
