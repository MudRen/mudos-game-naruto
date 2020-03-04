/* sand_hole.c
*/
#define OPEN_WAR 5
#include <ansi.h>
inherit F_DBASE;

// ��ܬO�@�ӾԪ���
int isWar() { return 1; }

int number;

// �Ԫ�������ɶ�
// �p�G�]��0, ��ܾԪ�������ɶ��ۦ�]�w�A���Ѩt�α���
int getDuration() { return 300; }   // ����5����

mapping record = ([
    0: ([ "name": HIK"���v�_��"NOR,
          "file": "/world/area/whale_island/hole.c",
          "x": 20,
          "y": 15, ]),
    1: ([ "name": HIK"���v�_��-B1"NOR,
          "file": "/world/area/whale_island/hole_1f.c",
          "x": 20,
          "y": 20, ]),
    2: ([ "name": GRN"�����p��"NOR,
          "file": "/world/area/wild/hole.c",
          "x": 19,
          "y": 11, ]),
    3: ([ "name": HIG"�ԨƪL"NOR,
          "file": "/world/area/bone/fight.c",
          "x": 41,
          "y": 31, ]),
    4: ([ "name": HIK"���v�p�|"NOR,
          "file": "/world/area/sneakhole/path.c",
          "x": 20,
          "y": 40, ]),
]);

private void create() 
{
    seteuid(getuid());
    set("channel_id", "�Ԫ����F");
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

    // ���l�@���a�Y��
    mob = new(npc_path + "doctor.c");
    mob->set("SAND_KILL", record[room_id]["file"]);
    leader_name = mob->query("name");

    // �H�����ܬY�@��
    moveCorrectCoord(mob, room, room_id);

    // �ԭz�N��b�a�Y���o�̡A�w�� call_out �S�P�w��
    CHANNEL_D->do_channel( player, "war", YEL" ���n���D�G"HIW+leader_name+NOR+YEL"���I��ˡA�o�������ȴN�浹�A�F�I\n\n"NOR+YEL"\t�F�ޥS�̨̭S���Y��A�o���N�e��"NOR+record[room_id]["name"]+YEL"�j�v���ܤ@�f�I\n\n"NOR+YEL"�ٱ�"HIR"["+chinese_number(kill_lv)+"��]"NOR+YEL"�H�W���U���^���̤��[��N���W���]���浹���I�S�̭̤W���I\n\n\n"NOR);
}

private void createBandit(object player, object room, int room_id, int kill_lv)
{
    object mob;
    int i, cnt = 15;
    string npc_path = "/world/area/sand_hole/npc/";

    // �䥦����
    for(i=0; i<cnt; i++) {
        mob = new(npc_path + "bandit.c");
        mob->set("level_kill", kill_lv);
        moveCorrectCoord(mob, room, room_id);
    }
}

// �}�l�Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ��Ұ�, 0 ��ܨS�Ұ�
int doStartWar(object player)
{
    int i, x, y;
    int kill_lv, room_id;
    object room;

    // �H�����o�Y�ϰ�
    room_id = random(sizeof(record));
    number = room_id;
    room = load_object(record[room_id]["file"]);
    kill_lv = 21 + random(20);

    // �S��k���J�ϰ�
    if( !objectp(room) ) return 0;

    // �o�Ӱϰ쪱�a�H�Ƥ����A���|�}�Ԫ�
    if( getPlayerCnt(room) < OPEN_WAR ) return 0;

    // ���J����NPC
    createDoctor(player, room, room_id, kill_lv);
    call_out("createBandit", 5, player, room, room_id, kill_lv);
    call_out("createBandit", 10, player, room, room_id, kill_lv);

    // �g�o���� mob �ۤv�h�P�_�n���n�{�H
    room->set("SAND_WAR", 1);

    return 1;
}

// �����Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ�����, 0 ��ܨS����
int doEndWar(object player)
{
    // mob���R����� mob �ۤv�P�_�A��� map ���t��P bug...
    object room;
    room = load_object(record[number]["file"]);

    // �S��k���J�ϰ�
    if( !objectp(room) ) return 0;

    room->delete("SAND_WAR");

    CHANNEL_D->do_channel( this_object(), "war",YEL"�s�������ڪ����D�G�o�����G���G���Ӧn���I���ԦU��S�̡I"NOR);
    return 1;
}

void doHeartBeat()
{
}
