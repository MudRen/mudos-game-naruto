inherit ROOM;

void create()
{
        set("short", "�@�Ӥj�U");
        set("long", @LONG
�P���\��ۥξ�F�������Ȥl�M��l�A�W���Q�۰ʪ��������o
�Q���ξA�A��l�W�h��ۤ@�Ǿ���C
LONG);
    set("exits", ([
        "east" : __DIR__"elder01.c",
        "south" : __DIR__"elder04.c",
    ]));
        setup();
}
