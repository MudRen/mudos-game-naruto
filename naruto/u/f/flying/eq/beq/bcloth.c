#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(BBLU+HIC"B�Ũ�ԪA"NOR, ({ "Blevel cloth", "cloth" }) );

    set_weight(1200);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 8000);
        set("long", "B��NPC�M�Ϊ���A�A�����������m��O�C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
      "armor": 16,
         ]));
    }
    setup();
}

