inherit F_FOOD;

void create()
{
    set_name("�]�O�Y", ({ "heal mp pill", "pill" }));
    set("unit", "��");
    set("base_value", 600);
    set("base_weight", 10);
    set("food_stuff", 1);              // �����q�A���~�@�w�n�������q
    set("long", "�Y�F�i�H�ߧY��_�A���]�O��(MP) 300 �I�C\n");
    set("heal", ([
        "mp": 300,
    ]) );
	setup();
}
