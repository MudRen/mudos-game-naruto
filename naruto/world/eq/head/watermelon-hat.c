#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIK"��ʥ�"NOR, ({ "watermelon hat", "hat" }) );

    set_weight(3300);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 3700);
        set("long", "�@����ʥ֡A��¦⪺���ӷ��v�ΡA���Y�٦��ۧ��l�A���A�J��j���]�j�����C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 6,
            "dex": 1,
        ]));
    }

    setup();
}

