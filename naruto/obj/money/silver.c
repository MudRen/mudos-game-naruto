// silver.c

inherit MONEY;

void create()
{
	set_name("銀子", ({"silver", "silver_money"}));
	if( !clonep() ) {
		set("money_id", "silver");
		set("long", "白花花的銀子﹐人見人愛的銀子。\n");
                set("unit", "兩");
		set("material", "silver");
		set("base_value", 1);
		set("base_weight", 5);
	}
	set_amount(1);
	setup();
}

