inherit ROOM;

void create()
{
        set("short", "醫館");
        set("long", @LONG
這是一家小醫館，女主人是位外地來的醫療忍者，醫術�諰�，讓
村民不得嘖嘖稱奇是女主人曾經將一匹死馬當活馬醫，霧忍村古時候
常有戰鬥，許許多多戰鬥受傷的人們都到此求醫。近幾年來，不知什
麼原因女主人停止再幫任何人治療，館內已經空蕩蕩的僅剩幾張空床
。
LONG
        );
        set("exits", ([
                "south" : ([ "filename" : __DIR__"wuyin.c",
                                         "x_axis" : 25,
                                         "y_axis" : 19, 
                                  ]),
                ]));

        setup();
  
}


