#include <ansi.h>
#include <room.h>

inherit INN;

void create()
{
    set("short", "����p��");
    set("long", @LONG
�b�o�̥i�H�Pı�������������D�A���ɪ��٦������j�ӤQ���D�n�C
�ж�������W���۳\�h���x�����A�٦��@��ݰ_�Ӧ��I�j�Ѫ����x��
�M���b�������C�@��ѤH���s�˦a���b�Ф��C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 58,
                     "y_axis" : 77,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/oldman.c" : 1,
    ]));
    set("valid_startroom", 1);
    setup();
}