#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("殺豬刀", ({ "butcher's blade" ,"blade" }));
    set_weight(1000);
    setup_weapon(10, 20, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 5815);
        set("long", "一把普通拿來剁豬肉的刀，傳說有一位密探利用特異功能來操控它打敗金槍客。\n" );
    }

    set("apply_weapon/twohanded", 
        ([ "str" : 3,            // 屬性：力量
           "attack" : 2,         // 攻擊力量
           "armor" : 2,        // 防禦力量
    ]) );

    setup();
}

