#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

void create()
{
    set_name(HIR"��"HIW"��"NOR"�_�l", ({ "Spanner", "spanner" }));
    set_weight(100);
    setup_weapon(30, 50, 150, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 10);
        set("long", "�����@�Ӥu�H�A���W���������_�l�]�ܥ��`�a�C\n" );
        set("wield_msg", "$N�q�h�������ǥX$n�A$n�e�Y���G�٦��I���C\n"); 
        set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n"); 
    }
    set("apply_weapon/righthand",
        ([ "dex" : 10,
           "attack" : 10,
    ]) );
    set("apply_weapon/lefthand", // �k��A��
        ([ "dex" : 10,
           "intimidate" : 10,
    ]) );
    setup();
}
