#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�ʸU���a");
        set("long", @LONG
���ʸU���a�A�ݰ_�ӫD�`����....���O�|�P���ﺡ�F�U�a���ѩ�
���J�M�_�l�A�@�줤�~�H�N�b�J�襤�~��V�O���Y�۩��ѡA�p�G�S��
�q���L���ӴN�O���ʸU�F�C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 33,
                       "y_axis" : 33,
                  ]),
    ]));
    set("objects", ([
        _DIR_AREA_"echo/npc/wang.c" : 1,
    ]));
    setup();
}
