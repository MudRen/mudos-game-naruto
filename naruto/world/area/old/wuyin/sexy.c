inherit ROOM;

void create()
{
        set("short", "嘂媋院");
        set("long", @LONG
嘂媋院門上高高掛著一塊匾額及一對紅燈籠，匾額上刻著黑粗浮
雕「嘂媋院」三個字，門前貼著一附對聯，往前仔細一瞧，原來是一
間男人愛好的場所，嘂媋院裡鶯鶯燕燕，紅香散亂，外頭正有幾位妙
齡女郎在一旁招呼過往客人。
LONG
        );
        set("exits", ([
                "south" : ([ "filename" : __DIR__"wuyin.c",
                                         "x_axis" : 11,
                                         "y_axis" : 24, 
                                  ]),
                ]));

        setup();
  
}

