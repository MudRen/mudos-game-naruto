#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

int i = 0;
int do_attack(object obj);

string *combat_wp = ({
    "$N����|�_�I���������j�ۡu��ĥ���v�M��@���F�V$n",
    "$N���_$w�ĦV�A�H��@�O�Ϧ��A��$w�������V$n$l",
    "$N��ۤ@�Ǫ����m�B�o�X�@���A�Q�ΤϽĤO�ֳt���V$n",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("���x�����", ({ "fire gun", "gun" }));
    set_weight(5000);
    setup_weapon(20, 20, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "�`");
        set("value", 2020);
        set("have_mag", 1);
        set("long", "���L��L�@�Իݭn���ˮ`�ɷ|�ϥΪ��j����������C\n"
                    "�����u��o�g�@���A�o�g�L�ᥲ���󴫤�÷�~��A���g���C\n"
                    "�ϥ�"HIY"[change gun]"NOR"�i�H�󴫤�÷(�ݭn����÷�~���)\n"
                    "�ϥ�"HIY"[gun attack on (�ؼ�)]"NOR"�g���ĤH�C\n");
    }
    set("wield_msg", "$N�N�I����$n���b�ӻH�W�C\n");
    setup();
}

void init()
{
    add_action("do_firegun", "gun");
    add_action("do_change", "change");
}

int do_change(string arg)
{
    object cord;

    if( this_player()->is_busy() )
        return notify_fail("�A���b���L�A�S�ɶ�����÷�C\n");

    if( !objectp(cord = present("_CORD_", this_player())) )
        return notify_fail("��÷���S���Q�������÷�C\n");

    if( arg == "gun" ) {
        if( i >= 1) {
            i = 0;
            message_vision(CYN"$N���X��÷��i������ݡC\n"NOR, this_player());
            write("��÷�w�g��n�F�C\n");
            cord->add_amount(-1);
            if( cord->query_amount() <= 0 ) destruct(cord);
            return 1;
        } else {
            write("��÷�٦b���A�n������H�C\n");
            return 1;
        }
        if( this_player()->is_fighting() ) {
            write("�A�b�԰����󴫤�÷�A�@�ɶ��L�k��ʡI");
            this_player()->start_busy(3);
        } else {
            this_player()->start_busy(1);
        }
    }
    return 0;
}

int do_firegun(string arg)
{
    string func,target;
    object ob;

    if( this_player()->is_busy() )
        return notify_fail("�A���b���L���A�S�ŨϥΡC\n");

    if( !this_object()->query("equipped") )
        return notify_fail("�A�S���������ΡC\n");

    if( !this_player()->is_fighting() )
        return notify_fail("�S���԰��é�����ܦM�I���C\n");

    if( !arg || sscanf(arg, "%s on %s", func, target)!=2 )
        return notify_fail("�ϥΫ��O�� gun attack on <�ؼ�>\n");

    if( !objectp(ob = present(target, environment(this_player()))) )
        return notify_fail("�䤣��ؼй�H�C\n");

    if( !ob || !ob->is_character() || ob->is_corpse() || ob == this_player() )
        return notify_fail("��I�L���ݭn�Ψ�����C\n"NOR);

    if( func == "attack" ) {
        do_attack(ob);
    }
    return 1;
}

int do_attack(object ob)
{
    string msg;
    object me;
    int damage, exact, evade;

    me = this_player();
    exact = me->query_level();
    evade = ob->query_level();

    if( i > 0 ) {
        message_vision("$N�k�Q�ϥΤ����A���O�ڥ��S�ˤ�÷�C\n", me);
        return 1;
    }
    me->add_temp("apply/attack", 300);
    damage = COMBAT_D->isDamage(me, ob, this_object());
    me->add_temp("apply/attack", -300);

    if( damage < 100 ) damage = random(100);

    message_vision("\n$N�Τ������$n�A�F���@�n�o�g�X�h�A$N��ӤH�^�F�@���C\n", me, ob);
    if( !COMBAT_D->SkillHit(me, ob, exact, evade) ) {
        message_vision("���G���������F�a���A�a�W�@���J�¡C\n\n", me, ob);
    } else {
        ob->damage_stat("hp", damage, me);
        message_vision( sprintf("$n$n�u�S�v�a�@�n�A���u�b$n�����W���}�A�����Y�����ˮ`(%d) %s\n\n", damage, COMBAT_D->report_status(ob) ), me, ob);
    }
    i++;
    me->start_busy(4);
    return 1;
}
