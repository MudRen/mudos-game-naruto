#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIC"�p������"NOR, ({ "Thunder-god shield", "shield" }));
    set_weight(6000);
    setup_weapon(180, 200, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "lefthand" }) );
        set("unit", "��");
        set("value", 1105360);
        set("long", "�ǻ����ĤG�N���v�ҥιL���M �p�����C�C\n" );
    }
     // ���[��O
               set("apply_weapon/lefthand",
        ([ "armor" : 10,            // �ݩʡG�O�q
 ]) );
    
      setup();
}


