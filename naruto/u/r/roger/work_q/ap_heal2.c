inherit F_FOOD;

void create()
{
    set_name("�j��O�Y", ({ "big heal ap pill", "pill" }));
	if( !clonep() ) {
		set("unit", "��");
		set("base_unit", "��");
        set("base_value", 1000);
		set("base_weight", 10);
		set("food_stuff", 10);              // �����q�A���~�@�w�n�������q
        set("long", "�@���Y�F�i�H�ߧY��_�A���믫��100�I�C\n");
        set("heal_ap", 100);
	}
	setup();
}
