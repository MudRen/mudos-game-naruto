#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "���~�P�}�a");
    set("long", @LONG
�A���B�󤻨~�P�]�k�}���A�Pı�������O�q������������X�ӡA
���L�C��A�o�ʧ����ɡA�o�S�Pı�������O�q�N���J��@�Ӳ`������
���۴��A�����������Q�l���A���A�뤣�o�������}�o�ө_�Ǫ��a��C
�u���|�P��۳\�h�o�ۥ��~���]�k���H�A���G�i�H�Ψӽm�\�C
LONG);
    set("exits", ([
        "east" : __DIR__"magic02.c",
        "south" : __DIR__"magic05.c",
    ]));
    set("objects", ([
        __DIR__"npc/item/stake.c" : 3,
    ]));
    setup();
    set("no_recall", 1);
}
void init()
{
    add_action("do_move", "move");
    add_action("do_move", "sfly");
}
int do_move(string arg)
{
    message_vision("$N���ϭ��W�ѪšA���O����г��S�^�F�U�ӡC\n", this_player());
    return 1;
}
