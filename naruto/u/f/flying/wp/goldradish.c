#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIY"黃金蘿蔔"NOR, ({ "gold radish", "radish" }));
    set_weight(2000);
    setup_weapon(150, 190, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "根");
        set("value", 404);
        set("long", "一根黃金製的蘿蔔，摸起來手感極佳，打人一定很浪費。\n"
     "上面有flying的神力加持，可以讓屬性暴漲。\n" );
    }

    // 附加能力
    set("apply_weapon/righthand", 
        ([ "str" : 180,            // 屬性：力量
           "con" : 180,
           "dex" : 180,
           "int" : 180,
           "wittiness" : 500,
           "intimidate" : 500,    // 攻擊技巧
    ]) );

    setup();
}
