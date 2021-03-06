#include <ansi.h>

inherit AREA;

void create()
{
    set("name", "琥珀之塔Ⅰ層");
    set("x_axis_size", 30);            // 橫向大小
    set("y_axis_size", 30);            // 縱向大小
    setup();
    set("no_recall", 1);
    set("no_drop", 1);
}

void init()
{
    add_action("do_up", "up");
    add_action("do_out", "exit");
    add_action("do_move", "move");
    add_action("do_move", "sfly");
}

int do_move(string arg)
{
    message_vision("$N企圖離開此地，但是一直找不到出口。\n", this_player());
    return 1;
}

int do_up(string arg)
{
    int x, y;
    object me, area, npc;
    string area_file = "/world/area/four_wheel_tower/sand_2f.c";

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->is_busy() ) return notify_fail("你現在正在忙，一時之間無法移動。\n");

    if( !userp(me) || !this_object()->query_data(x, y, "cord_up") ) return notify_fail("這個方向沒有出路。\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    if( npc = present("_KING_ONE_", environment(me)) ) {
        message_vision("通往二樓的路被$N擋住了，$n無法通過。\n", npc, me);
        return 1;
    }
    message_vision("$N緩緩地走上樓去。\n", me);
    if( !area_move(area, me, x, y) ) return 0;
    return 1;
}

int do_out(string arg)
{
    int x, y;
    object me, area, npc;
    string area_file = "/world/area/four_wheel_tower/sand_0f.c";

    me = this_player();
    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");

    if( me->is_busy() ) return notify_fail("你現在正在忙，一時之間無法移動。\n");

    if( !userp(me) || !this_object()->query_data(x, y, "door_out") ) return notify_fail("這個方向沒有出路。\n");

    if( !objectp(area = load_object(area_file)) ) return 0;
    if( !area->is_area() ) return 0;
    message_vision("$N推開大門走了出去。\n", me);
    if( !area_move(area, me, 7, 40) ) return 0;
    return 1;
}

object do_random(string category)
{
    int rnd, *key;
    key = keys(ITEM_D->do_query_all(category));
    rnd = key[random(sizeof(key))];
    return ITEM_D->get_item(category, rnd);
}

void do_ask(string arg, object who, string *inv)
{
    object room;
    int i;

    room = load_object("/world/area/wizard/guildhall.c");

    for(i=0;i<sizeof(inv);i++) {
        if( arg == inv[i] ) who->set_temp("check_robot_ok", 1);
    }
    if( !who->query_temp("check_robot_ok") ) {
        tell_object(who, HIR"\n你答錯了！一道"HIY"天雷"HIR"將你打回天上人間！\n\n"NOR);
        if( !who->move(room) ) {
            tell_object(who, "\n你東躲西閃...居然僥倖逃過天雷的攻擊！\n\n"NOR);
            return;
        }
        message_vision(HIW"一陣白光過去，$N「唉喲∼」一聲，突然從天空中掉了下了，跌了個狗吃屎。\n"NOR, who);
        who->set_stat_current("ap", 1);
        who->set_stat_current("hp", 1);
        who->set_stat_current("mp", 1);
    } else {
        who->delete_temp("ELF_HOUSE");
        tell_object(who, "\n低沉的聲音傳過你的耳邊："HIG"你過關了！\n\n"NOR);
    }
    who->delete_temp("check_robot_ok");
    return;
}

int valid_leave(object me, string dir)
{
    object ob, item;
    int x, y;
    string *inv;

    if( !me ) return 0;

    x = me->query("area_info/x_axis");
    y = me->query("area_info/y_axis");
    ob = this_object();

    // return 0; 表示移動失敗
    if( userp(me) && ob->query_data(x, y, "check_robot") ) {
        switch( random(4) ) {
            case 0: item = do_random("wp"); break;
            case 1: item = do_random("eq"); break;
            case 2: item = do_random("obj"); break;
            default: item = do_random("food"); break;
        }
        if( !objectp(item) ) {
            tell_object(this_player(), "但是並沒有發生任何事。\n");
        } else {
            inv = item->parse_command_id_list();
            tell_object(this_player(), YEL"忽然沙堆中噴出一道金光！\n"NOR);
            tell_object(this_player(),"想要繼續在這裡移動，請先輸入 "+item->query("name")+" 的物品ＩＤ為何："NOR);
            input_to("do_ask", this_player(), inv);
        }
        destruct(item);
    }
    return ::valid_leave(me, dir);
}
