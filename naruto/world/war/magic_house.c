// magic_house.c
//
#define OPEN_WAR 0
#include <ansi.h>
inherit F_DBASE;

// ��ܬO�@�ӾԪ���
int isWar() { return 1; }

// �Ԫ�������ɶ�
// �p�G�]��0, ��ܾԪ�������ɶ��ۦ�]�w�A���Ѩt�α���
int getDuration() { return 0; }   // �ɶ��ѩǪ�����a

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

private void moveCorrectCoord(object mob, object room)
{
    int x, y, ok = 0;

    while( ok == 0 ) {
        x = random(41);
        y = random(26);

        if( !room->query_data(x, y, "block") )
            ok = 1;
    }
    area_move(room, mob, x, y);
}

private void createBandit(object player, object room)
{
    object mob;
    int i;
    int cnt = 20;  // cnt = random(60) + 70 �@���Ӧh�|�����D
    string npc_path = "/world/area/magic_house/npc/";

    // �䥦����
    for(i=0; i<cnt; i++) {
        mob = new(npc_path + "monster.c");
        moveCorrectCoord(mob, room);
    }
}

// �}�l�Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ��Ұ�, 0 ��ܨS�Ұ�
int doStartWar(object player)
{
    object room;

    // ���o�Y�ϰ�
    room = load_object("/world/area/magic_house/house.c");

    // �S��k���J�ϰ�
    if( !objectp(room) ) return 0;

    // �]���� call out �ҥH�N�ԭz��b�o��
    // �����a�|���n�A�ҥH�Ԫ����T������� war ��
    CHANNEL_D->do_channel( this_object(), "war",HIW"�j�x��"+player->query("name")+"�N�]�N�����Ϊ����~Ţ�l���}��...�I�I\n\n"NOR+HIG"\t�]�N�����Τ��@���T�ǡA�C�Ȩ�B�k�R�A�p���̦��۸ɮ����~\n\n"NOR);

    // �γo�ӥh�� mob �P�_�Ӥ��ӯd�b�ϰ줤�A��� map ���t��
    room->set("MONSTER_WAR", 1);

    // ���J����NPC
    createBandit(player, room);
    call_out("createBandit", 5, player, room);
    call_out("createBandit", 10, player, room);
    call_out("createBandit", 15, player, room);

    return 1;
}

// �����Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ�����, 0 ��ܨS����
int doEndWar(object player)
{
    object home, room;

    // ���o�Y�ϰ�
    room = load_object("/world/area/magic_house/house.c");

    // �]���n���}�����s�ҥ�
    home = load_object("/world/area/magic_house/open.c");

    // �S��k���J�ϰ�
    if( !objectp(room) ) return 0;

    // �����F�n�R��
    home->delete("MONSTER_WAR");
    room->delete("MONSTER_WAR");
    CHANNEL_D->do_channel( this_object(), "war", HIW"���~�̲ש�Q��^Ţ�l�ԡA�u�O�i�ߥi�P..."NOR);
    return 1;
}

void doHeartBeat()
{
}
