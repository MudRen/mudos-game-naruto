inherit F_FOOD;

void create()
{
    set_name("�J�խ�", ({ "albumin jelly", "jelly" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 100);            // ������ġA���ݭn�ӶQ�A�����a�R�o�_
        set("base_weight", 10);
        set("food_stuff", 5);              // �����q�A���~�@�w�n�������q
        set("long", "�@���γD�J�ջs�����G��A����[����O�^�_�C\n");
        set("condition", ([ "hpheal2": ([ "duration": 15 ]) ]) );
    }
    setup();
}
