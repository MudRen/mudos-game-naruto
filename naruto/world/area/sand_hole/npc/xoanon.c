#include <npc.h>
#include <ansi.h>

void create()
{
    if( random(40) == 20 ) {
        set_name(HIY"黃金石像巨兵"NOR, ({ "golden xoanon", "xoanon" }) );
        set_level(45);
        set("long", "金色的巨大石像兵，據說是石像被太陽照射後所變化而成。\n");
        set("item_drop", "/world/area/sand_hole/npc/eq/waist.c");
        set("molecule", 1);            // 分子
        set("denominator", 100);       // 分母
        set("set_drop", ({
            ([ "type":"wp", "id":6, "amount":1, "p1":40, "p2":100 ]),       // 雙刃斧
            ([ "type":"wp", "id":37, "amount":1, "p1":15, "p2":100 ]),      // 長柄砍斧
            ([ "type":"eq", "id":113, "amount":1, "p1":1, "p2":400 ]),      // 太陽之護帶
        }) );
    } else {
        set_name("石像巨兵", ({ "xoanon" }) );
        set_level(35);
        set("long", "被沙盜們驅使的奇怪石像，似乎是沙穴遠古遺址的遺蹟。\n");
        set("item_drop", "/world/area/sand_hole/npc/eq/waist.c");
        set("molecule", 1);            // 分子
        set("denominator", 400);       // 分母
        set("set_drop", ({
            ([ "type":"wp", "id":44, "amount":1, "p1":40, "p2":100 ]),      // 迴旋斧
            ([ "type":"wp", "id":32, "amount":1, "p1":15, "p2":100 ]),      // 巨斧
        }) );
    }
    set_race("human");
    set("attitude", "aggressive");
    set("age", 1000+random(5001));
    set("title",YEL"古代遺蹟"NOR);
    setup();
    carry_object(_DIR_AREA_"thorn_pine/npc/wp/whirls_axe.c")->wield("twohanded");
    carry_object(_DIR_AREA_"blood_wild/npc/eq/black_streak_gloves.c")->wear();
    carry_object(__DIR__"eq/waist.c")->wear();
    add_temp("apply/armor", 300);
}
