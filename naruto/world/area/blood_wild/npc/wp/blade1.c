#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIY"�}�H�b"NOR, ({ "broken blade", "blade" }));
    set_weight(15000);
    setup_weapon(60, 80, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 48270);
        set("long", @long
�M���Ψӥ��H�O�H���Y���M�l�C
long
);
    }
    
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "dex": 2,
           "str": 2,
           "attack": 10, 
           "intimidate": 6, 
           "exact": 4
        ]) );

    setup();
}
