/* write by -Acme- */

#include <room.h>

// �]��INN�̡A�|�۰ʦ����D�԰ϡA�åB�O�����I
inherit INN;

void create()
{
    set("short", "�Ův����");
    set("long", @LONG
�o�̦�ۤ@�s�֦������]�k���Ův�A�Ův�Ҿ֦�����O���O�@��
�H�i�H�A�Ѫ��A�A�i�H�ݨ��e�����Ův��R���Цa�A�g�����ɴ��o�X
�C�m���~�A�����b�Ϥ����]�k�C
LONG
    );
    set("exits", ([
        "west" : __DIR__"bug",
        "north" : __DIR__"academy",
        "east" : __DIR__"propose",
        "up" : __DIR__"meetingroom",
        "south": __DIR__"power",
    ]));

    set("objects", ([
        __DIR__"npc/annihilator" : 1,
        __DIR__"npc/luky" : 1,
        __DIR__"npc/shengsan" : 1,
        __DIR__"npc/tmr" : 1, 
        __DIR__"npc/acme" : 1, 
        __DIR__"npc/chi.c" : 1,
    ]));

    setup();
    load_object("/daemon/board/wizard");
    replace_program(ROOM);
}
