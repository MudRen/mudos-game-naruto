// File: /d/whale_island/mite_store.c
// Updated by tmr (Mon Jun  3 00:17:06 2002)

#include <room.h>
inherit INN;


void create()
{
          set("short", "米特的酒店");
          set("long", @LONG
幽暗的燈光，和著吵雜的聲音，一進這家酒店，迎面撲鼻而來的是濃郁
的酒味和著淡淡的紅木香。這裡是鯨魚島唯一的一間酒吧，航經此島的人們
很喜歡來到這間酒吧小憩。在這間酒吧裡，每天都有來自各國的水手及旅客
，仔細聽這裡每天都有人在吹噓自己在汪洋大海上的英勇事跡，也有人在一
旁竊竊私語，亦有在一旁喝著悶酒的人。櫃檯上有一本留言簿(board)。
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

