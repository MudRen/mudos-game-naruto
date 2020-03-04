// �Ȥl
//
#define OPEN_WAR 0
#include <ansi.h>
inherit F_DBASE;

// ��ܬO�@�ӾԪ���
int isWar() { return 1; }

// �Ԫ�������ɶ�
// �p�G�]��0, ��ܾԪ�������ɶ��ۦ�]�w�A���Ѩt�α���
int getDuration() { return 600; }   // ���� 10 ���� (600��)

object *loadMobs = ({});

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
        x = 22;
        y = 29;

        if( !room->query_data(x, y, "block") )
            ok = 1;
    }
    area_move(room, mob, x, y);
}

private void createBandit(object player, object room)
{
    object mob;
    string npc_path = "/world/area/sand_hole/npc/";

    mob = new(npc_path + "sun_scorpion.c");
    moveCorrectCoord(mob, room);

    // �ƶq�ִN�浹 map �h�P�_�a..�Ʊ�S���D @o@
    loadMobs += ({ mob });

    CHANNEL_D->do_channel( this_object(), "war", HIR"�a���}�}���n�ʡA�@�n���T���M�ǹM�|�P\n\n"NOR+HIW"�u�����H������񪺤Ѫũ��M�{ģ�ۦp�Ӷ��몺���~�A�P�ѪŪ������ۤ��I��\n\n"NOR);
}

// �}�l�Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ��Ұ�, 0 ��ܨS�Ұ�
int doStartWar(object player)
{
    object room;

    // ���o�Y�ϰ�
    room = load_object("/world/area/sand_hole/hole_3b.c");

    // �S��k���J�ϰ�
    if( !objectp(room) ) return 0;

    // ���J����NPC
    createBandit(player, room);

    return 1;
}

// �����Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ�����, 0 ��ܨS����
int doEndWar(object player)
{
    // �R�����J��mob
    int i, size;
    object home;

    // �]���n���}�����s�ҥ�
    home = load_object("/world/area/sand_hole/hole_3b.c");

    size = sizeof(loadMobs);
    for(i=0; i<size; i++) {
        if( objectp( loadMobs[i] ) ) {
            message_vision("�ɶ����y�u�������M�S�A�����U�A$N�]�^��I�v�����C\n"NOR, loadMobs[i]);

            // ��� mob ���Q�R���ɤ~���ԭz�A��氦�� mob �i�H��b�o��
            // �קK�M boss �� mob �����j�ۭ��� end
            // �������ԭz�O�Ѧ��{������
             CHANNEL_D->do_channel( this_object(), "war", HIC"�ѷn�a�ʺ������F�A�ϩ�����Ʊ��]�S�o��"NOR);
            destruct(loadMobs[i]);
        }
    }
    loadMobs = ({});
    return 1;
}

void doHeartBeat()
{
}
