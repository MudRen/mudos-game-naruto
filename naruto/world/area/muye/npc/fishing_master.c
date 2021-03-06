#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("捕魚人", ({ "fishing master", "master" }));
    set_race("human");
    set_level(50);
    set("age", random(50)+18);

    set("long", "捕魚界中的第一把交椅，你可以跟他買釣竿來釣魚。\n");

    // 設定商人所販賣的物品
    // set_goods(代碼, 種類, 編號, 數量, 單價)
    // 商人能販賣的東西只能由 query 指令裡查 eq, wp, food 能查出來的物品
    // 如 set_goods(1, "food", 1, 10, -1) 表示販賣 query 指令查出來的food編號為1的食品十個
    // 若數量設定 -1 表示無限量供應
    // 若單價設為 -1 表示價錢是使用該物件設定的value
    // 代碼是用於 buy 指令上，如 buy 1 則會向商人買下代碼為1的商品

    set_goods(1, "wp", 15, 10, -1);

    // 設定掉落物結構： (分子/分母) 是掉落機率
    // ({ ([ "type":類別, "id":編號, "amount":數量, "p1":分子, "p2":分母 ]),
    //    ([ ... ]), ([ ... ]), ... })
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":100+random(100), "p1":50, "p2":100 ]),  // 銀子
        ([ "type":"eq", "id":21, "amount":1, "p1":70, "p2":100 ]),     // 布手套
        ([ "type":"eq", "id":7, "amount":1, "p1":70, "p2":100 ]),     // 布衣
        ([ "type":"eq", "id":64, "amount":1, "p1":20, "p2":100 ]),     // 斗笠
        ([ "type":"wp", "id":15, "amount":1, "p1":60, "p2":100 ]),     // 釣竿
    }) );

    setup();
}
