#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�r�a�@�n�A��ʸ�U�����ǡA�ֳt�ĦV$n���e�H$w�����$n�C��",
    "$N����}�F$n�������A�����F���a���a���ǡA�q�ǰ���$n��$l",
    "$N����ǥ��h��ƤءA�H�۰��Ǥ@�n����A�}�l�ֳt�ĦV$n�i�����",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

int i=1;

void create()
{
    set_name("�Z��"HIR"���W�j"NOR, ({ "takeda lance", "lance" }));
    set_weight(3000);
    setup_weapon(70, 100, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "righthand", "twohanded" }) );
        set("unit", "�`");
        set("value", 50000);
        set("no_box", 1);
        set("no_auc", 1);
        set("have_mag", 1);
        set("long", "�Z�Юa�کҨϥΪ��Z���A�˦����I�����u�A�q�`�ϥΩ��M���ɡA�]��\n"
                    "����O�H�«׫ܰ����K���һs���A�ҥH�H�B�L�Ҧ��ϥγo��Z���|�P\n"
                    "ı���ǤO���q�ߡC\n" );
    }
    set("apply_weapon/twohanded", 
        ([ "con" : 2,             // ���
           "hp" : 100,            // �ͩR
           "ap" : 50              // �믫
    ]) );
    set("apply_weapon/righthand", 
        ([ "hp" : 200,            // �ͩR
           "ap" : 100             // �믫
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

    if( arg == this_object()->query("id")+".lunge" ) {

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
        exact = COMBAT_D->wittiness(me, 1)*1.3;
        evade = COMBAT_D->intimidate(enemy, 1);

        me->damage_stat("mp", 20, me);
        message_vision("\n$N���R��"+query("name")+"�M�b�­����԰��W�u"GRN"�U���b��"NOR"�E"YEL"�Y��"NOR"�v�Ϻɥ��O����$n�I\n", me, enemy);
        if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
            message_vision("$N�ĵ۽ĵۤ@���p�ߩ~�M�ĹL�F�Y�A��~����է��������F�C\n\n", me, enemy);
            me->start_busy(3);
        } else {
            if( userp(me) ) raiseDamage = me->query_level()*3 + me->query_skill("combat");
            else { 
                if( enemy->query_stat_maximum("hp") > 10000 ) raiseDamage = 500;
                if( enemy->query_stat_maximum("hp") > 1000 ) raiseDamage = enemy->query_stat_current("hp")/10;
                else raiseDamage = 300;
            }
            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 150 ) damage = 100 + random(50);

            enemy->receive_damage(damage, me);
            message_vision( sprintf("$n�u�S���v�@�n�e�T�A�Q�԰������F�X�h�A����@�Ǥ���(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            me->start_busy(1);
            enemy->start_busy(2);
        }
        return 1;
    }
}