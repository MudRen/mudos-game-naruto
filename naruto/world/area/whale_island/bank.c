/* write by -Acme- */

#include <room.h>

inherit BANK;

void create()
{
    set("short", "�H���Ȧ�");

    set("long", @long
�o��O�q�W���ߤ@�@���Ȧ� �����O�Ȧ�A���ˤ��p���O���p�뤽�ǡC
�Τl�̥u���@�i�줽��A�M�@�Ӧ~�ڪ��ѱC�C�A���G�N�O�x�޳o���Ȧ檺
�u�@�H���C
�������O�G[�s��] deposit <�ƶq> <�f������>
          [���] withdraw <�ƶq> <�f������>
          [�׿�] outward <�H��> <�ƶq>
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"area.c",
                      "x_axis": 28,
                      "y_axis": 26,
                 ]),
    ]));

    setup();
}
