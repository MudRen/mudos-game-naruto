#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�����u�ë�");
    set("long", @LONG
�̭����@�ǽ��Z���b�𮧪����x�h�L�A�������M�εۤF�o���M��
���۵۫O�@�q�k�q�B�½å@�ɥ��q�������ڸܡA�ݨӮ��x���٬O����
�h���h�L���O�u���Q���ۥ��q���C
LONG);
    set("exits", ([
        "south" : ([ "filename": __DIR__"sifa.c",
                     "x_axis": 51,
                     "y_axis": 38,
                  ]),
    ]));
    setup();
}
