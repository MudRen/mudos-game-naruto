/* write by -Acme- */

#include <room.h>

// �]��INN�̡A�|�۰ʦ����D�԰ϡA�åB�O�����I
inherit INN;

void create()
{
    set("short", "�i�@�֡j�����]");

    set("long", @long
�o�O�츭�����������]�A�Ѯv�Ū��������񹣦W�A�o�̪����ѬO
�W�������~�A�s�Ĥ@�N�����v�j�H�g�L���|�D�������A��W�ٱ��ۤ@
�T���v�j�H�L�U�����Ӥ��A�۷�r��C
long);

    set("exits", ([
        "west" : ([ "filename": __DIR__"muye.c",
                      "x_axis": 37,
                      "y_axis": 21,
                 ]),
    ]));

    set("objects", ([
        __DIR__"npc/fooder.c": 1,
        __DIR__"npc/naruto.c": 1,
    ]));

    setup();
}
