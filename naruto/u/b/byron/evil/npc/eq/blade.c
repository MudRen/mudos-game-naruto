#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;
void create()
{
    set_name(HIR"閻魔荒神斬"NOR,({"yan mo blade","blade"}));;
    set_weight(15000);
    setup_weapon(170, 200, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 800000);
        set("long",RED"隸屬鬼族的退休狼主逃山補劍缺所打造的魔刀是魔君旱魃所專屬的佩刀\n"
                      "本來是東方鼎立所持有的長日狂陽鬼知先座什麼時候把它拿回來獻給魔君。\n"
                      "在刀柄底部有顆妖魂珠可能就是這把刀的能量來源吧。\n"NOR);
}
    set("apply_weapon/twohanded", 
        ([ "str"   : 3,            
           "con"   : 3,
           "hp"    : 1000,        
    ]) );
    setup();
}

