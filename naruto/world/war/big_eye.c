#include <ansi.h>
inherit F_DBASE;

// ��ܬO�@�ӾԪ���
int isWar() { return 1; }

// �Ԫ�������ɶ�
// �p�G�]��0, ��ܾԪ�������ɶ��ۦ�]�w�A���Ѩt�α���
int getDuration() { return 0; }

private void create() 
{
    seteuid(getuid());
    set("channel_id", "���]����");
}

void doChat(string str)
{
    CHANNEL_D->do_channel( this_object(), "war",HIR + str + "\n"+NOR);
}

// �}�l�Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ��Ұ�, 0 ��ܨS�Ұ�
int doStartWar(object player)
{
    return 0;
}

// �����Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ�����, 0 ��ܨS����
int doEndWar(object player)
{
    return 0;
}

void doHeartBeat()
{
}
