#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIK"����C"NOR, ({ "gao yuan sword", "sword" }));
    set_weight(15000);
    setup_weapon(75, 90, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 167364);
        set("long", "�@��ӲӪ������C�C\n" );
    }
    
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "str" : 2,            // �ݩʡG�O�q
           "con" : 2,
           "wittiness" : 10,
           "intimidate" : 10,    // �����ޥ�
    ]) );

    setup();
}
