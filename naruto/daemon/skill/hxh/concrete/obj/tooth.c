#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�i�}��֤j�f�A�ξU�Q��$w��$n��$l�r�h",
    "$N�o�X�y�U���i���n�A���M��ʨ��l���$n�����i�f�K�r",
    "$N���ڤ@�}��ʡA���l�r�M�u�V$n�S�X$w�ǳƮ����y��",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("�r��", ({ "fish tooth", "tooth" }));
    set_weight(8000);
    setup_weapon(40, 55, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "lefthand" }) );
        set("unit", "��");
        set("value", 47094);
        set("have_mag", 1);
        set("long", "�۷�U�Q���r���C\n" );
    }
    setup();
}