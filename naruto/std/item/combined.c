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
    
    // �w�g�˳ư_�Ӫ����~�A�����ӻP�䥦���~�X��
    if( this_object()->query("equipped") ) return 1;
	
	// �w�g���ܪ����~��ơA����P�䥦�����~�X��(�]���i���Ƥ��P�A�@�X�N�ܤ@�ˤF)
    if( this_object()->query("changed") ) return 1;

    // �۰ʦX�ּ˦P����A�����w�O�_�O�H�����W
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