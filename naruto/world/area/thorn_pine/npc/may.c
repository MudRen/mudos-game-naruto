#include <npc.h>

inherit F_VENDOR;

void create()
{
    set_name("豹妹", ({ "bow may", "may" }));
    set_race("human");
    set_level(60);
    set("age", 20);
    set("gender", "female");
    set("nickname","投擲武器專賣");
    set("long", "排行么妹，古靈精怪，常發明一些投擲武器。\n");
    set("camp", "bow");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "ccc" :),
        (: command, "say 新產品！炸藥 & 戰鬥急救包！" :),
    }));

    // 設定商人所販賣的物品
    // set_goods(代碼, 種類, 編號, 數量, 單價)
    // 商人能販賣的東西只能由 query 指令裡查 eq, wp, food 能查出來的物品
    // 如 set_goods(1, "food", 1, 10, -1) 表示販賣 query 指令查出來的food編號為1的食品十個
    // 若數量設定 -1 表示無限量供應
    // 若單價設為 -1 表示價錢是使用該物件設定的value
    // 代碼是用於 buy 指令上，如 buy 1 則會向商人買下代碼為1的商品

    set_goods(1, "wp", 5, 50, -1);     // 苦無
    set_goods(2, "wp", 11, 50, -1);    // 短劍
    set_goods(3, "obj", 58, -1, -1);     // 精神急救
    set_goods(4, "obj", 65, -1, -1);     // 體力急救
    set_goods(5, "obj", 66, -1, -1);     // 念查急救
    set_goods(6, "obj", 62, 50, -1);    // 飛鏢
    set_goods(7, "obj", 63, 30, -1);    // 炸藥
    set_goods(8, "obj", 64, 10, -1);    // 棘
    set_goods(9, "obj", 59, 10, -1);    // 炸彈

    setup();
}
