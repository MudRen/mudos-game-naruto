inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����W�����F���y�A�ҵe�������O�@�خɱ`ť�H�����p���l����
�����u�a�����v���L�ܤ�ť�H�ݹL�a�������ˤl�A�o���o��b�o�̬�
��a�������U�ث��A���y�A��ܳo���Фl���D�H���o���l��������
���۷�`�J���F�ѡC
LONG);
    set("exits", ([
        "west" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 26,
                       "y_axis" : 28,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/shao.c" : 1,
    ]));
    setup();
}
