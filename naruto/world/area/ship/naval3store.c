#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��ĥ�ܮw");
        set("long", @LONG
�q�`�����x��ĥ�O�S���ܮw���A�]���o�������Ӻ�O�B��ĥ����
�����a�A�ܮw���N���Ӥj�B�c�A�i�H�s��ܦh�������M�������ơA
���L�{�b�o����ܮw�èS���Ӧh���F��A�u���ֶq�������Ӥw�C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"naval3.c",
                       "x_axis" : 10,
                       "y_axis" : 27,
                  ]),
    ]));
    setup();
}
