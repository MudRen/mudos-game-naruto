#include <ansi.h>
#include <armor.h>
inherit F_NECK_EQ;

void create()
{
        set_name(HIY"����ɦ�]"NOR, ({ "kinkon rosary","rosary" }) );
        set_weight(1000);
        setup_neck_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 1000);
                set("long",
                        "�ǻ��O�����ꪺ�L���I�v�N�|�Q�E�����]�ٰ��A�N���]���F��W�禨�@��C
�C�|�Q�E�����ɦ�]�C\n");
                set("wear_as", "neck_eq");
                set("apply_armor/neck_eq", ([
                        "armor" :5,
                        "int":3,
                        "str":3,
                ]));
        }

        setup();
}

