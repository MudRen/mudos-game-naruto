#include <ansi.h>

// 說明這是一個陣營檔
int isCamp() { return 1; }

// 陣營名稱
string getName() { return "沙穴強盜"; }

// 友好陣營
string* getFriendly() { return ({}); }

// 敵對陣營
string* getAdversely() { return ({ "hunter" }); }

// (4) 崇拜, (3) 崇敬, (2) 尊敬, (1) 友好, (0) 中立, (-1) 冷淡, (-2) 敵視, (-3) 敵對, (-4) 仇恨

// 玩家在該陣營的聲望低於多少時會被Auto kill，預設的值是-3
int getHate() { return -2; }

// Auto Kill 時，所要喊的話, $N是自已, $n是對方
string getHateMsg() {
    switch( random(3) ) {
        case 0: return HIR"$N邪惡地笑了幾聲大喊：喂！$n！還不把身上的錢財交出來！\n"NOR; break;
        case 1: return HIR"$N邪惡地笑著說道：送錢送到家門口...$n還真好心阿！\n"NOR; break;
        case 2: return HIR"$N向前一跳，哇哇大叫：闖進別人家裡不知道給過路費阿！\n"NOR; break;
    }
}

// 玩家在敵對陣營的聲望高於多少時會被Auto kill, 預設的值是 3
int getAdvHate() { return 3; }

// 目對敵對陣營時Auto kill要喊的話, $N時自已, $n是對方
string getAdvHateMsg() {
    return HIR"$N鬼吼鬼叫著：最討厭像$n這種自以為英雄的人！去死吧！\n"NOR;
}
