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
        "east" : __DIR__"pk02.c",
        "south" : __DIR__"pk06.c",
    ]));
    set("objects", ([
        __DIR__"npc/warrior.c" : 1,
        __DIR__"npc/master.c" : 1,
    ]));
    setup();
}