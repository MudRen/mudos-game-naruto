inherit F_FOOD;
void create()
{
    set_name("�W�Ťj�ɤY", ({ "super big pill", "pill" }));
        set("unit", "��");
    set("base_value", 999999);
        set("base_weight", 10);
        set("food_stuff", 10);                            // �����q�A���~�@�w�n�������q
    set("long", "�Y�F�i�H�ߧY��_�A���]�O��(MP)��O��(HP)��O��(AP) 5000 �I�C\n");
    set("heal", ([
        "ap": 5000,
        "hp": 5000,
        "mp": 5000,
    ]) );
        setup();
}

