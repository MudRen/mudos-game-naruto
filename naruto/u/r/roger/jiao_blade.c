#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"�B��"NOR, ({ "jiao ji blade", "blade" }));
    set_weight(15000);
    setup_weapon(160, 180, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 636470);
        set("long", "���������ԤM�C�H�����@�u�d�U���B�v���R�M�C\n" );
    }
    
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "str" : 7,            // �ݩʡG�O�q
           "exact" : 18,         // �R����O
           "mp": 200,            // �W�[MP
    ]) );

    setup();
}
