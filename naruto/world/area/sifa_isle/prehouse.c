#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�e���u�ë�");
    set("long", @LONG
�h�L�̥���˫ݵo�A�����e�����u�áA���ɱ`�]�ӭJ�x������
�ɮɨ�賣���ݤp���ԷV�A�u�����L�̤��_�����q�ۧA�A�i��u�n��
�I���骺�ˤl�A�G�ܤ����N�|���W�Q�����a�C
LONG);
    set("exits", ([
        "south" : ([ "filename": __DIR__"sifa.c",
                     "x_axis": 45,
                     "y_axis": 75,
                  ]),
    ]));
    setup();
}
