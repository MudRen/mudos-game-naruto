#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIC"蠍王"HIW"[很威風]"HIC"劍"NOR, ({ "scorpion sword","sword" }));
    set_weight(3000);
    setup_weapon(80, 99, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "lefthand", "twohanded" }) );
        set("unit", "把");
        set("value", 102678);
        set("long", "蠍王所持的武器，只要拿起這把刀的人，就會讓旁人覺得你很威風。\n" );
    }
    set("apply_weapon/lefthand", 
        ([ "con" : 2,            // 屬性：力量
           "str" : 2,
           "attack" : 13,
           "intimidate" : 10,
        ]) );
    setup();
}

