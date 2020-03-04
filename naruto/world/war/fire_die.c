// �Ȥl
//
#define OPEN_WAR 0
#include <ansi.h>
inherit F_DBASE;

// ��ܬO�@�ӾԪ���
int isWar() { return 1; }

// �Ԫ�������ɶ�
// �p�G�]��0, ��ܾԪ�������ɶ��ۦ�]�w�A���Ѩt�α���
int getDuration() { return 300; }   // ���� 5 ���� (300��)

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
    CHANNEL_D->do_channel( this_object(), "war", HIR"\n\n\t�Y�H���Ȧ������J���s���`�B�A���G�o�ɭP���s�[�t����..."NOR"\n\n\t"HIK"�u�����j����D�W�Ť��Q�X�}�}�@��..."NOR"\n\n\t"HIY"�ݨӦA�L"BLINK"������"NOR+HIY"���k�o�y���s�q���N������F�I\n\n\n"NOR);
}

// �}�l�Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ��Ұ�, 0 ��ܨS�Ұ�
int doStartWar(object player)
{
    object room;

    // ���o�Y�ϰ�
    room = load_object("/world/area/lv60_area/fire.c");

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
    object room;
    object *inv;

    // �n���ϰ줤�����a�����N��
    room = load_object("/world/area/lv60_area/fire.c");

    inv = all_inventory(room);
    size = sizeof(inv);

    CHANNEL_D->do_channel( this_object(), "war",HIR"\n\n\t���s�z�o�աI�٦b���s���r�d���_�I�̭̳�����L�������s�ҧ]��...\n\n\n"NOR);

    for(i=0; i<size; i++) if( userp(inv[i]) ) inv[i]->die();
    loadMobs = ({});
    return 1;
}

void doHeartBeat()
{
}
