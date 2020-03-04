#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�x���I�S�ӹL�A���a�۲r�P�����V����$n��$l",
    "$N�B�Τ�ê��ޥ���$w�I���o�X����A�uť���u���v�a�@�n�A���D«�V$n$l",
    "$N���$w�i���o�X�����P�ɡA$N�����������V$n��$l",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("�d��"HIR"������"NOR, ({ "wu fire finger", "finger" }));
    set_weight(3000);
    setup_weapon(25, 30, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 50000);
        set("no_box", 1);
        set("no_auc", 1);
        set("have_mag", 1);
        set("long", "�d��@�کҨϥΪ��L���A�������e�ݬO����i���X���V�����@�i����\n"
                    "���A�s�y�覡�u���d��@�ڪ��H�~���D�A�O���Ǫ��K�N�C�ϥΦ��٫K\n"
                    "��b�����ɩ�X���V�N�˹��C\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "exact" : 60,         // �R����O
    ]) );
    setup();
}
void init()
{
    add_action("do_perform", "perform");
}
int do_perform(string arg)
{
    mapping cnd = ([]);
    object enemy, me;
    int exact, evade;

    me = this_player();
    enemy = this_player()->query_opponent();

    if( arg == this_object()->query("id")+".fire" ) {

        if( me->is_busy() ) return notify_fail("�A�{�b�S���šC\n");
        if( !enemy ) return notify_fail("�S���ĤH�i�H�I�i�ޯ�C\n");
        if( !me->is_fighting(enemy) ) return notify_fail("�A�å��M���԰��C\n");
        if( me->query_stat("mp") < 20 ) return notify_fail("�A�S�]�O�ϥγo�ۡC\n");
        if( enemy->query_condition("firedamage", 1) != 0) return notify_fail("���w�g�ۤ��A���οN�F�C\n");
        if( !query("equipped") ) return notify_fail("�A�S�˳Ƴo�˪Z���C\n");
        if( me->query_level() < 41 ) return notify_fail("�A�L�k�ϥγo�өۦ��C\n");

        // �ĤH�b���P��m
        if( environment(me)->is_area() ) {
            if( !area_environment(me, enemy) ) return notify_fail("�S���ĤH�i�H�I�i�ޯ�C\n");
        } else {
            if( environment(enemy) != environment(me) ) return notify_fail("�S���ĤH�i�H�I�i�ޯ�C\n");
        }
        exact = COMBAT_D->intimidate(me, 1)*1.5;
        evade = COMBAT_D->wittiness(enemy, 1);

        me->damage_stat("mp", 20, me);
        message_vision("\n$N�j�ܤ@�n�u�d��w"HIR"������"NOR"�v�u��$N����Q�X���V��V$n�I\n", me, enemy);
        if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
            message_vision("���G�����Q$n�����}�F�A�S���F��ĪG�C\n\n", me, enemy);
            me->start_busy(2);
        } else {
            message_vision("���G���������F$n�����l�A���V�ֳt�a�U�N�F�_�ӡI\n\n", me, enemy);
            me->start_busy(1);

            cnd["name"] = HIR+"�ۤ����A"+NOR;
            cnd["duration"] = 5;
            cnd["from"] = me;

            enemy->set_condition("firedamage", cnd);
        }
        return 1;
    }
}