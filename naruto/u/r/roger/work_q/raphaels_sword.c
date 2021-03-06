#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"拉斐爾之劍"NOR, ({ "raphael's sword", "sword" }));
    set_weight(1);
    setup_weapon(160, 180, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "把");
        set("value", 1);
        set("long", "為天神最為寵愛的一位天使所使用的劍。\n" );
    }
    
    // 附加能力
    set("apply_weapon/righthand", 
        ([ "str": 7,            // 增加STR
           "exact" : 18,         // 命中能力
           "mp": 200,            // 增加MP
    ]) );

    setup();
}
