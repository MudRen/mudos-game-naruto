#include <ansi.h>

inherit COMBINED_ITEM;

object owner;

// 設定主人
int set_owner(object ob)
{
    if( !objectp(ob) ) return 0;
    owner = ob;
}

// 查詢主人
object query_owner()
{
    if( !objectp(owner) ) return 0;
    return owner;
}

void create()
{
    set_name(HIK"寄壞蟲"NOR, ({ "parasitism bug", "bug", "_GI_BUG_" }));
    set("unit", "隻");
    set("base_value", 0);
    set("base_weight", 1);
    set("no_sac", 1);
    set("no_sell", 1);
    set("no_drop", 1);
    set("no_box", 1);
    set("no_give", 1);
    set("long", "油女一族所操使的蟲子，糧食為查克拉，所以能合併忍術使用。\n");
    call_out("eat_mp", 3, this_object());
    setup();
}

void init()
{
    add_action("do_rid", "rid");
}

int do_rid(string arg)
{
    if( this_player()->is_fighting() ) {
        tell_object(this_player(), "戰鬥中除蟲，只會讓你進退兩難而已。\n"NOR);
        return 1;
    }
    if( query("keep_this") ) {
        tell_object(this_player(), "這樣東西你已經 keep 無法丟棄。\n"NOR);
        return 1;
    }
    message_vision(CYN"$N將身上的$n"CYN"拔起來丟在地上，還兇狠地往$n"CYN"上踩了幾腳。\n"NOR, this_player(), this_object());
    tell_object(this_player(), "雖然清除了"HIK"寄壞蟲"NOR"，但還是難消你心頭之恨。\n"NOR);
    destruct(this_object());
    return 1;
}

void eat_mp()
{
    object me;
    int i, damage;

    me = query_owner();
    i = query_amount()*2;

    if( !me ) {
        me = environment(this_object());
        set_owner(me);
    }
    if( !objectp(this_object()) || !me ) return;

    message_vision("\n$N"HIM"伸出觸角劃破$n的皮肉，偷偷吸取$n的魔力。\n"NOR, this_object(), me);

    if( me->query_stat_current("mp") > i ) {
        if( userp(me) ) message_vision("$n的魔力居然快速流失，似乎損失了 "HIB+i+NOR" 點。\n\n"NOR, this_object(), me);
        me->damage_stat("mp", i, me);
    } else if( me->query_stat_current("mp") <= 0 ) {
        if( userp(me) ) message_vision("但是$n身上已經沒有任何魔力能提供$N吸取。\n\n"NOR, this_object(), me);
    } else {
        if( userp(me) ) message_vision("很快地$n身上剩餘的 "HIB+i+NOR" 點魔力就被$N給吸光了。\n\n"NOR, this_object(), me);
        me->set_stat_current("mp", 0);
    }
    call_out("eat_mp", 10);
    return;
}
