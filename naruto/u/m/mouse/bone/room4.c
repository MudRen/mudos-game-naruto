#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�a�O�W�W�W�Y�Y���D�`���W�h�A��W���F�@��¦⪺�򨭦��٦�
�@����M�A��˪��~�������εۤH������r�g�ۡy��z�j���i�H�q�X
�o�̬O�D�H�m�߬����ԳN�����a�a�C�u�������L�a��躡�F�U�ع�
�שM��r���W�A�i�O��r�O�γD�ڪ��r�g���A�����ݤ����C
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"marsh.c",
                       "x_axis" : 6,
                       "y_axis" : 8,
                  ]),
    ]));
    setup();
}
