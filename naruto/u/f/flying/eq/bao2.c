#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name("���_�_���]", ({ "niao bao",}) );
    set_weight(800);
    setup_pants();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 100);
        set("long", "�@������Ϊ����]�A�ٱa�F�I�˨��C\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "hp": 9999,
            "mp": 9999,
            "ap": 9999,
            ]));
    }
  setup();
}

