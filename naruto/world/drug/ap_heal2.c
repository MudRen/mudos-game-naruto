inherit F_FOOD;

void create()
{
    set_name("�j��O�Y", ({ "big heal ap pill", "pill" }));
    set("unit", "��");
    set("base_value", 1800);
	set("base_weight", 10);
	set("food_stuff", 1);              // �����q�A���~�@�w�n�������q
    set("long", "�Y�F�i�H�ߧY��_�A���믫��(AP) 900 �I�C\n");
    set("heal", ([
        "ap": 900,
    ]) );
	setup();
}
