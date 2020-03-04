#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�����j�A�ϥΥ椬�g�����ޥ��A�s���_���o�g�l�u����$n$l",
    "$N�G�N��ν����O���j����÷�o�g$w�u�A���Ϲ�$n��$l�y������",
    "$N���챻�������i���u�A�P�ɮ��X���ðƺj�g��$n�}�������",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

int i=1;

void create()
{
    set_name("�ؤl�q"REV"�K��"NOR, ({ "germ gun", "gun" }));
    set_weight(3000);
    setup_weapon(25, 80, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 50000);
        set("no_box", 1);
        set("no_auc", 1);
        set("have_mag", 1);
        set("long", "�饻�K�����l���A�]�O�g�ѧ�}�᪺���n�Z�����@�A�쥻�]���˳Ƥ�\n"
                    "÷�Өϱo�˼u�t�פ����֡A�L�k�F��ϥΪ����G�A���O�g�Ѻؤl�q�a\n"
                    "��}��A�{�b�w�g�l�ͥX�\�h�K���Ԫk�F�C\n" );
    }
    set("apply_weapon/righthand", 
        ([ "int" : 5,             // ���z
           "defend" : 20,         // ���m��O
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
        evade = COMBAT_D->intimidate(enemy, 1);

        me->damage_stat("mp", 20, me);
        message_vision("\n$N�N���޶�i"+query("name")+"�\�X�g�����A�y"HIK"�T�q�t�g"NOR"�z��$N��"+chinese_number(i)+"�������I\n", me, enemy);
        if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
            message_vision("$N�˪������ǽT�A�̲��٬O�S������$n�C\n\n", me, enemy);
            i += 1;
        } else {
            if( userp(me) ) raiseDamage = me->query_level()*2;
            else raiseDamage = me->query_level()*5;

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage > 600 ) damage = 600;
            if( damage < 150 ) damage = 150;

            enemy->receive_damage(damage, me);
            message_vision( sprintf("$n�Q�K���������A�d�U�@�Ӥ����e�ת��p�u�նˮ`(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            i += 1;
        } if( i >= 4 ) {
            message_vision(CYN"$N"CYN"�s��g���F�T���A�����y�L�𮧤~���~��g���C\n\n"NOR, me, enemy);
            i = 1;
            me->start_busy(3);
        }
        return 1;
    }
}