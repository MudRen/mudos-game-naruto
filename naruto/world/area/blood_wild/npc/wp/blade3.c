#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIM"��Ĥb"NOR, ({ "blade of the phoenix", "blade" }));
    set_weight(15000);
    setup_weapon(90, 100, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 263795);
        set("long", @long
�@�⦳�p��ĥX�D���u�M�C
long
);
    }
    
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "dex": 8,
           "attack": 20, 
           "intimidate": 20, 
        ]) );

    setup();
}
