#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�L��");
        set("long", @LONG
�Ф��\��ۤ@�ǯ�H�A���L�C�@�ӳ��Q�����M����ˡC����W��
�F�@�ǳD�کҬ諸���ҩM�Z���A�Ҩ������ҳ��O�ûs�����ҡA�Z���h
�H�s�M�M���j���D�A��ܳD�ڦb�԰��ɫD�`�`�N�t�סA����θ�����
�𰵬�����A�Z���h�Χ����d����s���s�M���j�C
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"marsh.c",
                       "x_axis" : 6,
                       "y_axis" : 13,
                  ]),
    ]));
    setup();
}
