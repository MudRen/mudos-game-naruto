#include <ansi.h>
#include <weapon.h>

inherit F_WEAPON;

string *combat_wp = ({
    "$N�N$w���V$n�A$n�u�Pı��l�@�}�D�N�A�n���Q�U�Q���H�𵹹��L",
    "$N�s���X�ƼC�A�u��$w�Ƭ��H��A�b�a�W��X�@�D�B���ĦV$n",
    "$n���M�Pı�H���방�A$w�U�Q���H��Ƭ����b������V$n��$l",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("�Q��"HIC"���B�C"NOR, ({ "wei ice sword", "sword" }));
    set_weight(3000);
    setup_weapon(80, 100, 100, 1);

    if( !clonep() ) {
        set("wield_as", ({ "righthand" }) );
        set("unit", "��");
        set("value", 50000);
        set("no_box", 1);
        set("no_auc", 1);
        set("have_mag", 1);
        set("long", "�Q��@�کҨϥΪ��L���A�C���p���B�A���o�X�H�N���𮧡C�]�����~\n"
                    "�Ϯg����G�A�ϱo�ײ��Ҩ����C�����ڤW�٨Ӫ����A�ɭP�{�׮ɸg\n"
                    "�`�P�_���~�Ө��즹�C���ˮ`�C\n" );
    }
    set("apply_weapon/righthand", 
        ([ "dex" : 2,            // �ӱ�
           "intimidate" : 20,    // �����ޥ�
    ]) );
    setup();
}
void init()
{
    add_action("do_perform", "perform");
}
int do_perform(string arg)
{
    int damage;
    object enemy, me;

    me = this_player();
    enemy = this_player()->query_opponent();

    if( arg == this_object()->query("id")+".ice" ) {

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
        me->damage_stat("mp", 20, me);
        message_vision("\n$N�w�w���|�_�u"+query("name")+"�v�H�A���Z���L���覡��V$n�I\n", me, enemy);

        if( userp(me) ) damage = COMBAT_D->isDamage(me, enemy, this_object())/2;
        else damage = COMBAT_D->isDamage(me, enemy, this_object());

        if( damage < 50 ) damage = random(20) + 30;

        // �ˮ`�ާl��
        damage = COMBAT_D->receive_damage(enemy, me, damage);

        enemy->receive_damage(damage, me);
        message_vision( sprintf("$n�H���໴�P�׹L�����A�o�b��Y���Q�M�W�夤(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);

        me->start_busy(1);
        return 1;
    }
}