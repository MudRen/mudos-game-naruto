inherit ROOM;

void create()
{
        set("short", "�@�Ӥj�U");
        set("long", @LONG
�H�\�H�ӻ��O�D�`�𬣪��Ф��G�m�F�A���f����٦��\���~��
���A�a�W�]�Q�W�F��L�ʪ�����֦a��C����W���F�\�h�ʪ����Y��
�Х��A�N��۱ڪ��H�e�]�O�\�����@�N�^���C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 6,
                       "y_axis" : 18,
                  ]),
        "east" : __DIR__"elder03.c",
        "west" : __DIR__"elder02.c",
        "south" : __DIR__"elder05.c",
    ]));
    setup();
}
int valid_leave(object me, string dir)
{
    int x, y;
    if( !me ) return 0;
    if( !userp(me) && dir == "north" ) return 0;
    return ::valid_leave(me, dir);
}
