#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("防具商人", ({ "equip vendor", "vendor" }));
    set_race("human");
    set_level(50);
    set("age", random(50)+18);

    set("long", "無奸不成商，十足的奸商樣的老奸商人。\n");

    // 設定商人所販賣的物品
    // set_goods(代碼, 種類, 編號, 數量, 單價)
    // 商人能販賣的東西只能由 query 指令裡查 eq, wp, food 能查出來的物品
    // 如 set_goods(1, "food", 1, 10, -1) 表示販賣 query 指令查出來的food編號為1的食品十個
    // 若數量設定 -1 表示無限量供應
    // 若單價設為 -1 表示價錢是使用該物件設定的value
    // 代碼是用於 buy 指令上，如 buy 1 則會向商人買下代碼為1的商品

    set_goods(1, "eq", 26, 10, -1);
    set_goods(2, "eq", 27, 10, -1);
    set_goods(3, "eq", 28, 10, -1);
    set_goods(4, "eq", 29, 10, -1);
    set_goods(5, "eq", 30, 10, -1);
    set_goods(6, "eq", 31, 10, -1);
    set_goods(7, "eq", 32, 10, -1);
    set_goods(8, "eq", 33, 10, -1);
    set_goods(9, "eq", 34, 10, -1);
    set_goods(10, "eq", 35, 10, -1);
    set_goods(11, "eq", 36, 10, -1);
    set_goods(12, "eq", 37, 10, -1);
    set_goods(13, "eq", 38, 10, -1);
    set_goods(14, "eq", 39, 10, -1);
    set_goods(15, "eq", 40, 10, -1);
    set_goods(16, "eq", 41, 10, -1);
    set_goods(17, "eq", 42, 10, -1);
    set_goods(18, "eq", 43, 10, -1);
    set_goods(19, "eq", 44, 10, -1);
    set_goods(20, "eq", 45, 10, -1);
    set_goods(21, "eq", 46, 10, -1);
    set_goods(22, "eq", 48, 10, -1);
    set_goods(23, "eq", 49, 10, -1);
    set_goods(24, "eq", 50, 10, -1);
    set_goods(25, "eq", 51, 10, -1);
    set_goods(26, "eq", 52, 10, -1);

    setup();
}