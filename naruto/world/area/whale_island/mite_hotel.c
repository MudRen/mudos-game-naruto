// File: /d/whale_island/mite_store.c
// Updated by tmr (Mon Jun  3 00:17:06 2002)

#include <room.h>
inherit INN;


void create()
{
          set("short", "�̯S���s��");
          set("long", @LONG
�շt���O���A�M�ۧn�����n���A�@�i�o�a�s���A�ﭱ����ӨӪ��O�@��
���s���M�۲H�H�����쭻�C�o�̬O�H���q�ߤ@���@���s�a�A��g���q���H��
�ܳ��w�Ө�o���s�a�p�͡C�b�o���s�a�̡A�C�ѳ����ӦۦU�ꪺ����ήȫ�
�A�J��ť�o�̨C�ѳ����H�b�j�N�ۤv�b�L�v�j���W���^�i�Ƹ�A�]���H�b�@
�����Ѩp�y�A�禳�b�@�ǳܵ۴e�s���H�C�d�i�W���@���d��ï(board)�C
LONG
          );
          set("no_fight", 1);
          set("objects", ([ /* 1 element(s) */
        __DIR__"npc/mite" : 1,
          __DIR__"npc/village_head" : 1,
]));
    set("exits", ([
        "north" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 17,
                       "y_axis" : 33,
                  ]),
    ]));

          set("valid_startroom", 1);

        setup();
        load_object("/daemon/board/whale_island_b");

}

