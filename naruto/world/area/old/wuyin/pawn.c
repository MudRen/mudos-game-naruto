#include <room.h>
inherit HOCKSHOP;
void create()
{
    set("short", "當舖");
    set("long", @LONG
村裡唯一一家的當舖，高掛著一張矩形大藍底布上面寫著白色「
當」字，屋內上方的樑柱懸掛著一串串的古銅錢，華麗中的格調設計
，門旁站著當舖老闆顧請的兩位壯士防止糾紛鬧事，隱約帶著點兒「
吃人不吐骨頭」的勢利，來到此處你可以典當任何東西；除了金銀財
寶外，當舖老板什麼都收，也什麼都要。
LONG
        );
        set("exits", ([
                "south" : ([ "filename" : __DIR__"wuyin.c",
                                         "x_axis" : 11,
                                         "y_axis" : 29, 
                                  ]),
                ]));

    setup(); 
}
