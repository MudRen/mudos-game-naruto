inherit ROOM;

void create()
{
        set("short", "�M�����a");
        set("long", @LONG
�\�H�ڦb�ĤT�N�ڪ��ɴN�w�U�W�h�G�u�b���`�ɶ����i�H�N�P�H
��Z�Υ��[�A�Z�O�ǳW�̡A�@���F���r���׽m���Q�ѡA�B���o�ѻP��
�󪺥��y���ʡC�v�ߤ@�ҥ~���K�O�b�o���j����Z�����M���A�b���B
�\�H�K�i�H���O���P���԰��C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"village.c",
                       "x_axis" : 24,
                       "y_axis" : 18,
                  ]),

        "west" : __DIR__"pk03.c",
        "east" : __DIR__"pk05.c",
        "south" : __DIR__"pk09.c",
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
