/* get.c
   指令： 拾取
   create by Acme
*/

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int isCombined(object item)
{
    if( !objectp(item) ) return 0;
    if( !function_exists("query_amount", item) ) return 0;
    return 1;
}

object doGetFrom(object me, string from)
{
    object ofrom;
    ofrom = present(from, me);
    
    if( !objectp(ofrom) ) ofrom = present(from, environment(me));
    if( !objectp(ofrom) ) {
        tell_object(me, "你附近沒有 " + from + " 這樣東西。\n");
        return 0;
    }

    if( (living(ofrom) || userp(ofrom)) ) {
        if( !wizardp(me) ) {
            tell_object(me, "你沒辦法這麼做。\n");
            return 0;
        } else {
            if( wiz_level(me) <= wiz_level(ofrom) ) {
                tell_object(me, "你的巫師等級必須比對方高，才能搜身。\n");
                return 0;
            }
        }
    }
    return ofrom;
}

object doGetItem(object me, object from, string sitem, int amount)
{
    object item;

    // 檢查物品是否存在
    if( !objectp(item = present(sitem, from)) ) {
        if( from == environment(me) )
            tell_object(me, "你附近沒有這樣東西。\n");
        else if( from->is_character() )
            tell_object(me, from->name() + "身上沒有這樣東西。\n");
        else tell_object(me, from->name() + "裡面沒有這樣東西。\n");
        return 0;
    }

    if( (living(item) || userp(item)) || item->is_corpse() ) {
    tell_object(me, "你不能這樣做。\n");
        return 0;
    }

    if( isCombined(item) ) {  // 複合型物品
    if( amount == 0 ) amount = item->query_amount();

        if( amount < 1 || amount > item->query_amount() ) {
            if( from == environment(me) ) tell_object(me, "你附近沒有這麼多數量的" + item->name() + "。");
            else if( from->is_character() ) tell_object(me, from->name() + "身上沒有這麼多數量的" + item->name() + "。");
            else tell_object(me, from->name() + "裡面沒有這麼多數量的" + item->name() + "。");
            return 0;
        }

        if( amount == item->query_amount() ) // 拿取的數量剛好一樣
            return item;
        else {                               // 拿取的數量不一樣
            // 進行分堆
            object new_item;
            new_item = new(base_name(item));
            new_item->set_amount(amount);
            item->add_amount(-amount);
            return new_item;
        }

    } else return item;                 // 非複合型物品
}

int doGet(object me, object from, object item)
{
    int amount;
    string msg;
    object *guard, *obj;

    if( !objectp(me) || !objectp(from) || !objectp(item) ) {
        tell_object(me, "你沒有辦法拿任何東西。\n");
        return 0;
    }
    
    if( item->query("no_get") ) {
        tell_object(me, "你無法拿取這樣東西。\n");
        return 0;
    }
    
    if( guard = item->query_temp("guarded") ) {
        guard = filter_array(guard, (: objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2) :), me);
        if( sizeof(guard) ) return notify_fail( guard[0]->name() + "正守在" + item->name() + "一旁﹐防止任何人拿走。\n");
    }
    
    if( me->over_encumbranced() ) {
        tell_object(me, "你已經負荷過重了。\n");
        return 0;
    }
    obj = all_inventory(me);

    if( sizeof(obj) >= 40 ) {
        tell_object(me, "你身上的物品已經超過攜帶上限了。\n");
        return 0;
    }
    amount = item->query_amount();

    if( !item->move(me) ) {
        tell_object(me, "你無法拿取這樣東西。\n");
        // 移回原來的地點(因為有可能經過分堆
        if( from->is_area() ) move_side(item, me);
        else item->move(from);
        return 0;
    }
    msg = "$N";

    if( from == environment(me) ) {
        msg += "撿起";
    } else {
        if( from->is_character() ) {
            msg += "從" + from->name() + "身上";
            if( item->query("equipped") ) msg += "卸下";
            else msg += "搜出";
        } else msg += "從" + from->name() + "中拿出";
    }
    
    if( isCombined(item) ) msg += chinese_number(amount);
    else msg += "一";

    msg += item->query("unit") + "$n。\n";

    message_vision(msg, me, item);

    return 1;
}

int doGetAll(object me, object from)
{
    object item, *inv;

    if( me->is_fighting() ) {
        tell_object(me, "你現在沒空一次拿這麼多東西。\n");
        return 0;
    }

    // 取得環境中所有物件集
    if( from->is_area() ) {
        mapping info;
        if( (info = me->query("area_info")) )
        inv = from->query_inventory(info["x_axis"], info["y_axis"]);
    } else inv = all_inventory(from);

    foreach(item in inv) {    
        if( item->query("no_get") ) continue;
        if( (living(item) || userp(item)) ) continue;
        if( me->over_encumbranced() ) break;
        doGet(me, from, item);
    }

    tell_object(me, "ok.\n");
    return 1;
}

int main(object me, string arg)
{
    int amount = 0;
    string item, from;
    object oitem, ofrom;

    if( !arg ) return notify_fail("你要拿什麼東西？\n");
    if( me->is_busy() ) return notify_fail("你現在還沒有空拿東西。\n");
    
    // 從某個物品裡面拿出數個東西
    if( sscanf(arg, "%d %s from %s", amount, item, from) == 3 ) {
        if( !(ofrom = doGetFrom(me, from)) ) return 1;

    // 從某個物品裡面拿出東西
    } else if( sscanf(arg, "%s from %s", item, from) == 2 ) {
    if( !(ofrom = doGetFrom(me, from)) ) return 1;
    if( item == "all" ) {
        doGetAll(me, ofrom);
        return 1;
    }

    // 從環境中拿取
    } else if( sscanf(arg, "%d %s", amount, item) == 2 ) {
        ofrom = environment(me);
    } else {
        item = arg;
        ofrom = environment(me);
        if( item == "all" ) {
            doGetAll(me, ofrom);
            return 1;
        }
    }
    if( !(oitem = doGetItem(me, ofrom, item, amount) ) ) return 1;
    if( !doGet(me, ofrom, oitem) ) return 1;

    if( me->is_fighting() ) me->start_busy(1);

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : get <物品名稱> [from <容器名>]

這個指令可以讓你撿起地上或容器內的某樣物品。
若物品名稱輸入為 all 表示要拿取所有東西
HELP
    );

return 1;
}
