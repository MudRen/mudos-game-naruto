// silver.c

inherit MONEY;

void create()
{
	set_name("�Ȥl", ({"silver", "silver_money"}));
	if( !clonep() ) {
		set("money_id", "silver");
		set("long", "�ժ�᪺�Ȥl�M�H���H�R���Ȥl�C\n");
                set("unit", "��");
		set("material", "silver");
		set("base_value", 1);
		set("base_weight", 5);
	}
	set_amount(1);
	setup();
}

