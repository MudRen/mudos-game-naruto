#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�s�;ԤM", ({ "Newchar Blade", "blade" }));
    set_weight(2000);
    setup_weapon(4, 8, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 1);
        set("long", "�Z�j�v�e���s�⪺�Z���C\n" );
    }

    setup();
}
