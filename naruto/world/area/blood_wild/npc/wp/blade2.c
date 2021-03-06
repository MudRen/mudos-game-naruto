#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"雙翼刃"NOR, ({ "blade of one pair of wings", "blade" }));
    set_weight(20000);
    setup_weapon(80, 100, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "根");
        set("value", 89090);
        set("long", @long
一把如鳥展翅的二刃刀，左右二邊是刀刃，而中間是握把，耍的好的
人可以使出強大的殺傷力，但是手拙的話，小心傷到自已。
long
);
    }
    
    // 附加能力
    set("apply_weapon/righthand", 
        ([ "dex": 5,
           "attack": 15, 
           "intimidate": 10, 
           "exact": 5
        ]) );

    setup();
}

