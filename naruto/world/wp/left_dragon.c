#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIG"�C�s"NOR, ({ "green dragon sword", "sword" }));
    set_weight(5000);
    setup_weapon(100, 120, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "��");
        set("value", 176010);
        set("long", "�y���C�s�A�k�ժ�z���C�s�C�C\n" );
    }

    set("apply_weapon/lefthand", 
        ([ "dex" : 3,
           "evade" : 5,
           "wittiness" : 5,
    ]) );

    setup();
}
