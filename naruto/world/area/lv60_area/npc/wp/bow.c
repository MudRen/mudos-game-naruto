#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�V���D�X�T�B�A���ⶶ�է۰_�T��}�b��$w�@�f�g�V$n",
    "$N���⩹�a�W�ް_������խ��V�A�k��N�b�f��y����b�g��$n",
    "$N�e�����°��Ůg�X�@�b�A���}�b�o�H���i��ĳ�����צ^��g�V$n$l",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("��Q"HIM"���}"NOR, ({ "mouri bow", "bow" }));
    set_weight(3000);
    setup_weapon(10, 70, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 50000);
        set("no_box", 1);
        set("no_auc", 1);
        set("have_mag", 1);
        set("long", "��Q�a�ڥH���x����¦�A�o�i�X�@�M�S���@�Ԥ覡�A�b���Ԥ��̾A\n"
                    "�X�ϥΪ��Z���N�ݤ}�b�A���F�����a�����ԧ��L�����Q�A�b�}�b��\n"
                    "�]�p�W�]�U�F�@½�\�ҡC\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "intimidate" : 40,      // �����ޥ�
           "attack" : 5,           // ������O
    ]) );
    setup();
}
void init()
{
    add_action("do_perform", "perform");
}
int do_perform(string arg)
{
    int damage, raiseDamage, exact, evade;
    object enemy, me;

    me = this_player();
    enemy = this_player()->query_opponent();

    if( arg == this_object()->query("id")+".loose" ) {

        if( me->is_busy() ) return notify_fail("�A�{�b�S���šC\n");
        if( !enemy ) return notify_fail("�S���ĤH�i�H�I�i�ޯ�C\n");
        if( !me->is_fighting(enemy) ) return notify_fail("�A�å��M���԰��C\n");
        if( !query("equipped") ) return notify_fail("�A�S�˳Ƴo�˪Z���C\n");
        if( me->query_stat("mp") < 20 ) return notify_fail("�A�S�]�O�ϥγo�ۡC\n");
        if( me->query_level() < 41 ) return notify_fail("�A�L�k�ϥγo�өۦ��C\n");

        // �ĤH�b���P��m
        if( environment(me)->is_area() ) {
            if( !area_environment(me, enemy) ) return notify_fail("�S���ĤH�i�H�I�i�ޯ�C\n");
        } else {
            if( environment(enemy) != environment(me) ) return notify_fail("�S���ĤH�i�H�I�i�ޯ�C\n");
        }
        exact = COMBAT_D->intimidate(me, 1)*1.2;
        evade = COMBAT_D->wittiness(enemy, 1);

        me->damage_stat("mp", 20, me);
        message_vision("\n$N"+query("name")+"�@�f�@��A�ϥX��Q�a���ޡu"RED+BLINK"�H�O����"NOR"�v�s��b�V$n�g�h�I\n", me, enemy);
        if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
            message_vision("���O���ڦb�Ť��N�z�F�}�ӡA�S������v�T�C\n\n", me, enemy);
            me->start_busy(2);
        } else {
            if( userp(me) ) raiseDamage = me->query_level()*2;
            else raiseDamage = me->query_level()*5;

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(enemy, me, damage);
            enemy->receive_damage(damage, me);
            message_vision( sprintf("�u�P�v�a�@�n�A���ڮg���F$n�A��$n�s�z�F�@�n(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            if( random(200) > 50 ) {
                if( userp(me) ) raiseDamage = me->query_level()*3;
                else raiseDamage = me->query_level()*5 + me->query_ability("exact");

                me->add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(me, enemy, this_object());
                me->add_temp("apply/attack", -raiseDamage);

                if( damage < 150 ) damage = 100 + random(50);

                enemy->receive_damage(damage, me);
                message_vision( sprintf("���M���ڵo�ͤ@�}�z���A�ߨ謵�ˤF�Q�b�g����$n(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                if( random(200) > 150 ) {
                    damage = me->query_level() + random(me->query_level());
                    // �ˮ`�ާl��
                    damage = COMBAT_D->receive_damage(enemy, me, damage);
                    enemy->receive_damage(damage, me);
                    message_vision( sprintf("�S�Q����V���l�ǤS�Q��$n���W�y���ĤT���ˮ`(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                }
            } else {
                message_vision("$n��b�ޤF�U�ӥ��@�ǡC\n", me, enemy);
            }
            message_vision("\n", me, enemy);
        }
        return 1;
    }
}