#include <ansi.h>
inherit NPC;
void create()
{
    set_name("赦生童子", ({ "she sheng tong zi" , "zi" }) );
    set_race("human");
    set_level(75);
    set("long","異度魔君麾下頭號殺將，雙眼罩著奇特的封印，手持狼煙戟，\n"
                "騎乘一頭巨大狼獸，鎮守著異空間的赦生道。\n"
                "一旦狼煙揮動，剎時電流異閃，代表無盡的殺戮。\n");
    set("age",30);
    set("title", "赦生道守路者");
    setup();
    carry_object(__DIR__"eq/pike.c")->wield("twohanded");

}

