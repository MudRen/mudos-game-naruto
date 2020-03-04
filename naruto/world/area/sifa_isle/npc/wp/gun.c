#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;

int i = 0;
int do_attack(object obj);

string *combat_wp = ({
    "$N�@���ֳt�b�]�˶�l�u�A�H��@���ਭ�@�j�g�V$n",
    "$N�|�_$w�I�i�u�����k�v���V$n$l",
    "$N�o�{�Ӥ��θ˶�l�u�A�H��N�|�_$w�{�V$n$l",
});

string *atk_msg = ({
        "����", "�k��", "���u", "�k�u", "���L", "�k�L", "����", "�k��",
        "����", "�k��", "����", "�k��", "���}", "�k�}", "�{�l", "�I��",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name("���x��K��", ({ "iron gun", "gun" }));
    set_weight(1000);
    setup_weapon(8, 8, 100, 1);
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 808);
        set("have_mag", 1);
        set("long", "���x�h�L���|�t�a����Z���A����o�g�X�K����u�C\n"
                    "�ϥ�"HIY"[check gun]"NOR"�i�H�d�ݳѾl�u��\n"
                    "�ϥ�"HIY"[change gun]"NOR"�i�H�󴫼u��(�ݭn���u���~���)\n"
                    "�ϥ�"HIY"[gun attack on (�ؼ�)]"NOR"�g���ĤH�C\n");
    }
    set("wield_msg", "$N�N$n�W���᮳�b��W�C\n");
    setup();
}

void init()
{
    add_action("do_firegun", "gun");
    add_action("do_change", "change");
    add_action("do_check", "check");
}

int do_change(string arg)
{
    object clip;

    if( this_player()->is_busy() )
        return notify_fail("�A���b���L�A�S�Ŵ��u�C\n");

    // �ˬd���S���a�u��
    if( !objectp(clip = present("_CLIP_", this_player())) )
        return notify_fail("�A�����W�S���u���A�L�k���u�C\n");

    if( arg == "gun" ) {
        message_vision(CYN"$N�}�l�󴫼u���C\n"NOR, this_player());
        if( i >= 10) {
            i = 0;
            write("�u���󴫧����C\n");
            destruct(clip);
        } else {
            write("�u�ƤQ���R���A���Χ󴫡C\n");
        }
        if( this_player()->is_fighting() ) {
            write("�A�b�԰����󴫼u���A�@�ɶ��L�k��ʡI");
            this_player()->start_busy(3);
        } else {
            this_player()->start_busy(1);
        }
        return 1;
    }
    return 0;
}

int do_check(string arg)
{
    int a = 20 - i;

    if( arg == "gun" ) {
        message_vision(CYN"$N�J���ˬd�۳Ѿl�u�ơC\n"NOR, this_player());
        write("�l�u�Ѿl("HIY+a+NOR")�o�C\n");
        return 1;
    }
}

int do_firegun(string arg)
{
    string func,target;
    object ob;

    if( this_player()->is_busy() )
        return notify_fail("�A���b���L���A�S�ťκj�C\n");

    if( !this_object()->query("equipped") )
        return notify_fail("�A�S���j���ΡC\n");

    if( !this_player()->is_fighting() )
        return notify_fail("�A�S�b�԰��A����κj�C\n");

    if( !arg || sscanf(arg, "%s on %s", func, target)!=2 )
        return notify_fail("�ϥΫ��O�� gun attack on <�ؼ�>\n");

    if( !objectp(ob = present(target, environment(this_player()))) )
        return notify_fail("�A�䤣��ؼСC\n");

    if( !ob || !ob->is_character() || ob->is_corpse() || ob == this_player() )
        return notify_fail("�o�ӥؼЮڥ����ݭn�κj�g���C\n"NOR);

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
    msg = atk_msg[random(sizeof(atk_msg))];

    if( i > 20 ) {
        message_vision("�K���o�X�س��n�T�A���ӬO�l�u�Υ��F�C\n", me);
        return 1;
    }
    me->add_temp("apply/attack", 100);
    damage = COMBAT_D->isDamage(me, ob, this_object());
    me->add_temp("apply/attack", -100);

    if( damage < 20 ) damage = random(20);

    message_vision("\n$N�b�۵ۮ��_"HIW"�K��"NOR"�˷�$n�A�u�I�v�a�@�n�g�X�l�u�C\n", me, ob);
    if( !COMBAT_D->SkillHit(me, ob, exact, evade) ) {
        message_vision("���O�l�u�g���F�A�S����$n�C\n\n", me, ob);
    } else {
        ob->damage_stat("hp", damage, me);
        message_vision( sprintf("$n�Q�K�u�����F"+msg+"�A�n������F�@�Ƕˮ`(%d) %s\n\n", damage, COMBAT_D->report_status(ob) ), me, ob);
    }
    i++;
    me->start_busy(2);
    return 1;
}
