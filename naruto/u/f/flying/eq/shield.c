#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIC"�֬�"NOR, ({ "shield" }));
    set_weight(6000);
    setup_weapon(0, 0, 100, 1);
    
    if( !clonep() ) {
        set("wear_as", ({ "lefthand" }) );
        set("unit", "��");
        set("value", 10000);
        set("long", "�@�ӥֻs�޵P�A�Ԥh�̥��ƫ~�C\n" );
    }
     // ���[��O
    set("apply_weapon/lefthand",
        ([ "armor": 5,
    ]) );

   
      setup();
}


