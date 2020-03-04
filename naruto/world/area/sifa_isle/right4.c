#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�k������");
    set("long", @LONG
���Ӧ��@������z�ۥ��~�i�ӡA�u�����e�O�@�Ӥj���������A��
���D������ΡA���L�A�Q�h�I�o�Ӿ����]�S����²��A���Ө����έD
���ͪ����צb�����e���C
LONG);
    set("exits", ([
        "down" : __DIR__"right3.c",
    ]));
    set("detail", ([
        "����": "���G�i�H����(push)���ˤl�C",
    ]));
    set("objects", ([
        __DIR__"npc/xiao.c" : 1,
    ]));
    setup();
}
void init()
{
    add_action("do_push", "push");
}
int do_push(string arg)
{
    object ob, me;
    
    me = this_player();

    if( arg == "����" ) {
        if( ob = present("_XIAO_", environment(me)) ) {
            message_vision(ob->query("name")+"���D�G"HIG"��z�z�I����I�����I\n"NOR, me);
            message_vision(ob->query("name")+"���D�G"HIG"��$N���D�ڡu�L�n�����v���F�`�I��z�z�I\n"NOR, me);
            ob->kill_ob(me);
            me->kill_ob(ob);
            return 1;
        } else {
            me->add_temp("quest/justdoor", 1);
            message_vision("$N�ΤO���N�������i�h�C\n", this_player());
            message_vision(CYN"�u����誺�Q���n���]����U�ӤF�@�ǡC\n"NOR, this_player());
            return 1;
        }
    }
    return notify_fail("�A���ʤ���H\n");
}
