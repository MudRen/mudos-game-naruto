#include <npc.h>
#include <ansi.h>

object owner;

// �]�w�֦���
int set_owner(object obj)
{
    if( !objectp(obj) ) return 0;
    owner = obj;
}

// �d�߾֦���
object query_owner()
{
    if( !objectp(owner) ) return 0;
    return owner;
}

// �R����H
void do_destruct()
{
    // �w�g�n�������d���N���Τ@���ۭn�����F
    if( query("WILL_DELETE") ) return;

    // �o�{�d���l��L�h���|�o�ͫO�@���~
    // �]�����}�ɨS���R���d���O�@
    // �ҥH�ֿn�F�L�h�� guard ��T  by mouse 2009/2/16
    this_object()->guard_ob(0);
    if( query("WILL_DIE") ) message_vision("$N�]���ͩR�O�ӺɡA�ܦ��@��Фg�C\n", this_object());
    else message_vision("�]���D�H�L�k���ѩ��O...$N�v���\\�䦺�`...\n", this_object());
    set("WILL_DELETE", 1);

    // �������@�ǰʧ@���]�L
    do_chat( ({ (: destruct, this_object() :) }) );
}

// �H���ˬd�֦��̬O�_�������d�J�ԡA�åB�l��
void do_check()
{
    int i, ntar;
    object enemy;

    // �֦��̤��b�u�W�A�h��H����
    if( !objectp(owner) ) {
        do_destruct();
        return;
    }

    // �p�𪬺A�ɥD�H���b���Ǫ�������
    if( this_object()->query("change") != 1 ) {
        if( environment(owner)->is_area() ) {
            if( !area_environment(this_object(), owner) ) {
                do_destruct();
                return;
            }
        } else {
            if( environment(this_object()) != environment(owner) ) {
                do_destruct();
                return;
            }
        }
    }

    // �b���P��m�|�۰ʲ���D�H����A���O�n���Ӥ@�ǩ��O
    if( environment(owner)->is_area() ) {
        if( !area_environment(this_object(), owner) ) {
            area_move(environment(owner), this_object(), owner->query("area_info/x_axis"), owner->query("area_info/y_axis"));
            owner->damage_stat("mp", 2);
            message_vision("$N�l���F$n�����O�᩿�M�q�a�W�ۤF�X�ӡC\n", this_object(), owner);
            return;
        }
    } else {
        if( environment(this_object()) != environment(owner) ) {
            this_object()->move(environment(owner));
            owner->damage_stat("mp", 2);
            message_vision("$N�l���F$n�����O�᩿�M�q�a�W�ۤF�X�ӡC\n", this_object(), owner);
            return;
        }
    }

    if( owner->query_stat("mp") < 10 ) {
        do_destruct();
        return;
    }
    return;
}

// �O�_�����R�O
int accept_order(object who, string cmd)
{
    return 0;  // �����O�������
}
void create()
{
    set_name(YEL"�p��"NOR, ({ "tree", "_TREE_" }));
    set_race("human");
    set("long", "�@�ʩ|�b��������p��C\n");
    set("age", random(10) + 1);
    set("limbs", ({ "���", "��K", "��", "���", "���", "��F", "�~��", "��}" }) );
    set("chat_chance", 50);
    set("chat_msg", ({
        (: do_check :),
    }));
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_check :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":60, "amount":1, "p1":60, "p2":100 ]),       // ��K
    }) );
    setup();
}

void unconcious()
{
    die();
    return;
}

void die()
{
    string name;
    int raiseDamage, damage, sk;
    object enemy, ob;

    enemy = this_object()->last_damage_giver();
    name = owner->query("id");
    ob = LOGIN_D->find_body(name);
    sk = owner->query_skill("born-again branch", 1);

    if( !enemy ) {
        set("WILL_DELETE", 1);
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            set("WILL_DELETE", 1);
            return;
        } else if( environment(enemy) != environment(this_object()) ) {
            set("WILL_DELETE", 1);
            return;
        }
    }

    // �w�g���z�L�N���ǦA�z�F
    if( query("WILL_DIE") == 1 || query("WILL_DELETE") == 1 ) {
        return;
    }
    enemy->remove_killer(this_object());
    message_vision("$N�{�����e���M�o�ʤF���ͪ�����A�ֳt�a�ĦV$n�I\n\n", this_object(), enemy);

    if( sk < 80 ) raiseDamage = ob->query_stat_maximum("hp")/10;
    if( sk < 140 ) raiseDamage = ob->query_stat_maximum("hp")/9;
    if( sk < 200 ) raiseDamage = ob->query_stat_maximum("hp")/8;
    else raiseDamage = ob->query_stat_maximum("hp")/6;

    if( raiseDamage >= 2000 ) raiseDamage = 2000;

    this_object()->add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    this_object()->add_temp("apply/attack", -raiseDamage);

    enemy->receive_damage(damage, this_object());
    message_vision("$N"HIW"�C��K�}����"NOR"$n"HIW"���A���骺���߶}�l�o�X"HIR+BLINK"������~"NOR+HIW"�I\n"NOR, this_object(), enemy);
    message_vision( sprintf("$N�ɤF�ۤv�̫�@���O�q�A�N$n�����|������(%d) %s\n\n", damage, COMBAT_D->report_status(enemy)), this_object(), enemy);
    owner->delete_temp("TREE_ONE");
    owner->delete_temp("TREE_TWO");
    set("WILL_DELETE", 1);
    ::die();
    do_chat( ({ (: destruct, this_object() :) }) );
    return;
}

// ����fight
int accept_fight(object me, string arg)
{
    return 0;
}

// ���� kill
int accept_kill(object me, string arg)
{
    remove_all_killer();
    me->remove_killer(this_object());
    return 1;
}