#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIW"天梯"NOR);
    set("long", @long
這裡是一個能容納數十人的小洞穴，在洞內的盡頭是一座高大的
樓梯，但是樓梯口卻被一扇不知是何種材質所製作的黑色大門所擋住
門上畫滿了數不清的神獸圖案，當你從每種角度去看，所能看出來的
神獸模樣皆不相同，久視後居然讓你心神渙散，漸漸被門上的神獸所
威嚇，不自覺的向後退了幾步。
long);
    set("exits", ([
        "south" : ([ "filename": __DIR__"god_1.c",
                      "x_axis": 42,
                      "y_axis": 8,
                 ]),
    ]));
    set("detail", ([
        "大門": "上面畫了許許多多的神獸，讓你看了心生害怕。",
        "樓梯": "不知道通到哪裡的樓梯，但是被大門擋住了。",
    ]));
    set("no_recall", 1);
    setup();
}
