#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIW"�ѨϾv��"NOR, ({ "Angel band" ,"band"}) );

    set_weight(500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 5000);
        set("long", "���ѨϤ��l���b�W�����Y���A���t���C�i��O�q�Ѱ�ҵo�����̪��F\n"
     "��i�ӼW�[�ӱ��A���ֻP�O�@���F���ۥѨӨ���c�]���O�q�I�J�C\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 8,
            "int": 1,
            "dex": 1,
        ]));
    }

    setup();
}

