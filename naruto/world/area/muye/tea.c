/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "�츭���]");

    set("long", @long
�o�O�츭�����񹣦W�����]�A���f�εۯ����K���@���p�l�A�W�Y�g
�g�u�}�Ӥ����q�A�n�����Ϊw�v�A�Ǥ��o�A���e�ӯ��]���ȤH�A�C�ӤH
�r������ӦY�A�G�M�O���Ϊw�C
long);

    set("exits", ([
        "east" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 12,
                      "y_axis": 30,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/teaer.c": 1,
    ]));

    setup();
}
