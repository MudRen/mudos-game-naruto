#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�}�ƺؤl��");
    set("long", @LONG
�ж����k����ۤ@�Ǯa�b���}�ơA�ж�������h�񺡤F�A�a��
���U�ح����ؤl�B���]�C�ж�����B����ۤ�ҡA���G�n���㶡�ж�
�����O�����ꪺ���A�A�s�i�ӤӤ[���A���Pı�ֽ����I�������F�C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 20,
                       "y_axis" : 26,
                  ]),
    ]));
    setup();
}
