#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"���`���"NOR, ({ "long axe", "axe" }));
    set_weight(7000);
    setup_weapon(45, 70, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 29557);
        set("long", "�๺�X���j���꩷�W�j���Y�@���A�X���O�D�C\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "attack" : 10,
    ]) );
    setup();
}
