inherit ROOM;

void create()
{
    set("short", "¾�~�y�H-�ɲ߯Z");

    set("long", @long
�o��O�H���q�W���@���ɲ߯Z�A�M���ۦ��Q�n���y�H¾�~���ǥ͡C�A�i�H
�ݨ�b�J�f���d�i�B�A�w�g�ƤF�����n���W�O���Z���H�s�C�p�G�A�Q�n�ѥ[��
�~���y�H���ҸաA����i�H��ӿ����Ӧҫe�Ĩ�Z�C
long
);

    set("exits", ([
        "east" : ([ "filename": __DIR__"area.c",
                      "x_axis": 12,
                      "y_axis": 11,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/teacher.c" : 1,
          __DIR__"npc/teacher2.c" : 1,
    ]));

    setup();
}

