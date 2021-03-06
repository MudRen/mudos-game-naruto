// 點數兌換指令 by mouse 2009/2/17
// inherit "/adm/daemons/exchanged.c";
#include <ansi.h>
inherit F_CLEAN_UP;

void create()
{
    seteuid(getuid());
}

int auc_item(object item, int value, int amount)
{
    string name;
    object disco = new("/world/npc/disco.c");

    if( !wizardp(this_player()) ) return notify_fail("只有巫師才能增加新的兌換商品。\n");
    if( item->query("money_id") ) return notify_fail("「錢」是不能當成商店的。\n");

    name = item->query("name");

    if( !EXC_D->do_stock(this_player(), item, value, amount) ) return notify_fail("點數商似乎不願收下這樣物品。\n");

    CHANNEL_D->do_channel(disco, "aucc", "本次兌換商品"+name+"以 "YEL+value+NOR" 點兌換點數開始進行兌換活動！("+CHINESE_D->chinese_date(time())+")");
    destruct(disco);
    return 1;
}

int do_list_aucer(string aucer)
{
    this_player()->start_more(EXC_D->do_list(aucer));
    return 1;
}

int do_search_goods(string name)
{
    this_player()->start_more(EXC_D->do_search_goods(name));
    return 1;
}

int do_identify(int id)
{
    this_player()->start_more(EXC_D->do_identify(id));
    return 1;
}

int main(object me, string arg)
{
    int id, amount, value;
    object item;
    string *tuned_ch;

    tuned_ch = me->link()->query("channels");

    // 補充上 aucc 的頻道
    if( !pointerp(tuned_ch) ) me->link()->set("channels", ( { "aucc"  } ) );
    else if( member_array("aucc", tuned_ch)==-1 ) me->link()->set("channels", tuned_ch + ( { "aucc" }) );

    // 檢視所有拍賣物
    if( !arg ) return do_list_aucer(0);

    // 拍賣商品
    if( sscanf(arg, "sell %d %s value %d", amount, arg, value) == 3 ) {
        if( !(item = present(arg, me)) ) return notify_fail("你想要將什麼物品上架？\n");
        if( amount <= 0 ) return notify_fail("你想要將幾個物品上架？\n");
        if( !objectp(new(base_name(item))) ) return notify_fail("你似乎無法將這樣物品上架。\n");
        if( amount > 99999 ) return notify_fail("兌換物品上限最高只能 99999 個。\n");

        // 因為純粹將物品放上架，自己物品不會有損失
        // 所以上架失敗也不需再回復什麼東西
        if( !auc_item(item, value, amount) ) {
            destruct(item);
        }
        return 1;
    }
    if( sscanf(arg, "sell %s value %d", arg, value) == 2 ) {
        if( !(item = present(arg, me)) ) return notify_fail("你想要將什麼物品上架？\n");
        return auc_item(item, value, 1);
    }
    // 購買商品
    if( sscanf(arg, "buy %d %d", amount, id) == 2 ) {
        EXC_D->to_sell(this_player(), id, amount);
        return 1;
    }
    if( sscanf(arg, "buy %d", id) == 1 ) {
        EXC_D->to_sell(this_player(), id, 1);
        return 1;
    }
    // 搜尋拍賣物名稱
    if( sscanf(arg, "/%s", arg) == 1 ) return do_search_goods(arg);

    // 檢視商品
    if( sscanf(arg, "%d", id) == 1 ) return do_identify(id);

    // 刪除可兌換物品
    if( sscanf(arg, "delete %s", arg) == 1 ) {
        object disco = new("/world/npc/disco.c");
        if( EXC_D->get_goods(this_player(), atoi(arg)) ) CHANNEL_D->do_channel(disco, "aucc", "認為編號 " + arg + " 的商品人氣太低，決定將物品下架。");
        destruct(disco);
        return 1;
    }
    return notify_fail("指令錯誤，請參考<help exc>。\n");
}

int help(object me)
{
  write(@HELP
指令格式 : exc                                 列出所有可以兌換的點數商品
           exc <編號>                          檢視該物品的能力

           exc /<關鍵字>                       查詢某兌換商品的能力
                                               如： exc /劍  ,  exc /blade

           exc buy <編號>
           exc buy [數量] <編號>               兌換某編號兌換商品

           balance                             查詢目前有多少兌換點數

           (以下指令為巫師專用)

           exc sell <物品> value <價格>
           exc sell [數量] <物品> value <價格> 訂出新的兌換商品
           exc delete <編號>                   將兌換商品刪除

HELP);
    return 1;
}
