inherit ROOM;

void create()
{
    set("short", "�o�󪫦^����");
    set("long", @long
���̰諸�äC�K�V�A�u���@���q�����f�����O�i�H�����A��L��
�m���Q�����Ұﺡ�C�J�Ӥ@�@�A������²�K���\�H�����צb�@�y�|
�a�����������W�A���H���T�`�ȥL�i��y�L�@�ʾ�������N���U�ӧ�
�A�]���b�̭��F�C
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"village.c",
                      "x_axis": 16,
                      "y_axis": 6,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/fee.c" : 1,
    ]));
    setup();
}
