// combined_item.c

inherit ITEM;

// variables

int amount;

// implementations

int query_amount() { return amount; }

private void destruct_me() { destruct(this_object()); }

void set_amount(int v)
{
    if( v < 0 ) error("combine:set_amount less than 1.\n");
    amount = v;

    if( v == 0 ) call_out("destruct_me", 0);
    else this_object()->set_weight((int)(v * (float)query("base_weight")));
}

void add_amount(int v) { set_amount(amount+v); }

varargs string short(int raw)
{
    if( raw ) return ::short(raw);
    return chinese_number(query_amount()) + query("unit") + ::short(raw);
}

varargs int move(mixed dest, int silent)
{
	string file = base_name(this_object());
    object ob;
    if( ! ::move(dest, silent) ) return 0;
    
    // 已經裝備起來的物品，不應該與其它物品合併
    if( this_object()->query("equipped") ) return 1;
	
	// 已經改變的物品資料，不能與其它的物品合併(因為可能資料不同，一合就變一樣了)
    if( this_object()->query("changed") ) return 1;

    // 自動合併樣同物件，不限定是否是人物身上
    if( environment()->is_area() ) {
    	mapping info = this_object()->query("area_info");
    	if( !mapp(info) ) return 0;
    	foreach(ob in environment()->query_inventory(info["x_axis"], info["y_axis"]) ) {
		    if( ob == this_object() ) continue;
		    if( base_name(ob) == file ) {
				amount += (int)ob->query_amount();
				destruct(ob);
		    }
    	}
    } else {
		foreach(ob in all_inventory(environment())) {
		    if( ob == this_object() ) continue;
		    if( base_name(ob) == file ) {
				amount += (int)ob->query_amount();
				destruct(ob);
		    }
		}
	}
    set_amount(amount);

    return 1;
}

int render_value()
{
    return to_int(query("base_value") * amount);
}

void setup()
{
    ::setup();

    if( !amount ) set_amount(1);

    set("value", (: render_value :));
}