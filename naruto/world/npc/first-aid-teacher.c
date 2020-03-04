#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("��ϱЮv", ({ "first-aid teacher", "teacher" }));
    set_race("human");
    set_level(50);
    set("age", random(50)+18);

    set("long", "�@��i�H�ЧA�p��ǲ߫�ϧޯ઺�Юv�C\n"
                "�ǲ߫�ϧޯ�G learn first-aid\n"
                "�C�X�c�檺���~�G list teacher\n" );

    // �]�w�ӤH�ҳc�檺���~
    // set_goods(�N�X, ����, �s��, �ƶq, ���)
    // �ӤH��c�檺�F��u��� query ���O�̬d eq, wp, food ��d�X�Ӫ����~
    // �p set_goods(1, "food", 1, 10, -1) ��ܳc�� query ���O�d�X�Ӫ�food�s����1�����~�Q��
    // �Y�ƶq�]�w -1 ��ܵL���q����
    // �Y����]�� -1 ��ܻ����O�ϥθӪ���]�w��value
    // �N�X�O�Ω� buy ���O�W�A�p buy 1 �h�|�V�ӤH�R�U�N�X��1���ӫ~

   set_goods(1, "obj", 119, -1, -1);
    set_goods(2, "obj", 168, -1, -1);
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

    if( !arg || arg != "first-aid")
        return notify_fail("�A�Q�ǲߤ���H\n");

    sk = me->getProSkill("first-aid");

    // �q�S�ǹL
    if( !mapp(sk) ) {
        message_vision("$N�V$n�Q�Ц�����Ϥ譱�����ѡC\n", me, this_object());
        me->addProSkill("first-aid");
    } else tell_object(me, "�A�w�g�Ƿ|��ϧޯ�F�C\n");

//    // ���ɧޯ൥�ŤW�����Ҥl
//    if( !mapp(sk) ) tell_object(me, "�A�S�ǹL��ϧޯ�C\n");
//    else {
//        // 75 -> 150  �Ѯv�u�Ш�150
//        if( sk["max_level"] >= 150 ) {
//            tell_object(me, "�A���G�L�k�qxxx���W�A�ǲߧ�i�@�B����ϧޯ�C\n");
//            return 1;
//        }
//
//        // �{�b���ޯ൥�ŭn�O�����W���~��W�[
//        if( sk["level"] != 75 ) {
//            tell_object(me, "�A����ϧޯ൥�Ť����H��i�@�B���ǲߡC\n");
//            return 1;
//        }
//
//        // ���ɤW��
//        me->upProSkill("first-aid");
//    }

    return 1;
}
