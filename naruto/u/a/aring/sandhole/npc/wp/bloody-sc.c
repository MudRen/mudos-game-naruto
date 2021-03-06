#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(NOR+RED"染血蠍爪"NOR, ({ "bloody scorpion claw","claw" }));
    set_weight(4750);
    setup_weapon(50, 60, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "把");
        set("value", 61710);
        set("long", "地下沙穴裡蠍子所使用的武器。\n" );
    }
    set("apply_weapon/righthand", 
        ([ "str" : 2,            // 屬性：力量
           "attack" : 3,         // 攻擊力量
           "intimidate" : 7,
        ]) );
    setup();
}

