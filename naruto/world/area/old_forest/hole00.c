#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","���~�}�]");
    set("long", @long
���g�ۧ�����誺�@���p�|�A���쩳�ݬO�������ª��}�]�A�}
�~�����F�g�۸g�`�ϥΪ���G�B���B�U�ئU�˪����~�A�C�س��s�@
���Q������A���~�~���٥]�q�F�@�h�z���T��A�ϸ̭����G��ᦷ��
���p��ĤU�Ӥ@�몺�A�A�A�N��g�ۤH�D�`�L�q�o�Ӭ}�]�C
long);
    set("exits", ([
        "south" : __DIR__"hole01.c",
        "north" : __DIR__"tree36.c",
    ]));
    set("no_recall", 1);
    setup();
}
