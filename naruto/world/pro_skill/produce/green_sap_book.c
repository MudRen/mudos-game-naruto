#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i�Ͳ��j����G�^���Ь��", ({ "green sap book", "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 100);
        set("long", "�����@�����ѡA�~�֬O�@�i�Τ�M�˵۾�G���ϡC\n"
                    "����G�������Ͳ��ޯ�C�ϥΤ覡�G use book�C\n");
    }
    setup();
}

void do_use(object me, string arg)
{
    mapping sk;
    sk = me->getProSkill("produce");

    if( !mapp(sk) ) {
        tell_object(me, "�A�q���ǹL�Ͳ��ޯ�C\n");
        return;
    }

    if( member_array("green_sap", sk["item"]) != -1 ) {
        tell_object(me, "�A���N�Ƿ|�ѤW�����e�աC\n");
        return;
    }

    if( !me->addProItem("produce", "green_sap") ) {
        tell_object(me, "�]���A�Ͳ��������Ѥ����A�ݤ����ѤW�����e�C\n");
        return;
    }
    message_vision("$N���_��W��$n�J�Ӫ��\Ū�_�ӡC\n", me, this_object());
    destruct(this_object());
}
