#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("�j�۩�", ({ "whirls axe", "axe" }));
    set_weight(3000);
    setup_weapon(25, 30, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 3477);
        set("long", "�@��u��A�ˮ`�����T�w�C\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "intimidate" : 5,
    ]) );
    setup();
}
