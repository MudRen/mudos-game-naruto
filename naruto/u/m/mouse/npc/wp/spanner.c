#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIR"螺"HIW"絲"NOR"起子", ({ "Spanner", "spanner" }));
    set_weight(100);
    setup_weapon(30, 50, 150, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 10);
        set("long", "身為一個工人，身上有把螺絲起子也很正常吧。\n" );
        set("wield_msg", "$N從懷中偷偷掏出$n，$n前頭似乎還有點血跡。\n"); 
        set("unwield_msg", "$N將手中的$n藏入懷中。\n"); 
    }
    set("apply_weapon/righthand",
        ([ "dex" : 10,
           "attack" : 10,
    ]) );
    set("apply_weapon/lefthand", // 右手適用
        ([ "dex" : 10,
           "intimidate" : 10,
    ]) );
    setup();
}
