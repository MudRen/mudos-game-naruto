#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIR"����"HIW"�Ф��Y�y"NOR, ({ "red plume hood", "hood" }) );

    set_weight(1000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 650);
        set("long", "�@���۷��ӤH���檺�Y�y�A�W�Y�ٴ��۴X�ڬ���Ф�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
        	"armor": 2,
            "exact": 3,
        ]));
    }

    setup();
}
