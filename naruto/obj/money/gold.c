// gold.c

inherit MONEY;

void create()
{
	set_name("����", ({"gold", "ingot", "gold_money"}));
	if( !clonep() ) {
		set("money_id", "gold");
		set("long", "����᪺���l�M�H���H�R�����l�M�ڡ����l�T\n");
                set("unit", "��");
		set("material", "gold");
		set("base_value", 1000);
		set("base_weight", 10);
	}
	set_amount(1);
	setup();
}

