#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"�Դ������C"NOR, ({ "raphael's sword", "sword" }));
    set_weight(1);
    setup_weapon(160, 180, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 1);
        set("long", "���ѯ��̬��d�R���@��ѨϩҨϥΪ��C�C\n" );
    }
    
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "str": 7,            // �W�[STR
           "exact" : 18,         // �R����O
           "mp": 200,            // �W�[MP
    ]) );

    setup();
}
