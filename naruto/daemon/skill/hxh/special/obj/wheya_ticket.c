#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"[���]]"HIW"�ɶU��"NOR, ({ "wheya ticket" }));
    if( !clonep() ) {
        set("unit", "�i");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 1);
        set("no_box", 1);
        set("long","�@�i�_�Ǫ��d���A�W�����o�X�P�����P�����O\n\n"
                   "�ޯ�W�١G���]�Ԫ̧ޥ�"HIY"["HIR"�������R"HIY"]\n"NOR
                   "�ϥα���G�S��t�{��(special) 100 �ťH�W�B�ɶU�� 100 �ťH�W\n"
                   "�ޯ�ĪG�G�@��ˮ` �ɶU�鵥�� + (��)�ͩR - random(200)\n"
                   "�R������G(��)�R����O > (��)�j�ׯ�O\n"
                   "�B�~����G�C���ϥΦ����ۤv���ͩR �ɶU�鵥�� + random(100) �I\n"
                   "�ϥλݨD�G�C���ϥλݭn �ɶU�鵥��/4 �I�]�O��\n\n");
    }
    setup();
}

void do_use(object me, string arg)
{
    mapping cnd = ([]);
    int sk;

    if( me->query("level") < 30 ) {
        write("���ť����n�� 30 �Ť~��ϥν��]���ɶU��C\n");
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

    cnd["name"] = HIR"��[���]]"NOR;
    cnd["duration"] = sk*3/2;
    cnd["ability"] = "wheya";
    me->start_busy(2);
    me->set_condition("ticket", cnd);
    me->set_temp("ticket_card/wheya", 1);

    // �Ӽƴ��
    this_object()->add_amount(-1);
    if( !this_object()->query_amount() )
        destruct(this_object());
}
