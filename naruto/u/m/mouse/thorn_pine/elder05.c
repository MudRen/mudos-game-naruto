inherit ROOM;

void create()
{
        set("short", "�@�Ӥj�U");
        set("long", @LONG
�Ѱʪ���֦a��ҾQ�����@���Ŧa�A�|�P���\��ۮ�ȡA���G�O
�}�|�ɵo���̥�������o�̵o���A���j�a������F�ѵo���̪��@�|�@
�ʡA�P�ɳo�̤]��۪��f�A�s�~�������[�̤]��s�o�@�G�C
LONG);
    set("exits", ([
        "west" : __DIR__"elder04.c",
        "east" : __DIR__"elder06.c",
        "north" : __DIR__"elder01.c",
        "south" : __DIR__"elder08.c",
    ]));
        setup();
}
