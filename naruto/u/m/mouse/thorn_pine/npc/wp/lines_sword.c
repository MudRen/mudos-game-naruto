#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("�课�C", ({ "lines sword", "sword" }));
    set_weight(2000);
    setup_weapon(15, 15, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 9715);
        set("long", "�W���観�������C�A��@��Z����o�C\n" );
    }
    set("apply_weapon/righthand", 
        ([ "con" : 1,
           "armor" : 5,
    ]) );
    setup();
}
