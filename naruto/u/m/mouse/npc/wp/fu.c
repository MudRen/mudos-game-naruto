#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�o�Ʀ����|�_$w�ϥX�@�ۡu"HIY"��d�x"NOR"�v�ֳt�A�V$n��$l",
    "$N���M��_��ӡu"HIC"�ۭ���"NOR"�v�v���G��$n�r��",
    "$N�ΤO�N$w���a�W�@�{�u"HIR"�ѱY�a��"NOR"�v�n�ɦa�����X�@�D�����V$n",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name(HIY"��"NOR"��", ({ "dou fu", "fu" }));
    set_weight(1000);
    setup_weapon(50, 100, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "righthand", "twohanded" }) );
        set("unit", "��");
        set("value", 7272);
        set("have_mag", 1);
        set("long", "�����ҥΪ����Y�A�N���ۧN�ۧN�C\n" );
    }
    setup();
}
