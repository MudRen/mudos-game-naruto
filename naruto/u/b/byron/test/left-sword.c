#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;
void create()
{
    set_name(HIC"七星倒峰劍"NOR,({"sevenstar barb sword","sword","sevenstar"}));;
    set_weight(15000);
    setup_weapon(170, 200, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "把");
        set("value", 800000);
        set("long",HIB"這把劍輕巧柔軟，可是在你抽出這把劍時，卻發現這把劍的嗜血和可怕\n"
                      "之處，在劍鋒上隱隱有些許\的血滴流露出來。傳說這把劍是古代時異人\n"
                      "用血和玄鐵鑄成的，所以這一把劍是無比的鋒利和無比的血腥。\n"NOR);
}
    // 附加能力
    set("apply_weapon/righthand", 
        ([ "str"   : 10,            
           "con"   : 10,
           "exact" : 20,         
           "mp"    : 500,        
    ]) );
    setup();
}

