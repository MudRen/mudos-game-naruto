/* 羽毛繃帶 plume_bandage.c
*/

// 屬於急救技能下的產品
string getProSkill() { return "first-aid"; }

// 習得此產品必要的技能等級
int getLearnLevel() { return 10; }

// 物品名稱
string getName() { return "羽毛繃帶"; }

// 簡述
string getBrief() {
    return "可以馬上恢復 HP 300 的繃帶。";
}

// 詳述
string getDetail() {
    string msg = "";
    msg += "可以馬上恢復 HP 300 的繃帶。\n";
    msg += "急救等級小於20級時，製作後有機會提升急救等級。\n";
    return msg;
}

// 製造此產品所需的材料
mapping getStuff() {
    mapping stuff = ([
        "/world/area/muye/npc/item/plume.c": 1,  // 羽毛
    ]);
    return stuff;
}

// 製造的產品檔
string getProduct() {
    return "/world/pro_skill/first-aid/plume_bandage.c";
}

// 製造產品時的訊息
string makeMsg()
{
    return "$N手上搓來搓去的，開始製造「羽毛繃帶」。\n";
}

// 產品是否綁定(也就是製造的人才能用), (1:是, 0:否)
// 註：綁定的產品最好是不能合併的物品，否則綁定會混亂
//     綁定的產品上會設定 set("binding", 角色id)
//     所以要判斷該產品是否能被使用就是檢查 binding 是否符合玩家的id就行了
int isBinding() { return 0; }

// 可以自訂製作條件
int preCondition(object player)
{
    return 1;
}

// 可以自訂製作後效果
int postCondition(object player)
{
    // 大於20級不能提升
    if( player->getProSkillLevel("first-aid") >= 20 )
        return 1;

    // 有機會, 急救升一級
    if( random(100) > 60)
        player->addProLevel("first-aid");

    return 1;
}
