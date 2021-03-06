#include <ansi.h>

// 說明這是一個陣營檔
int isCamp() { return 1; }

// 陣營名稱
string getName() { return "蛇人"; }

// 友好陣營
string* getFriendly() { return ({}); }

// 敵對陣營
string* getAdversely() { return ({ "orc", "wheya", }); }

// (4) 崇拜, (3) 崇敬, (2) 尊敬, (1) 友好, (0) 中立, (-1) 冷淡, (-2) 敵視, (-3) 敵對, (-4) 仇恨

// 玩家在該陣營的聲望低於多少時會被Auto kill，預設的值是-3
int getHate() { return -2; }

// Auto Kill 時，所要喊的話, $N是自已, $n是對方
string getHateMsg() {
    switch( random(3) ) {
        case 0: return HIR"$N似乎得不到滿足的大喊：殺殺殺！更多的血！哭喊吧$n！\n"NOR; break;
        case 1: return HIR"$N喊著：施予我族更多的鮮血！$n只不過是其中之一！\n"NOR; break;
        case 2: return HIR"$N偉大的蛇神！請接受$n的鮮血吧！\n"NOR; break;
    }
}

// 玩家在敵對陣營的聲望高於多少時會被Auto kill, 預設的值是 3
int getAdvHate() { return 2; }

// 目對敵對陣營時Auto kill要喊的話, $N時自已, $n是對方
string getAdvHateMsg() {
    return HIR"$N高舉著武器大喊：今日我們就要獻上$n的血肉祭祀蛇神和死去的同胞！\n"NOR;
}
