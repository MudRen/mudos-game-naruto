#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("��N�M", ({ "scalpel" }));
    set_weight(8000);
    setup_weapon(40, 55, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 47094);
        set("long", "�۷�p�����M�l�A���O�o�Q�����W�Q�C\n" );
    }

    setup();
}

