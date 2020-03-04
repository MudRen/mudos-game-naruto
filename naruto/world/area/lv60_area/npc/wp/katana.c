#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�k�ⴤ��$w�Կ�Ԫk�u���X�v���s���_����ճs�����$n��$l",
    "$N�|�_$w�\�X�ľW���աu��i�v�Q�������z�o�O��V$n",
    "$N���k���j�A���M�V�e�@�O�u��ŧ�v$w���V$n��$l",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("����"HIW"�Z�h�M"NOR, ({ "nagao katana", "katana" }));
    set_weight(3000);
    setup_weapon(77, 96, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 50000);
        set("no_box", 1);
        set("no_auc", 1);
        set("have_mag", 1);
        set("long", "�V��W�����@�A�W�Q���Z�h�M�A���W���V��Z�h�M�A�]�������Q�٬�\n"
                    "�u�V�ᤧ�s�v����������ӧ�W�������Z�h�M�A���H���F���㦹�M\n"
                    "���S��A���M���`�������[���A�N���p���������ڡC\n" );
    }
    set("apply_weapon/righthand", 
        ([ "con" : 3,             // ���
           "attack" : 10,         // ������O
           "wittiness" : 5,        // ���m�ޥ�
    ]) );
    setup();
}
void init()
{
    add_action("do_perform", "perform");
}
int do_perform(string arg)
{
    int damage, raiseDamage;
    object enemy, me;

    me = this_player();
    enemy = this_player()->query_opponent();

    if( arg == this_object()->query("id")+".hew" ) {

        if( me->is_busy() ) return notify_fail("�A�{�b�S���šC\n");
        if( !enemy ) return notify_fail("�S���ĤH�i�H�I�i�ޯ�C\n");
        if( !me->is_fighting(enemy) ) return notify_fail("�A�å��M���԰��C\n");
        if( !query("equipped") ) return notify_fail("�A�S�˳Ƴo�˪Z���C\n");
        if( me->query_stat("mp") < 35 ) return notify_fail("�A�S�]�O�ϥγo�ۡC\n");
        if( me->query_level() < 41 ) return notify_fail("�A�L�k�ϥγo�өۦ��C\n");

        // �ĤH�b���P��m
        if( environment(me)->is_area() ) {
            if( !area_environment(me, enemy) ) return notify_fail("�S���ĤH�i�H�I�i�ޯ�C\n");
        } else {
            if( environment(enemy) != environment(me) ) return notify_fail("�S���ĤH�i�H�I�i�ޯ�C\n");
        }
        me->damage_stat("mp", 35, me);
        message_vision("\n$N���M���o�X�s�u�몺��աA���t��M�u"HIW"�V���s�q"NOR"�E"HIG"�x��"NOR"�v��Ѱʦa���@���I\n", me, enemy);
        if( !COMBAT_D->isHit(me, enemy) ) {
            message_vision("�j�O���M��u�b�a�W�d�U�F����A�եծ��O�O��C\n\n", me, enemy);
            me->start_busy(4);
        } else {
            if( userp(me) ) raiseDamage = me->query_level()*5;
            else raiseDamage = 800;

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 200 ) damage = 80 + random(120);

            enemy->receive_damage(damage, me);
            message_vision( sprintf("$n�Ө�����o�ѤO�q�A�����Y�����СA�Q�F���Ѫ��A��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            me->start_busy(3);
        }
        return 1;
    }
}