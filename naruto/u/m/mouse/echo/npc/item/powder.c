inherit F_FOOD;

void create()
{
    set_name("����", ({ "tooth powder", "powder" }));
    if( !clonep() ) {
        set("unit", "�]");
        set("base_unit", "�]");
        set("base_value", 100);            // ������ġA���ݭn�ӶQ�A�����a�R�o�_
        set("base_weight", 10);
        set("food_stuff", 5);              // �����q�A���~�@�w�n�������q
        set("long", "�s�T����ҿi�������A����ֳt�^�_�ۢޡC\n");
        set("condition", ([ "mpheal2": ([ "duration": 15 ]) ]) );
    }
    setup();
}
