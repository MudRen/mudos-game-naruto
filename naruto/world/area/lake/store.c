#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�ܮw");
    set("long", @long
�̭����o�X�Ѽ�ê��`���A�ݵ۪��P�W�g�ۡu�ܮw�v���r�ˡA
���ӯ���Q�H��o�̨I�J�����ɡA�̭��]��F���֪F��a�A�u�O�g
�L�F�����D�h�֦~�����w�A�j�������w�g�G�ꤣ��ΤF�C
long);
    set("exits", ([
        "north" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 7,
                      "y_axis": 7,
                 ]),
        "east" : __DIR__"store2.c",
    ]));
    setup();
}
