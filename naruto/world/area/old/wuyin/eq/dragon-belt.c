#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
        set_name(HIB"�C�s�n�a"NOR, ({ "dragon belt","belt" }) );
        set_weight(3000);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "��");
        set("value", 600);
                set("long", "�۶ǬO�|�j�t�~�i�C�s�j���֩һs�������ݥn�a�A�ƷȷȪ��ݨӭn�髬�A�X���H�~ô���_�ӡC\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "str": 3,
                ]));
        }

        setup();
}

