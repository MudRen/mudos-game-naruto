#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name("���j", ({ "thron lance", "lance" }));
    set_weight(4000);
    setup_weapon(40, 50, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 5295);
        set("long", "�j�Y����쪺�y��A������h�Ӥ�V�C\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "intimidate" : 5,
    ]) );
    setup();
}
