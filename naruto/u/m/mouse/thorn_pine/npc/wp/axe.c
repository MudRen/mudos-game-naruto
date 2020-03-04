#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("斧頭", ({ "axe" }));
    set_weight(5000);
    setup_weapon(15, 30, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "把");
        set("value", 2922);
        set("long", "平常用來砍柴的尋常斧頭。\n" );
    }
    // 附加能力
    set("apply_weapon/twohanded", 
        ([ "str" : 1,
    ]) );
    setup();
}
