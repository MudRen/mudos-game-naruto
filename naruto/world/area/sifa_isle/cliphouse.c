inherit ROOM;

void create()
{
        set("short", "���x�u�Įw");
        set("long", @LONG
���x���u�Įw�A�̭��o�ŪŦp�]�u���ֶq���j��M�l�u�C�@��D
�`���j���H�����b�Фl���A���L�L�b�s�۸y�A��ӭI�������b�г��W
�A���G�����L���ˤl�C
LONG
);
    set("exits", ([
        "west" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 59,
                     "y_axis" : 40,
                 ]),
        ]));
    set("objects", ([
        __DIR__"npc/jie.c": 1,
    ]));
    setup();
}
