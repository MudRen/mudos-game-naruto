#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "��������");
    set("long", @LONG
���Ӧ��@������z�ۥ��~�i�ӡA�u�����e�O�@�Ӥj���������A��
���D������ΡA���L�A�Q�h�I�o�Ӿ����]�S����²��A���Ө���M�A
���ǤH���צb�����e���C
LONG);
    set("exits", ([
        "down" : __DIR__"left3.c",
    ]));
    set("detail", ([
        "����": "���G�i�H����(push)���ˤl�C",
    ]));
    set("objects", ([
        __DIR__"npc/wei.c" : 1,
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
        if( ob = present("_WEI_", environment(me)) ) {
            message_vision(ob->query("name")+"���D�G"HIG"������I�J�M...���ʾ����I...\n"NOR, me);
            message_vision(ob->query("name")+"���D�G"HIG"��$N�N...�U���u�h�a�I\n"NOR, me);
            message_vision(ob->query("name")+"���D�G"HIG"���K�i�D�ڤw�u�����ˡI...�ڹL���ܦn�I������I\n"NOR, me);
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
