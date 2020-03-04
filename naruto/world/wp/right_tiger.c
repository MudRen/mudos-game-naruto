#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIW"�ժ�"NOR, ({ "white tiger blade", "blade" }));
    set_weight(7000);
    setup_weapon(120, 140, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 206030);
        set("long", "�y���C�s�A�k�ժ�z���ժ�M�C\n" );
    }

    set("apply_weapon/righthand", 
        ([ "con" : 3,
           "exact" : 5,
           "intimidate" : 5,
    ]) );

    setup();
}
