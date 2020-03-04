#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�x�|�ж�");
    set("long", @LONG
�ж����G�m�����Ӯx�|�A���D�F�M�y���A�٦��p���P�@�s�p�ʪ�
�A�ݰ_�ӫܩM�Ӫ��ˤl�C�b�Фl�����������@�Өk�l�A���w�b�a�W��
ı�A�u���L�����ǩ�ۤ@�U�ݰ_�Ӧn���ܭ����U�l�A�U�l�W�ټg�Ӥj
�j���u���v�r�A�Ӥ��|�O���U�a�C
LONG);
    set("exits", ([
        "north" : __DIR__"hall2.c",
    ]));
    set("detail", ([
        "���U": "�ݰ_�ӫܭ����ˤl�A�_�X���X�筫�A�Q��(get)�ܡH�C",
    ]));
    set("objects", ([
        __DIR__"npc/jia.c" : 1,
    ]));
    setup();
}
void init()
{
    add_action("do_get", "get");
}
int do_get(string arg)
{
    object ob, me;
    
    me = this_player();

    if( arg == "���U" ) {
        if( ob = present("_JIA_", environment(me)) ) {
            message_vision(ob->query("name")+"���M�C�}�F�����C\n"NOR, me);
            message_vision(ob->query("name")+"���D�G"HIG"�������I���p���W�ĤF�I\n"NOR, me);
            message_vision(ob->query("name")+"���D�G"HIG"�m�ܮ��x�]���I�h���a�I\n"NOR, me);
            ob->kill_ob(me);
            me->kill_ob(ob);
            return 1;
        } else {
            message_vision("$N���_�F���U�A�o�o�{�̭����O���ȿ��������C\n", this_player());
            return 1;
        }
    }
}
