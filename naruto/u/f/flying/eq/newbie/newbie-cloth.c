#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("�s�⥬��", ({ "newbie cloth", "cloth" }) );

    set_weight(500);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�@��M�`���s�⥬��C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
      "armor": 1,
      "wittiness": 1, 
       ]));
    }
    setup();
}

