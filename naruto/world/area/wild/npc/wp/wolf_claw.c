#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(YEL"�T��"NOR, ({ "wolf's claw", "claw" }));
    set_weight(8000);
    setup_weapon(10, 15, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 2424);
        set("long", "�@���T�����A�ݰ_�ӫܦy�U�C\n" );
    }

    setup();
}
