#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIY"����"NOR, ({ "Tree staff", "staff" }));
    set_weight(7000);
    setup_weapon(40, 45, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 26884);
        set("long", "�����K�Ҧ������A�֦����쪺�k�O�C\n" );
    }
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "int" : 2,
           "continual hit" : 10,
    ]) );
    setup();
}
