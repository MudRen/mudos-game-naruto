#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�ǫ�");
    set("long", @long
�Ǥ��Ŷ����O�ܤj�A�j���u�e���U���ӤH�@�P�i�J�A��W����
�@�Ǭݰ_�Ӥ��O�ܺ�������e�A������إΪ��O�̴��q���A�s�e��
���e�����O�p�Ĥl�H����~�A��b���H�d�����o���ж����γB�쩳
�b���̡A�n���u�O���p�Ĥl���e���ж��Ӥw�C
long);
    set("exits", ([
        "west" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 23,
                      "y_axis": 12,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/ninja4.c" : 1,
    ]));
    set("detail", ([
        "���e": "�@�Ӧ۵e���a�H�e���n�C��K���H���H�ݥX���O�۵e���C",
    ]));
    setup();
}
