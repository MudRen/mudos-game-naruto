inherit F_FOOD;

void create()
{
    set_name("������", ({ "noodles", "_BEEF_NOODLES_" }));
    if( !clonep() ) {
        set("unit", "�J");
        set("base_unit", "�J");
        set("base_value", 500);
        set("base_weight", 10);
        set("food_stuff", 30);
        set("long", @LONG
�ѽ��Ѫ��ѱi�Ұ����W�������ѡA�ҥΪ���ƬO�W�����סA�j���Y�M
�h�ؽ���Ҽ������������Y�A�ѱ����ߦ��l�A�f�t���ֳ\�������n�f
���סA�Y������A�@�ܴ��A���W�N��~�ҹ��������S�@������J�f��
�A���H�^���L�a�A�g�����f�C
�i�Y�@���o15�I�ɮĪ��ЯŴ����N�B�ЯŤѦa�N�H�΢Я��ٶ��N�C�j
LONG);
        set("condition", ([ "apheal2": ([ "duration": 15 ]),
                            "hpheal2": ([ "duration": 15 ]),
                            "mpheal2": ([ "duration": 15 ]),
                         ]));
    }
    setup();
}
