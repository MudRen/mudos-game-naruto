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
        "west" : __DIR__"pk07.c",
        "east" : __DIR__"pk09.c",
        "north" : __DIR__"pk03.c",
        "south" : __DIR__"pk13.c",
    ]));
        setup();
}
