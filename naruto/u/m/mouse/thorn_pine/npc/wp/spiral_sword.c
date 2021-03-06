#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"螺旋劍"NOR, ({ "spiral sword", "sword" }));
    set_weight(2500);
    setup_weapon(30, 45, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "lefthand", "righthand" }) );
        set("unit", "把");
        set("value", 39224);
        set("long", "圓柱體劍身，刻有螺絲狀凹槽，刺入身體會造成巨大傷害。\n" );
    }
    set("apply_weapon/righthand", 
        ([ "attack" : 10,
           "exact" : 5,
           "intimidate" : 10,
    ]) );
    set("apply_weapon/lefthand", 
        ([ "exact" : 5,
    ]) );
    setup();
}
