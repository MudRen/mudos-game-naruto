#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�Ϊ���");
    set("long", @LONG
��󤻨~�P�k�����Ϊ��Ǥ��A�Ϊ����p���ມ�y���e���V�A�ݦn
�A���O�A�o�������Pı��o�ж������ػ����X�����L�P�A�A�H�K����
���Ϊ����դF�X�y�A�K�֨B���}�Τl�A�b�{���e���Gť�쨥�p����
�b�ж�����Y�H��͵�....���O�A��~�i�h�èS�ݨ�H���H
LONG);
    set("exits", ([
        "west" : __DIR__"magic06.c",
        "east" : __DIR__"magic08.c",
        "north" : __DIR__"magic03.c",
        "south" : __DIR__"magic11.c",
    ]));
    set("objects", ([
        __DIR__"npc/yan.c" : 1,
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
