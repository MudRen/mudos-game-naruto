#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void create()
{
    set_name("��즫��", ({ "Joe Torre", "torre", "joe" }));
    set_race("human");
    set_level(1);
    set("age", 66);
    set("long", "�~�Ѫ������ιέ��A�{�b���b�o��Ф���z�~���C\n"
                "�p�G�Q�n�ǲߥͲ��M�~�ޥ��A�]�i�H�M�L�ǲߡC\n"
                "���O�G learn produce \n");
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say �̪�`��z�X�@�Ǭ\�K...���O�ӤH�檺�¤߳f�C" :),
        (: command, "say �n���`���H�Ӹ�ڶR�\�K...���쩳��F�¡H" :),
    }) );
    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

    set_goods(1, "obj", 163, 5, -1);
    set_goods(2, "obj", 162, -1, 1);
    setup();
}

void init()
{
    add_action("do_learn", "learn");
}

int do_learn(string arg)
{
    object me;
    mapping sk;

    me = this_player();

    if( !arg || arg != "produce")
        return notify_fail("�A�Q�ǲߤ���H\n");

    sk = me->getProSkill("produce");

    // �q�S�ǹL
    if( !mapp(sk) ) {
        message_vision(CYN"$N�V$n�M�ݤ@�ǥͲ����������ѡC\n"NOR, me, this_object());
        message_vision("$n���D�R"HIG"���o�٦��o�򦳤ߨD�Ǫ��H�A�ڴN�б�$N�a�C\n"NOR, me, this_object());
        tell_object(me , "(�A�F�ѤF�Ͳ��Ǫ���¦�C)\n"NOR);
        me->addProSkill("produce");
    } else tell_object(me, "�A�w�g�w�g�|�Ͳ��ޯ�F�C\n");
    return 1;
}
