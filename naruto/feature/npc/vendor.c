/* vendor.c 商人 */

#include <ansi.h>
#include <query.h>

mapping goods = ([]);

// 設定販賣的物品
void set_goods(int number, string type, int id, int amount, int value)
{
    goods[number] = ([]);
    goods[number]["type"] = type;
    goods[number]["id"] = id;
    goods[number]["amount"] = amount;
    goods[number]["amount_max"] = amount;
    goods[number]["value"] = value;
}

string do_list()
{
	int index, maximum;
	string msg;
    mapping record;

    if( (maximum=sizeof(goods)) <= 0 )
    	return this_object()->query("name") + "目前沒有販賣任何物品。\n";

    msg  = "╭──────────────────────────────────╮\n";
    msg += sprintf("│%-68s│\n", this_object()->query("name") + "目前的商品列表");
    msg += "├──────────────────────────────────┤\n";
    msg += "│編號    數量  單價/銀兩  名稱                                       │\n";
    msg += "├──────────────────────────────────╯\n";

    for(index=1;index<=maximum;index++) {
        if( undefinedp(goods[index]) ) continue;
        switch( goods[index]["type"] ) {
            case "eq":   record = ITEM_D->do_query("eq", goods[index]["id"]); break;
            case "wp":   record = ITEM_D->do_query("wp", goods[index]["id"]); break;
            case "food": record = ITEM_D->do_query("food", goods[index]["id"]); break;
            case "obj": record = ITEM_D->do_query("obj", goods[index]["id"]); break;
            default: continue;
        }
        if( !mapp(record) ) continue;

        msg += sprintf("│%4d %7s %10d  %-s\n", 
                       index,
                       ( goods[index]["amount_max"] == -1 ? "oo" : "" + goods[index]["amount"] ),
                       goods[index]["value"] < record["value"] ? record["value"] : goods[index]["value"],
                       record["name"] );
    }

    msg += "├──────────────────────────────────╮\n";
    msg += "│輸入 help trade 瞭解如何使用交易指令。                              │\n";
    msg += "╰──────────────────────────────────╯";

    return msg;
}

int to_sell(object who, int number, int amount)
{
    int value;
    object item;
    mapping record;

    if( !objectp(who) ) return 0;

    if( sizeof(all_inventory(who)) >= 40 ) {
        tell_object(who, "店家發現你似乎拿不動這樣商品，便不賣你了。\n");
        return 1;
    }

    if( who->query_encumbrance() >= who->query_ability("carriage") ) {
        tell_object(who, "店家發現你似乎拿不動這樣商品，便不賣你了。\n");
        return 1;
    }

    if( amount <= 0 ) {
        tell_object(who, "你想要買幾個商品？\n");
        return 1;
    }

    if( amount > 999 ) {
        tell_object(who, "一次最多只能購買999個商品...\n");
        return 1;
    }
    // 沒有這個商品編號
    if( undefinedp(goods[number]) ) {
        tell_object(who, "沒有這個商品編號。\n");
        return 1;
    }

    // 非無限量供應之商品的數量檢查
    if( !amount ) amount = 1;
    if( goods[number]["amount_max"] != -1 && goods[number]["amount"] < amount ) {
        tell_object(who, "這個商品數量沒有這麼多。\n");
        return 1;
    }

    switch( goods[number]["type"] ) {
        case "eq":   record = ITEM_D->do_query("eq", goods[number]["id"]); break;
        case "wp":   record = ITEM_D->do_query("wp", goods[number]["id"]); break;
        case "food": record = ITEM_D->do_query("food", goods[number]["id"]); break;
        case "obj": record = ITEM_D->do_query("obj", goods[number]["id"]); break;
        default:
            tell_object(who, "店家發現這個商品有問題後隨即下架了，你無法購買。\n");
            // 或許檔案已經不存在，從列表中刪除
            map_delete(goods, number);
            return 1;
    }
    if( !mapp(record) ) {
        tell_object(who, "店家發現這個商品有問題後隨即下架了，你無法購買。\n");
        // 或許檔案已經不存在，從列表中刪除
        map_delete(goods, number);
        return 1;
    }

    if( goods[number]["value"] < record["value"] ) value = record["value"];
    else value = goods[number]["value"];

    value = value * amount;

    // 銀行錢不夠
    if( who->query("bank") < value ) {
        tell_object(who, "你銀行裡的錢不夠，無法購買此商品。\n");
        return 1;
    }

    // 無法建立該商品
    if( !objectp(item = new(record["file_name"])) ) {
        tell_object(who, "店家發現這個商品有問題後隨即下架了，你無法購買。\n");
        // 或許檔案已經不存在，從列表中刪除
        map_delete(goods, number);
        return 1;
    }
    
    if( !function_exists("set_amount", item) && amount > 1) {
        tell_object(who, "這個東西一次只能買一個。\n");
        destruct(item);
        return 1;
    }

    item->set_amount(amount);
    
    if( !item->move(who) ) {
        tell_object(who, "店家發現你似乎拿不動這樣商品，便不賣你了。\n");
        // 刪除物品
        destruct(item);
        return 1;
    }

    message_vision("$N花了" + chinese_number(value) + "兩銀子向" + this_object()->query("name") + "買下" +
                   chinese_number(amount) + "個" + record["name"] + "。\n", who);

    // 從銀行扣錢
    who->add("bank", -value);

    // 非無限量供應的商品數量需改變
    if( goods[number]["amount_max"] != -1 )
        goods[number]["amount"] -= amount;

    return 1;
}

// 恢復商品的數量
void reset()
{
	int index, maximum;
	maximum = sizeof(goods);
    for(index=1;index<=maximum;index++) {
        if( undefinedp(goods[index]) ) continue;
        goods[index]["amount"] = goods[index]["amount_max"];
    }
}
