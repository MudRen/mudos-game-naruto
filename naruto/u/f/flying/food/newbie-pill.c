inherit F_FOOD;

void create()
{
        set_name("�s��L³�Y", ({ "newbie pill" ,"pill"}));
        if( !clonep() ) {
                set("unit", "��");
                set("base_unit", "��");
                set("base_value", 10);             // ������ġA���ݭn�ӶQ�A�����a�R�o�_
                set("base_weight", 10);
                set("food_stuff", 20);              // �����q�A���~�@�w�n�������q
                set("long", "�@�ɷs��L³�Y�C\n"
                    "�i�Y�@���o50�I�ɮĪ��ѯŴ����N�H�΢ѯ��ٶ��N�C�j\n");
                set("condition", ([ "apheal1": ([ "duration": 50 ]),
                                        "hpheal1": ([ "duration": 50 ]),
                                        ]));
        }
        setup();
}


