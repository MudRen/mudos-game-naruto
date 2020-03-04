#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIW"����"NOR, ({ "snow katana", "katana" }));
    set_weight(7000);
    setup_weapon(150, 160, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("no_box", 1);
        set("value", -1);
        set("long", "ù�������e���������W�M�A���¤M���B�äb�p�B�r�C\n" );
    }
    set("apply_weapon/righthand", 
        ([ "con": 10,
           "intimidate": 30,
           "heavy hit": 10,
    ]) );
    setup();
}
