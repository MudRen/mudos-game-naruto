#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIM"[����]"HIW"�ɶU��"NOR, ({ "music ticket" }));
    if( !clonep() ) {
        set("unit", "�i");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 1);
        set("no_box", 1);
        set("long","�@�i�_�Ǫ��d���A�W�����o�X�P�����P�����O\n\n"
                   "�ޯ�W�١G�����Ԫ̧ޥ�"HIM"[�������N]\n"NOR
                   "�ϥα���G�S��t�{��(special) 50 �ťH�W�B�ɶU�� 30 �ťH�W\n"
                   "�ޯ�ĪG�G�v���ۨ����ˮ` �ɶU�鵥�� & �S��t�{�� �v�T\n"
                   "          �̦h�v���ۨ���O�̤j�Ȫ� 25%\n"
                   "�ϥλݨD�G�C���ϥλݭn 100 �I�]�O��\n"
                   "�N�o�ɶ��G���Ӫv�������O���h�ֵ����N�o�A�̦h 3 ����\n\n");
    }
    setup();
}

void do_use(object me, string arg)
{
    mapping cnd = ([]);
    int sk;

    if( me->query("level") < 15 ) {
        write("���ť����n�� 15 �Ť~��ϥέ��Ԫ��ɶU��C\n");
        return;
    }
    if( me->query_condition("ticket") != 0 ) {
        write("�A�w�g�b�ϥέɶU��F�A���ɮĹL�h�A���a�C\n");
        return;
    }
    sk = me->query_skill("lending ticket");

    if( sk < 20 || me->query_skill("special") < 20 ) {
        write("�A���ɶU��M�S��t�{�ץ����n�b 20 �ťH�W�C\n");
        return;
    }
    message_vision("\n$N�����M�`�a�a�W�ն�A�C�C�N$n���}�A�@�}�C����J$N�����W...\n\n"NOR, me, this_object());

    cnd["name"] = HIM"��[����]"NOR;
    cnd["duration"] = sk*3/2;
    cnd["ability"] = "music";
    me->start_busy(2);
    me->set_condition("ticket", cnd);
    me->set_temp("ticket_card/music", 1);

    // �Ӽƴ��
    this_object()->add_amount(-1);
    if( !this_object()->query_amount() )
        destruct(this_object());
}
