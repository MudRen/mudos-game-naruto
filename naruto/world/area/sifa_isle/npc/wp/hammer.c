#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(YEL"���H�ڤ��j�l"NOR, ({ "atlantean hammer", "hammer" }));
    set_weight(150000);
    setup_weapon(160, 200, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 540180);
        set("long", "���H�کҨϥΪ��W���Ժl�A���`�H�ڥ������|�_�C\n" );
    }
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "intimidate" : 10,            // �ݩʡG�O�q
    ]) );
    setup();
}
