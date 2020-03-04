#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIR"ī�G�Y��"NOR, ({ "Apple archer" ,"archer"}) );

    set_weight(500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 5000);
        set("long", "��ī�G�@�ˡB�a���ǩ_��m���U�l�A�ܤ[�H�e�A�@�ӧ޳N���W���g��\n"
     "�u�ΤF�@�b�N�b�������Z���~�g���o��ī�G�A���ϥΪ̪����m�״��@\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "dex": 3,
        ]));
    }

    setup();
}

