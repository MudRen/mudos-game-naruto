#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name("���ޤM", ({ "butcher's blade" ,"blade" }));
    set_weight(1000);
    setup_weapon(10, 20, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 5815);
        set("long", "�@�ⴶ�q���Ө�ަת��M�A�ǻ����@��K���Q�ίS���\��Ӿޱ������Ѫ��j�ȡC\n" );
    }

    set("apply_weapon/twohanded", 
        ([ "str" : 3,            // �ݩʡG�O�q
           "attack" : 2,         // �����O�q
           "armor" : 2,        // ���m�O�q
    ]) );

    setup();
}

