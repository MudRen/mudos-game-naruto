#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

void create()
{
    set_name("�ֲy", ({ "ball" }));
    set_weight(800);
    setup_weapon(10, 20, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 1815);
        set("long", "�@�������Ϊ�t�Ϊ��ֲy�C\n" );
    }
    // ���[��O
    set("apply_weapon/righthand",
        ([ "attack" : 3,         // �����O�q
    ]) );
    setup();
}
