inherit F_FOOD;

void create()
{
    set_name("���S�Y", ({ "Positive Lou pill", "pill" }));
    set("unit", "��");
    set("base_value", 600);
    set("base_weight", 10);
    set("food_stuff", 1);              // �����q�A���~�@�w�n�������q
    set("long", "���a�j�p�A�X���Ȧ�A���ƨ}�ġC\n");
    set("heal", ([
        "ap": 9999,
        "hp": 9999,
        "mp": 9999,


    ]) );
        setup();
}

