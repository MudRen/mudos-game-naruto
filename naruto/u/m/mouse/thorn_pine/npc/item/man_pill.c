inherit F_FOOD;

void create()
{
    set_name("�G�H��", ({ "twoman pill", "pill" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 1500);
        set("base_weight", 10);
        set("food_stuff", 10);   // �����q�A���~�@�w�n�������q
        set("long", "��ɥR�믫�P�ۢު��}�ġC\n");
        set("condition", ([ 
            "apheal4": ([ "duration": 15 ]),
            "mpheal4": ([ "duration": 15 ]),
        ]));
    }
    setup();
}
