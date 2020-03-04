#include <ansi.h>
inherit F_DBASE;

// 表示是一個戰爭檔
int isWar() { return 1; }

// 戰爭的持續時間
// 如果設為0, 表示戰爭的持續時間自行設定，不由系統控制
int getDuration() { return 0; }

private void create() 
{
    seteuid(getuid());
    set("channel_id", "眼魔部族");
}

void doChat(string str)
{
    CHANNEL_D->do_channel( this_object(), "war",HIR + str + "\n"+NOR);
}

// 開始戰爭所要執行的操作
// 傳回 1 表示戰爭啟動, 0 表示沒啟動
int doStartWar(object player)
{
    return 0;
}

// 結束戰爭所要執行的操作
// 傳回 1 表示戰爭結束, 0 表示沒結束
int doEndWar(object player)
{
    return 0;
}

void doHeartBeat()
{
}
