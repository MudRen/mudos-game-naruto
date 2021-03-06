/* 水井 well.c
*/

#include <ansi.h>

// 屬於建築學技能下的產品
string getProSkill() { return "architecture"; }

// 習得此產品必要的技能等級
int getLearnLevel() { return 0; }

// 物品名稱
string getName() { return "水井"; }

// 簡述
string getBrief() {
    return "在地上挖一口水井...";
}

// 詳述
string getDetail() {
    string msg = "";
    msg += "你可以任意的在有合法建地的地方挖一口井，並訓練你的建築學技巧\n";
    msg += "最高到二十級，據說挖出來的井有特殊的效用...\n";
    msg += "\n";
    msg += "水井相關指令：\n";
    msg += "    1. short,  設定水井的短敘述。(最長十個字元)\n";
    msg += "    2. long,  設定水井的長敘述。(最長五十個字元, 使用to long效果最好)\n";
    msg += "    3. drink, 舀水來喝，據說有神奇的效果。(一小時一次)\n";
    msg += "\n";
    msg += "建造需求：\n";
    msg += "    學習點數 10000 點。\n";
    msg += "\n";
    return msg;
}

// 製造此產品所需的材料
mapping getStuff() {
    mapping stuff = ([
        "/world/area/wizard/npc/obj/shovel.c": 3,  // 鏟子
    ]);
    return stuff;
}

// 製造的產品檔
string getProduct() {
    return 0;
}

// 製造產品時的訊息
string makeMsg()
{
    return "$N拿起身上的鏟子，左手一把，右手一把，嘴裡還咬著一把，自以為是索隆的往地上狂挖。\n";
}

// 產品是否綁定(也就是製造的人才能用), (1:是, 0:否)
// 註：綁定的產品最好是不能合併的物品，否則綁定會混亂
//     綁定的產品上會設定 set("binding", 角色id)
//     所以要判斷該產品是否能被使用就是檢查 binding 是否符合玩家的id就行了
int isBinding() { return 0; }

// 可以自訂製作條件
int preCondition(object player)
{
int x, y;
    if( !environment(player) ) return 0;
    
    if( player->query_point("learn") < 10000 ) {
        tell_object(player, "你的學習點數不足 10000 無法使用挖井技巧。\n");
        return 0;
    }

    if( !environment(player)->is_area() ) {
    tell_object(player, "你不能在這裡挖井...\n");
        return 0;
    }
    x = player->query("area_info/x_axis");
    y = player->query("area_info/y_axis");
    
    if( !environment(player)->createBuilding("well_11_eswn", player->query_id(), x, y) ) {
        tell_object(player, "你沒有辦法在這裡挖井...\n");
        return 0;
    }
    
    player->add_point("learn", -10000);
    player->save();
    
    return 1;
}

// 可以自訂製作後效果
int postCondition(object player)
{
    message_vision(HIW"$N只用了三把鏟子就挖出了一口井，實在是太神奇了！！\n"NOR, player);

    // 大於20級不能提升
    if( player->getProSkillLevel("architecture") < 20 ) 
        player->addProLevel("architecture");

    return 1;
}
