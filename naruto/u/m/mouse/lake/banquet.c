#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�b�|�U");
    set("long", @long
�Q���e�s���j�ǡA�W�����ӥΪ����J�誺�P�l��ۡu�b�|�U�v
�T�Ӧr�A�j���O�o�D�H�|�쬡�ʮɭԩҥΪ��|���a�C�a�W��B���O
�Ͼ����H���άO���ê��j���A�p�G���n�L�ʪ��ܷQ���|�ȫܦh����
�a�A�u���O�D�`�i���C
long);
    set("exits", ([
        "west" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 6,
                      "y_axis": 3,
                 ]),
        "east" : __DIR__"banquet2.c",
        "south" : __DIR__"banquet3.c",
        "north" : __DIR__"banquet4.c",
    ]));
    setup();
}
