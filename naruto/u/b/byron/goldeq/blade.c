#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;
void create()
{
    set_name(HIY"�����j�M"NOR, ({ "gold blade", "blade" }));
    set_weight(5000);
    setup_weapon(180, 200, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "��");
        set("value", 176010);
        set("long", "�ª����y���j�M�C\n" );
    }
    set("apply_weapon/lefthand", 
        ([ "str" : 10,
           "con" : 10,
           "dex" : 10,
           "int" : 10,
           "hp"  : 1000,                      
    ]) );
    setup();
}

