#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIK"�j�j��L"NOR, ({ "spdier leg", "leg" }));
    set_weight(2000);
    setup_weapon(1, 5, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 650);
        set("long", "�@�ڭ�٤U�Ӫ��j��L�A���O�N�_�Ӥ���A���]��w�������A���ӥi�H���ӥ��H�C\n" );
    }

    setup();
}

