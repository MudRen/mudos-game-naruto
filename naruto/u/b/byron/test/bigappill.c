inherit F_FOOD;
void create()
{
    set_name("�W�Ťj�ɤY", ({ "super ap pill", "pill" }));
        set("unit", "��");
    set("base_value", 999999);
        set("base_weight", 10);
        set("food_stuff", 1);                            // �����q�A���~�@�w�n�������q
    set("long", "�Y�F�i�H�ߧY��_�A����O��(AP) 9999 �I�C\n");
    set("heal", ([
        "ap": 9999,
        ]) );
        setup();
}

