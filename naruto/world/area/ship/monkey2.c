#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��s�s�X�ζL��");
        set("long", @LONG
�ж���������L�ж����٭n�p�A�����D�O�����]�~��o�̪�
�j���ĪG��������n�H�Ъ��W�g�ۡu�������v�V�V�C
LONG);
    set("exits", ([
        "up" : __DIR__"monkey3.c",
        "down" : __DIR__"monkey1.c",
        "east" : ([ "filename" : __DIR__"lufi.c",
                       "x_axis" : 26,
                       "y_axis" : 24,
                  ]),

    ]));
    setup();
}
