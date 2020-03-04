#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIG"�M�u�u"HIC"�ݩw"NOR, ({ "defend katana", "katana" }));
    set_weight(7000);
    setup_weapon(120, 140, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("no_box", 1);
        set("value", 206030);
        set("long", "���@��W�M�A�@�N�ݩw�G�N�ݩw�̬����W�A�b���K�Q�������C\n" );
    }
    set("apply_weapon/righthand", 
        ([ "int" : 3,
           "evade" : 5,
           "wittiness" : 5,
    ]) );
    setup();
}
