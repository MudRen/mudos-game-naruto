#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("�K�y����", ({ "iron ball enchain", "enchain" }));
    set_weight(50000);
    setup_weapon(40, 120, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 40780);
        set("long", "�I�����K�y�A�e�ݩԵۤ@������C\n" );
    }
    // ���[��O
    set("apply_weapon/twohanded", 
        ([ "str" : 1 ]) );
    setup();
}
