/* sand_hole.c
*/
#define OPEN_WAR 5
#include <ansi.h>
inherit F_DBASE;

// 表示是一個戰爭檔
int isWar() { return 1; }

int number;

// 戰爭的持續時間
// 如果設為0, 表示戰爭的持續時間自行設定，不由系統控制
int getDuration() { return 300; }   // 持續5分鐘

mapping record = ([
    0: ([ "name": HIK"陰影巢穴"NOR,
          "file": "/world/area/whale_island/hole.c",
          "x": 20,
          "y": 15, ]),
    1: ([ "name": HIK"陰影巢穴-B1"NOR,
          "file": "/world/area/whale_island/hole_1f.c",
          "x": 20,
          "y": 20, ]),
    2: ([ "name": GRN"秘之小穴"NOR,
          "file": "/world/area/wild/hole.c",
          "x": 19,
          "y": 11, ]),
    3: ([ "name": HIG"戰事林"NOR,
          "file": "/world/area/bone/fight.c",
          "x": 41,
          "y": 31, ]),
    4: ([ "name": HIK"陰影小徑"NOR,
          "file": "/world/area/sneakhole/path.c",
          "x": 20,
          "y": 40, ]),
]);

private void create() 
{
    seteuid(getuid());
    set("channel_id", "戰爭精靈");
}

private int getPlayerCnt(object area)
{
    int i, size, cnt = 0;
    object *inv;

    inv = all_inventory(area);
    size = sizeof(inv);

    for(i=0; i<size; i++)
        if( userp(inv[i]) ) cnt += 1;

    return cnt;
}

private void moveCorrectCoord(object mob, object room, int room_id)
{
    int x, y, ok = 0;

    while( ok == 0 ) {
        x = random(record[room_id]["x"]);
        y = random(record[room_id]["y"]);

        if( !room->query_data(x, y, "block") )
            ok = 1;
    }
    area_move(room, mob, x, y);
}

private void createDoctor(object player, object room, int room_id, int kill_lv)
{
    object mob;
    string leader_name;
    string npc_path = "/world/area/sand_hole/npc/";

    // 先召一隻帶頭的
    mob = new(npc_path + "doctor.c");
    mob->set("SAND_KILL", record[room_id]["file"]);
    leader_name = mob->query("name");

    // 隨機移至某一格
    moveCorrectCoord(mob, room, room_id);

    // 敘述就放在帶頭的這裡，預防 call_out 沒判定到
    CHANNEL_D->do_channel( player, "war", YEL" 朗聲說道："HIW+leader_name+NOR+YEL"快點整裝，這次的任務就交給你了！\n\n"NOR+YEL"\t沙穴兄弟們沒錢吃穿，這次將前往"NOR+record[room_id]["name"]+YEL"大肆略奪一番！\n\n"NOR+YEL"還望"HIR"["+chinese_number(kill_lv)+"級]"NOR+YEL"以上的各路英雄們不吝色將身上的財物交給咱！兄弟們上阿！\n\n\n"NOR);
}

private void createBandit(object player, object room, int room_id, int kill_lv)
{
    object mob;
    int i, cnt = 15;
    string npc_path = "/world/area/sand_hole/npc/";

    // 其它雜魚
    for(i=0; i<cnt; i++) {
        mob = new(npc_path + "bandit.c");
        mob->set("level_kill", kill_lv);
        moveCorrectCoord(mob, room, room_id);
    }
}

// 開始戰爭所要執行的操作
// 傳回 1 表示戰爭啟動, 0 表示沒啟動
int doStartWar(object player)
{
    int i, x, y;
    int kill_lv, room_id;
    object room;

    // 隨機取得某區域
    room_id = random(sizeof(record));
    number = room_id;
    room = load_object(record[room_id]["file"]);
    kill_lv = 21 + random(20);

    // 沒辦法載入區域
    if( !objectp(room) ) return 0;

    // 這個區域玩家人數不足，不會開戰爭
    if( getPlayerCnt(room) < OPEN_WAR ) return 0;

    // 載入相關NPC
    createDoctor(player, room, room_id, kill_lv);
    call_out("createBandit", 5, player, room, room_id, kill_lv);
    call_out("createBandit", 10, player, room, room_id, kill_lv);

    // 寫這個讓 mob 自己去判斷要不要閃人
    room->set("SAND_WAR", 1);

    return 1;
}

// 結束戰爭所要執行的操作
// 傳回 1 表示戰爭結束, 0 表示沒結束
int doEndWar(object player)
{
    // mob的刪除改由 mob 自己判斷，減少 map 的負擔與 bug...
    object room;
    room = load_object(record[number]["file"]);

    // 沒辦法載入區域
    if( !objectp(room) ) return 0;

    room->delete("SAND_WAR");

    CHANNEL_D->do_channel( this_object(), "war",YEL"龍角散豪邁的說道：這次成果似乎不太好阿！散拉各位兄弟！"NOR);
    return 1;
}

void doHeartBeat()
{
}
