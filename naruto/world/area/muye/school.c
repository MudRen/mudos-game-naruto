/* write by -Acme- */

inherit ROOM;

void create()
{
    set("short", "�Ԫ̾Ǯ�");

    set("long", @long
�o�̬O�츭�����Ԫ̾ǮաA�A�Ҧb����m�O�Ԫ̾Ǯժ������j�U
�A�Ԫ̾ǮլO�оɾǥͤ@�ǰ򥻪��ԳN�B��N�B�۳N�����F�b�Ԫ̾�
�ղ��~��A�~�঳�U�ԦҸժ����C
long);

    set("exits", ([
        "east" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 10,
                      "y_axis": 37,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/ka.c" : 1,
    ]));

    setup();
}
