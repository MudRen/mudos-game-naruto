inherit ROOM;

void create()
{
    set("short", "�����H�a");

    set("long", @long
�����H�a���\��F�\�h���ɥγ��Ψ�A�q�����쳨�������ɦ��A
�Ʀܥ~�Y�٦��@���ɳ���C
long);

    set("exits", ([
        "south" : ([ "filename": __DIR__"swanlake.c",
                      "x_axis": 6,
                      "y_axis": 7,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/fishing_master.c": 1,
    ]));

    setup();
}
