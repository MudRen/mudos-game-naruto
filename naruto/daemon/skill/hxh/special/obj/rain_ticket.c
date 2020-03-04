#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"[�B��]"HIW"�ɶU��"NOR, ({ "rain ticket" }));
    if( !clonep() ) {
        set("unit", "�i");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 1);
        set("no_box", 1);
        set("long","�@�i�_�Ǫ��d���A�W�����o�X�P�����P�����O\n\n"
                   "�ޯ�W�١G�B���Ԫ̧ޥ�"HIC"[���پ�]\n"NOR
                   "�ϥα���G�S��t�{��(special) 40 �ťH�W�B�ɶU�� 40 �ťH�W\n"
                   "�ޯ�ĪG�G�������m�O�q �ɶU�鵥��/2 �I\n"
                   "�ĪG�ɶ��G�ɶU�鵥��\n"
                   "�ϥλݨD�G�C���ϥλݭn 100 �I�]�O��\n\n");
    }
    setup();
}

void do_use(object me, string arg)
{
    mapping cnd = ([]);
    int sk;

    if( me->query("level") < 15 ) {
        write("���ť����n�� 15 �Ť~��ϥΫB�����ɶU��C\n");
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

    cnd["name"] = HIC"��[�B��]"NOR;
    cnd["duration"] = sk*3/2;
    cnd["ability"] = "rain";
    me->start_busy(2);
    me->set_condition("ticket", cnd);
    me->set_temp("ticket_card/rain", 1);

    // �Ӽƴ��
    this_object()->add_amount(-1);
    if( !this_object()->query_amount() )
        destruct(this_object());
}
