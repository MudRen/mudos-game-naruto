#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i��ϡj�s�@�D���^�a�оǮ���", ({ "snake-skin-bandage book", "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 100);
        set("long", "�@���ЧA�p��s�@�D���^�a���оǮ��y�C\n"
                    "����G��������ϧޯ�C\n"
                    "�ϥΤ覡�G use book\n");
    }

    setup();
}

void do_use(object me, string arg)
{
    mapping sk;
    sk = me->getProSkill("first-aid");

    if( !mapp(sk) ) {
        tell_object(me, "�A�q���ǹL��ϧޯ�C\n");
        return;
    }

    if( member_array("snake_skin_bandage", sk["item"]) != -1 ) {
        tell_object(me, "�o�Ӳ��~�A�w�g�Ƿ|�F�C\n");
        return;
    }

    if( !me->addProItem("first-aid", "snake_skin_bandage") ) {
        tell_object(me, "�A�S��k�ǲ߳o�˲��~�A�i��O�ޯ൥�Ť����C\n");
        return;
    }


    message_vision("$N���_��W��$n�J�Ӫ��\Ū�_�ӡC\n", me, this_object());
    destruct(this_object());
}

