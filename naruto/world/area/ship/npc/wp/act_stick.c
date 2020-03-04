#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�ϥ�$w�j�X�@�ӹq��w�A���O$n�uı�o�@�}�¡A$N�u�n���R$w����",
    "$N��$w���M�Q�X�@������A�O$N�s�˦a�n�n�Y������V$n��$l",
    "$N�Q�n�o��$w���S�ޡA�o�ܦ����A���Q���S�ޡA��$n��ӯ�½�b�a�W",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("��t�ΤѭԴ�", ({ "act sky stick", "stick", "_WEATHER_" }));
    set_weight(1000);
    setup_weapon(5, 15, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 1010);
        set("have_mag", 1);
        set("long", "�F�H�������b���~�ѭԴΡA�ܦh�\�ೣ�u�O��t�γ~�C\n" );
    }
    setup();
}
