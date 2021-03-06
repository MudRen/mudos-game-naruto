#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

// 一般的魚
string *fish_list = ({
    "/world/area/benthal/npc/food/clam.c",
    "/world/area/benthal/npc/food/urchin.c",
    "/world/area/benthal/npc/food/cuttlefish.c",
    "/world/area/benthal/npc/food/octopus.c",
    "/world/area/benthal/npc/food/lobster.c",
});

// 特殊物品
string *spec_list = ({
    "/world/area/lake/npc/item/vase2.c",            // 破花瓶
    "/world/eq/feet/straw.c",                       // 草鞋
    "/world/area/old_forest/npc/eq/coco.c",         // 椰子殼
    "/world/eq/head/boiler.c",                      // 鍋子
    "/world/eq/face/fglasses.c",                    // 蛙鏡
    "/world/eq/belt/hoop.c",                        // 呼拉圈
    "/world/wp/radish.c",                           // 蘿蔔
    "/world/area/sifa_isle/npc/wp/gun.c",           // 海軍制式鐵砲
    "/world/wp/sword.c",                            // 短劍
    "/world/wp/dagger.c",                           // 苦無
    "/world/wp/pairrod.c",                          // 雙截棍
    "/world/area/thorn_pine/npc/wp/lines_sword.c",  // 刻紋劍
});


void create()
{
    set_name("魚叉", ({ "gaff" }));
    set_weight(15000);
    setup_weapon(4, 8, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "把");
        set("value", 1000);
        set("long", "一根普通的魚叉，可以當武器使用，也可以拿來抓海產(gaffing)，。\n"
                    "當你釣累了可以放棄(giveup)。抓海產只能在「海底」的海草進行。\n" );
    }
    setup();
}
void init()
{
    if( environment(this_object()) && userp(environment(this_object())) ) {
        add_action("do_gaffing", "gaffing");
        add_action("do_giveup", "giveup");
    }
}

int do_giveup(string arg)
{
    if( !this_player()->query_temp("is_gaffing") )
        return notify_fail("你沒有在抓海產吧。\n");
    tell_object(this_player(), "你放棄繼續抓海產。\n");
    this_player()->delete_temp("is_gaffing");
    return 1;
}

int do_gaffing(string arg)
{
    int delay;
    object env, me = this_player();

    if( !objectp(env = environment(me)) ) return 0;

    if( !this_object()->query("equipped") ) 
        return notify_fail("必須裝備(wield)魚叉後才可以抓海產。\n");

    if( me->query_temp("weapon/righthand") != this_object() ) 
        return notify_fail("必須裝備(wield)魚叉後才可以抓海產。\n");
    if( me->query_temp("is_gaffing") ) return notify_fail("你已經在抓海產了。\n");
    if( me->is_fighting() || me->is_busy() ) return notify_fail("你正在忙，沒辦法抓海產。\n");

    if( env->is_area() ) {
        int x, y;
        x = me->query("area_info/x_axis");
        y = me->query("area_info/y_axis");
        if( !env->query_data(x, y, "gaffing") ) return notify_fail("這裡不能抓海產！\n");
    } else {
        if( !env->query("gaffing") ) return notify_fail("這裡不能抓海產！\n");
    }
    switch( random(4) ) {
        case 0:
            message_vision("$N拿起魚叉，準備好大蔞子，今天要來個滿載而歸。\n",me);
            break;
        case 1:
            message_vision("$N揉揉眼睛集中精神，快速地潛到海草堆附近，準備開始抓海產。\n",me);
            break;
        case 2:
            message_vision("$N浮上海面吸了一大口氣後又潛了下來，做好萬全的準備。\n",me);
            break;
        default:
            message_vision("$N鎖定了眼前的海草堆為目標，在附近設下陷阱後開始等待海產上勾...\n",me);
            break;
    }

    me->set_temp("is_gaffing", 1);

delay = 5 + random(5);

me->start_busy(delay);

    // 進入釣魚 function
    call_out("gaffing_2", delay, me);

    return 1;
}

int gaffing_2(object me)
{
    int x=0, y=0, delay;
    object item, env, mob;

    if( !me ) return 1;
    if( !me->query_temp("is_gaffing") ) return do_giveup("");
    if( !this_object()->query("equipped") ) return do_giveup("");
    if( me->query_temp("weapon/righthand") != this_object() ) do_giveup("");
    if( !objectp(env = environment(me)) ) return do_giveup("");
    if( me->is_fighting() ) return do_giveup("");

    if( env->is_area() ) {
        x = me->query("area_info/x_axis");
        y = me->query("area_info/y_axis");
        if( !env->query_data(x, y, "gaffing") ) return do_giveup("");
    } else {
        if( !env->query("gaffing") ) return do_giveup("");
    }
    switch( random(me->query_temp("is_gaffing")) ) {
        case 0: message_vision("$N找了老半天卻找不到半隻海產，覺得非常灰心...\n",me);  break;
        case 1: message_vision("$N似乎看到海草堆裡有個影子在動，一撥開海草卻發現只是雙破鞋...\n",me); break;
        case 2: message_vision("$N發瘋似的拿起魚叉往海草堆亂戳...結果只嚇跑了一堆海洋生物...\n",me); break;
        case 3: message_vision("$N發現海產的蹤影後立刻用力一刺，卻被海產靈活的游走了...\n",me); break;
        case 4: message_vision("$N氧氣似乎不夠了，急急忙忙游上海面吸一口氣又游回來繼續尋找海產...\n",me); break;
        case 5: message_vision("$N在海草堆中尋找海產，卻不慎被烏賊噴了一臉墨汁...\n",me); break;
        case 6: message_vision("一條魚在$N的腳邊游來游去...$N用力一叉卻叉中自己的腳，痛的哇哇大叫...\n",me); break;
        case 7: message_vision("$N將海草堆旁的石頭搬開尋找海產，但是卻無功而返...\n",me); break;
        default:
            if( random(100) > 1 ) {     // 釣中一般魚
                item = new( fish_list[random(sizeof(fish_list))] );
                if( !objectp(item) ) {
                    message_vision("$N發現這兒的海產已經沒了，只好收起魚叉準備換位置。\n",me);
                    me->delete_temp("is_gaffing");
                    return 1;
                }
                message_vision("$N在海草堆中發現了一個黑影！！慢慢的游了過去...\n",me);
                message_vision("$N在不驚動黑影的姿勢下用力一刺！結果刺中"
                                + ( item->query("base_unit") ? item->query("base_unit") : item->query("unit") ) + 
                               "$n放進簍子裡...\n", me, item);
            } else {                    // 釣中特殊物
                item = new( spec_list[random(sizeof(spec_list))] );
                if( !objectp(item) ) {
                    message_vision("$N發現這兒的海產已經沒了，只好收起魚叉準備換位置。\n",me);
                    me->delete_temp("is_gaffing");
                    return 1;
                }
                message_vision("$N在海草堆中發現了一個黑影！！慢慢的游了過去...\n", me);
                message_vision("$N在不驚動黑影的姿勢下用力一刺！發現是個奇怪的物品...\n", me);
            }
            if( !item->move(me) ) {
                message_vision("$N發覺簍子已經裝滿了，只好將$n放回海中...\n", me, item);
                destruct(item);
            }
            me->add_temp("is_gaffing", -3-random(4));
            if( me->query_temp("is_fishing") <= 0 )
                me->set_temp("is_fishing", 1);
            break;
    }
    // 5%機率自動停止
    if( random(100) < 5 ) {
        switch( random(4) ) {
            case 0:
                message_vision("$N累的喘不過氣來，只好放棄尋找海產。\n",me);
                break;
            case 1:
                message_vision("$N不小心踩到自己設的陷阱...被卡住沒辦法抓海產了。\n",me);
                break;
            case 2:
                message_vision("一艘船從上方海面經過，把魚群全都嚇跑...看來只好換地方了。\n",me);
                break;
            default:
                mob = new(_DIR_AREA_"benthal/npc/monster.c");
                if( environment(me)->is_area() ) {
                    if( area_move(environment(me), mob, x, y) ) {
                        message_vision(CYN"忽然一隻龐然大物從沙地中竄出！嚇的$N馬上停止捕捉海產。\n"NOR,me);
                        break;
                    }
                    message_vision("忽然一個黑影從$N身旁飄過，$N警覺的四處張望停止捕捉海產。\n",me);
                    break;
                } else {
                    message_vision("忽然一個黑影從$N身旁飄過，$N警覺的四處張望停止捕捉海產。\n",me);
                    break;
                }
        }
        me->delete_temp("is_gaffing");
        return 1;
    }
    me->add_temp("is_gaffing", 1);

    delay = 5 + random(10);
    me->start_busy(delay);

    // 進入釣魚 function
    call_out("gaffing_2", delay, me);
    return 1;
}
