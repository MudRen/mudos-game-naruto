#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "酒窖");
    set("long", @long
潮溼的地下室，從兩旁的擺設與地上多種破掉的酒瓶可以猜出
這裡應該是擺放一些高級酒品的酒窖。這裡被水侵襲非常的嚴重，
連兩旁最高的牆角都能看到上面長滿了綠苔，酒櫃更是一個不剩的
全都被大水給沖垮了。
long);
    set("exits", ([
        "up" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 19,
                      "y_axis": 1,
                 ]),
        "west" : __DIR__"wine2.c",
    ]));
    setup();
}
