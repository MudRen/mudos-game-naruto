#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIR"���C"NOR, ({ "thorn sword","sword" }));
    set_weight(4880);
    setup_weapon(77, 88, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "��");
        set("value", 42482);
        set("long", "�a�U�F�޸��Ȥl�ҨϥΪ��Z���C\n" );
    }
    set("apply_weapon/lefthand", 
        ([ "con" : 2,            // �ݩʡG�O�q
        ]) );
    setup();
}

