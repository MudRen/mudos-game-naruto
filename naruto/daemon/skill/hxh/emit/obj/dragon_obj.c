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

// �R��
void do_destruct()
{
    // �w�g�n�������d���N���Τ@���ۭn�����F
    if( query("WILL_DELETE") ) return;

    // �o�{�d���l��L�h���|�o�ͫO�@���~
    // �]�����}�ɨS���R���d���O�@
    // �ҥH�ֿn�F�L�h�� guard ��T  by mouse 2009/2/16
    this_object()->guard_ob(0);
    message_vision("$N"HIY"�o�X�@�}�j���A�����b�o�̤F�C\n"NOR, this_object());
    set("WILL_DELETE", 1);

    // �������@�ǰʧ@���]�L
    do_chat( ({ (: destruct, this_object() :) }) );
    return;
}

void do_fight()
{
    int damage, raiseDamage;
    object enemy;
    mapping cnd = ([]);

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( query_condition("tiger_cd") ) return;

    this_object()->damage_stat("mp", 50, this_object());
    message_vision("\n$N"HIM"�C�q�@�n�I�i"HIW"�y"HIC"����"HIW"�z"HIM"���Φ��p���y�A�q�D�`�p�p�����Ҽ��V$n�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("���G$N�ݯ}�F��աA����}�a�F$n���i����ҡC\n\n", enemy, this_object());
        start_busy(2);
    } else {
        raiseDamage = query_skill("strength")/2 + query_owner()->query_skill("dragon-head draw");

        add_temp("apply/attack", raiseDamage); 
        damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/twohanded"));
        add_temp("apply/attack", -raiseDamage);

        if( damage < 150 ) damage = 100 + random(51);

        enemy->receive_damage(damage, this_object());
        message_vision( sprintf("$N���X�s�����$n�Q����������A�i�L�K��$n���ӻH�����@�r(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        start_busy(1);
    }
    cnd["name"] = HIC+"(CD)����"+NOR;
    cnd["duration"] = 8;

    set_condition("tiger_cd", cnd);
    return;
}

// �H���ˬd�֦��̬O�_�������d�J�ԡA�åB�l��
void do_check()
{
    string name;
    object ob;

    name = owner->query("id");
    ob = LOGIN_D->find_body(name);

    // �֦��̤��b�u�W�A�h�s����
    if( !ob && userp(ob) ) {
        do_destruct();
        return;
    }
    // ���b�԰����ɦ۰ʮ���
    if( !this_object()->is_fighting() || !ob->is_fighting() ) {
        do_destruct();
        return;
    }
    // �b���P��m�]�|����
    if( environment(this_object())->is_area() ) {
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

    // ���\�q�L�N�|�ϥ� pe
    do_chat( ({ (: do_fight :) }) );
    return;
}

// �s�Q�������uCD
void get_CD()
{
    mapping cnd = ([]);

    tell_object(query_owner(), HIR"�]�����s�Q�ĤH�����A�ϧA���믫���췥�j�������I\n"NOR);

    cnd["name"] = HIR+"�s�����l"+NOR;
    cnd["duration"] = 20;

    query_owner()->set_condition("dragon_draw_cd", cnd);
    return;
}

// ���˴N��������
void unconcious()
{
    get_CD();
    do_destruct();
    return;
}

void die()
{
    get_CD();
    do_destruct();
    return;
}

// �O�_�����R�O
int accept_order(object who, string cmd)
{
    return 0;  // �����O�������
}

void create()
{
    set_name("���s", ({ "dragon", "_DRAGON_NPC_" }));
    set_race("beast");

    set("long", "���O���s�A�]��X�t��O�̰��K�ת�����O�Өϯ}�a�O�j�����ɡC\n");
    set("limbs", ({ "�s�Y", "����", "����", "�s��", "�s��", "�sŽ" }) ); 
    set("age", 1000 + random(5000));

    // ���ɰʧ@�G�ˬdowner�٦b���b
    set("chat_chance", 50);
    set("chat_msg", ({
        (: do_check :),
    }));

    // �԰��ɰʧ@�G�ˬdowner�٦b���b
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_check :),
    }) );
    setup();
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