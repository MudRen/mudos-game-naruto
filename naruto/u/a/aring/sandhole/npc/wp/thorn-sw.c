#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIR"刺刺劍"NOR, ({ "thorn sword","sword" }));
    set_weight(4880);
    setup_weapon(77, 88, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "把");
        set("value", 42482);
        set("long", "地下沙穴裡蠍子所使用的武器。\n" );
    }
    set("apply_weapon/lefthand", 
        ([ "con" : 2,            // 屬性：力量
        ]) );
    setup();
}

