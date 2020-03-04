inherit ROOM;

void create()
{
        set("short", "海軍藥店");
        set("long", @LONG
外面掛著牌子寫「藥」的小屋，不過屋內傳來陣陣油膩的味道和
非常嚴重的鹹味，讓人光聞到味道胃都快翻掉了。只見一個長的非常
奇怪的人，正穿著直排輪在屋子裡溜來溜去，口中不斷的唸著「我是
瓦傑∼我是ＣＰ７的廚師兼高手∼要不要來碗義大利麵∼」
LONG
);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 60,
                     "y_axis" : 33,
                 ]),
        ]));
    set("objects", ([
        __DIR__"npc/wa.c": 1,
    ]));
    setup();
}
