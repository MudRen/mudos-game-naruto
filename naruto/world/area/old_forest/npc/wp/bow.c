#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIW"�}"NOR, ({ "bow" }));
    set_weight(5000);
    setup_weapon(15, 15, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 1515);
        set("long", "�@��ܴ��q���}�C\n" );
    }
    setup();
}
