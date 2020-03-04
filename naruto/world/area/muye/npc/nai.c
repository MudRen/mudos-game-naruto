#include <npc.h>
#include <ansi.h>

void do_fight()
{
    mapping cnd = ([]);
    object target, bug;
    object *enemy;
    int damage, raiseDamage, ntar, i, j, check;

    this_object()->charge_ob(query_temp("charge_ob"));

    // �S���ĤH
    target = this_object()->query_charging();
    enemy = this_object()->query_enemy();
    ntar = sizeof(enemy);

    if( !target ) target = this_object()->query_opponent();
    if( !target ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), target) ) return;
    } else {
        if( environment(target) != environment(this_object()) ) return;
    }
    if( query_condition("fang_cd") ) return;
    if( query_stat_current("hp") < query_stat_maximum("hp")/2 ) check = random(6);
    else check = random(3);

    cnd["name"] = HIK+"(CD)�γN"+NOR;

    switch( check ) {
        case 0:  // �άW���N (�@�����)
            command("say �h�a�A�Τl�̡I");
            message_vision(HIK"\n$N�|�_����I�i"NOR"�y"GRN"�άW���N"NOR"�z"HIK"�q�S�f�g�X����¦⥨�W�ĦV$n�I\n"NOR, this_object(), target);
            if( !COMBAT_D->isHit(this_object(), target) ) {
                message_vision("���G$n���I�{�L�����A�o�o�{���W���b��W�~�M�O�@�j�諸�¦�p��...\n\n"NOR, this_object(), target);
            } else {
                raiseDamage = 800;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), target, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 300 ) damage = 250 + random(51);

                target->receive_damage(damage, this_object());
                message_vision( sprintf("���W�����b$n���W�y���ˮ`�A�H��W�ݩ~�M�X���}��"HIK"�y�H�a�Ρz"NOR"����$n�����I(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), this_object(), target);
                target->query_temp("add_bug", 1);
            }
            cnd["duration"] = 3;
            this_object()->set_condition("fang_cd", cnd);
            break;
        case 1:  // �ξ����N (�׸������k)
            if( target->query_temp("bug_exit") ) break;
            command("say �Q�n�����H�a�ΡA�u��N�e�̩�(rid)���C");
            message_vision(HIK"\n$N�k�ⴧ�S�I�i"NOR"�y"HIM"�ξ����N"NOR"�z"HIK"���f�~�M�Q�@��¦�p�ΰ���A�L���i�k�F�I\n\n"NOR, this_object());
            for(i=0;i<ntar;i++) {
                enemy[i]->set_temp("bug_exit", 1);
            }
            bug = new(__DIR__"bug.c");
            bug->move(environment(this_object()));
            break;
        case 2:  // �ο����N (busy)
            command("say �H�a�Υi�O��u�@�骺�ޥ��A"+target->query("name")+"�w�g�Q�ګe��]��F�C");
            message_vision(HIK"\n$N�V��@���A�B�άd�J�Ա����⨭�W�H�ͪ��H�a��"NOR"�y"HIB"�ο����N"NOR"�z"HIK"�Q���Τl��ê��ʡI\n"NOR, this_object());
            for(i=0;i<ntar;i++) {
                if( enemy[i]->is_busy() ) continue;
                if( bug = present("_GI_BUG_", enemy[i]) ) {
                    message_vision(HIC"$N"HIC"�Q�����������H�a�����L�k�ʼu�I\n"NOR, enemy[i]);
                    j = bug->query_amount()/20;
                    if( j < 0 ) j = 1;
                    if( j > 5 ) j = 5;
                    enemy[i]->start_busy(j);
                } else {
                    message_vision("$N���W�S���H�a�ΡA�]��������v�T�C\n"NOR, enemy[i]);
                }
            }
            message_vision("\n"NOR, this_object());
            cnd["duration"] = 10;
            this_object()->set_condition("fang_cd", cnd);
            break;
        default: // �H�a�ΡE�k (�}�a�d��)
            if( ntar <= 0 ) break;
            command("say ���I��O...�o�˪���...");
            message_vision(HIK"\n$N�ݪ��p�t���h�F�A�I�i�X"HIW"�y"BLINK+NOR"�H�a��"HIK"�E"HIR"�k"NOR+HIW"�z"HIK"�Q�αH�a�Ϋr�_����������]�O�u�I\n"NOR, this_object());
            bug = new("/world/npc/disco.c");
            for(i=0;i<ntar;i++) {
                if( enemy[i]->query_owner() && present("_GI_BUG_", enemy[i]) ) {
                    message_vision("$N"HIC"�]���ҧt��q�Q"HIK"�H�a��"NOR+HIC"���Ӭp�ɦӹ����_�u�참�@�˰���F...\n"NOR, enemy[i]);
                    remove_killer(enemy[i]);
                    enemy[i]->remove_killer(this_object());
                    enemy[i]->guard_ob(0);
                    if( !enemy[i]->query_food() ) enemy[i]->set_owner(bug);
                    set_temp("bug_ok", 1);
                    heal_stat("hp", query_stat_maximum("hp")/10);
                } else {
                    heal_stat("hp", query_stat_maximum("hp")/20);
                }
            }
            if( !query_temp("bug_ok") ) {
                message_vision(HIW"���O���G�S���o�ͤ���Ʊ��C\n"NOR, this_object());
                heal_stat("hp", query_stat_maximum("hp")/8);
            }
            delete_temp("bug_ok");
            message_vision("\n"NOR, this_object());
            destruct(bug);
            break;
    }
    // �񧹧ޯ�N�n�h���A���M���a���]�|�@���l
    this_object()->charge_ob(0);

    // �H�a�άO�b perform �ϥΧ��᰽����b���W��
    for(i=0;i<ntar;i++) {
        if( enemy[i]->query_temp("add_bug") ) j = 20+random(51);
        else j = random(6);
        if( bug = present("_GI_BUG_", enemy[i]) ) {
            bug->add_amount(j);
        } else {
            if( file_size(__DIR__"item/gi_bug.c") < 0 ) return;
            if( catch(bug = new(__DIR__"item/gi_bug.c")) ) return;
            if( !bug->move(enemy[i]) ) {
                destruct(bug);
            } else {
                bug->set_amount(j);
                bug->set_owner(enemy[i]);
                bug->set("changed", 1);
            }
        }
    }
    return;
}

void to_do_say()
{
    object bug;

    if( bug = present("_BUG_WALL_", environment(this_object())) ) {
        message_vision(CYN"�����԰���A$N�ߨ�N$n"CYN"���^�F�C\n"NOR, this_object(), bug);
        destruct(bug);
    }
    if( query_temp("charge_ob") ) delete_temp("charge_ob");
    do_heal();
    return;
}

void create()
{
    set_name("�o�k�ӤD", ({ "you ni zhi nai", "nai" }));
    set_race("human");
    set_level(55);
    set("camp", "muye");
    set_class("middle");            // ����
    set("classify", "strengthen");  // �j��
    set("age", 16);
    set("gender", "male");

    set("long", "�I�q�֨����L�A�԰��O���藍�z�A�b���Կ�޸շҡA�P�ħJ��԰���\n"
                "�ݨ�L���i�Ȫ��W���Ԫk�СбH�a�ΡA�q�ӱo���L�D�ΨϤ@�ڪ���H\n"
                "�A�P�αکw�U�����A���Ѭd�J�Ե��ΡA���Ϋh���U�L�԰��C\n");

    set("chat_chance", 30);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    set_skill("continual hit", 180);
    set_skill("heavy hit", 160);
    set_skill("ninja", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");

    add_temp("apply/exact", 250);        // �R��
    add_temp("apply/intimidate", 150);   // �����ޥ�
    add_temp("apply/armor", 150);        // ���m��O
    add_temp("apply/str", 5);
    add_temp("apply/con", 10);
    add_temp("apply/int", 15);
}

void die()
{
    object enemy, killer;
    int i = 15 + random(16);
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        destruct(this_object());  // �䤣����A��������
        return;
    }
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = HIK"\n�o�k�@�ڪ����N�~�M�ѵ��F"+enemy->rank()+"�H\n\n"HIW"�o�������ѧڰO��F�A�U���A�V"+enemy->query("name")+"�D�ԡI\n\n"NOR;
    msg += HIG"�i"HIR"�츭�ְT"HIG"�j"HIG"�줧���ި��Ϊ��o�k�@�ں�^"+this_object()->query("name")+"�A�Q�j����"+enemy->query("name")+"�����ѤF�C\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

int accept_kill(object me, string arg)
{
    message_vision("$N���D�G"HIG+me->query("name")+"�O�a�H�ڤw�g��w$n�F�C\n"NOR, this_object(), me);
    set_temp("charge_ob", me);
}
