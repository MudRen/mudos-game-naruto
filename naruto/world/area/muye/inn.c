/* write by -Acme- */

#include <room.h>

// 設成INN者，會自動成為非戰區，並且是重生點
inherit INN;

void create()
{
    set("short", "【一樂】拉麵館");

    set("long", @long
這是木葉村中的拉麵館，老師傅的手藝遠近馳名，這裡的拉麵是
上等的極品，連第一代的火影大人經過都會聞香落馬，牆上還掛著一
幅火影大人摔下馬的照片，相當逗趣。
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
