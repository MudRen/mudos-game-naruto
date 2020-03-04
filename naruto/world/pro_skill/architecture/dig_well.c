#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i�ؿv�ǡj�����ޥ�", ({ "dig well book", "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 10000);
        set("long", "�@���ЧA�p��������оǮ��y�C\n"
                    "����G�������ؿv�ǧޯ�C\n"
                    "�ϥΤ覡�G use book\n");
    }

    setup();
}

void do_use(object me, string arg)
{
    mapping sk;
    sk = me->getProSkill("architecture");

    if( !mapp(sk) ) {
        tell_object(me, "�A�q���ǹL�ؿv�ޯ�C\n");
        return;
    }

    if( member_array("well", sk["item"]) != -1 ) {
        tell_object(me, "�����ޥ��A�w�g�Ƿ|�F�C\n");
        return;
    }

    if( !me->addProItem("architecture", "well") ) {
        tell_object(me, "�A�S��k�ǲ߫����ޥ��A�i��O�ޯ൥�Ť����C\n");
        return;
    }


    message_vision("$N���_��W��$n�J�Ӫ��\Ū�_�ӡC\n", me, this_object());
    destruct(this_object());
}

