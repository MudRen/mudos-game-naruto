inherit F_FOOD;

void create()
{
    set_name("�G����", ({ "twoghost pill", "pill" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 1500);
        set("base_weight", 10);
        set("food_stuff", 10);   // �����q�A���~�@�w�n�������q
        set("long", "��ɥR��O�P�ۢު��}�ġC\n");
        set("condition", ([ 
            "mpheal4": ([ "duration": 15 ]),
            "hpheal4": ([ "duration": 15 ]),
        ]));
    }
    setup();
}
