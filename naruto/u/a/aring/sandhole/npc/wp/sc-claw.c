#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIW+BLK"�Ȥ�"NOR, ({ "scorpin claw","claw" }));
    set_weight(4000);
    setup_weapon(10, 15, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 2424);
        set("long", "�a�U�F�޸��Ȥl�ҨϥΪ��Z���C\n" );
    }

    setup();
}

