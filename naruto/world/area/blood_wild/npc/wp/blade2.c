#include <ansi.h>
#include <weapon.h>
inherit F_WEAPON;

void create()
{
    set_name(HIW"���l�b"NOR, ({ "blade of one pair of wings", "blade" }));
    set_weight(20000);
    setup_weapon(80, 100, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 89090);
        set("long", @long
�@��p���i�ͪ��G�b�M�A���k�G��O�M�b�A�Ӥ����O����A�A���n��
�H�i�H�ϥX�j�j�����ˤO�A���O��媺�ܡA�p�߶˨�ۤw�C
long
);
    }
    
    // ���[��O
    set("apply_weapon/righthand", 
        ([ "dex": 5,
           "attack": 15, 
           "intimidate": 10, 
           "exact": 5
        ]) );

    setup();
}

