#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
        set_name(HIW"�ժ��"NOR, ({ "tiger wrist","wrist" }) );
        set_weight(10000);
        setup_wrist_eq();

        if( !clonep() ) {
                set("unit", "��۷�I����");
        set("value", 600);
                set("long", "�۶ǬO�|�j�t�~�i�ժ�j�����һs�������l�A���۳̨Ψ��ƻP��պc�y�A���������ĤH���⤣�ΡC\n");
                set("wear_as", "wrist_eq");
                set("apply_armor/wrist_eq", ([
                        "armor": 10,
                        "attack": 10,
                ]));
        }

        setup();
}
