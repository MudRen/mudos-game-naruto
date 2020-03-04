#include <npc.h>
#include <ansi.h>

string *name1 = ({ "�T����", "������", "������", "�Q�|����", "�Q������",
                   "�T�Q����", "���Q����", "�ʪἺ��", "������" });

string *name2 = ({ "�j���P��", "�x�L", "���`��", "��K" });

void do_fight()
{
    object enemy;
    int damage, raiseDamage, exact;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // �w�g�w��N�����
    if( enemy->is_busy() ) return;
    exact = COMBAT_D->exact(this_object(), enemy, 1)*3/10;

    add_temp("apply/exact", exact);
    message_vision("\n$N���������e�I�i"HIM"�u���G��v"NOR"�S���O���y"HIW+name1[random(sizeof(name1))]+NOR"�z�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("$N���⩿�M�q�a�W���X�ӡA���O�Q$n���}�F...\n", this_object(), enemy);
        this_object()->start_busy(1);
    } else {
        message_vision("$N���⩿�M�q$n���W���X�ӡA��$n�ιΧ��L�k�ʼu\n\n", this_object(), enemy);
        enemy->start_busy(4);
        if( random(3) > 0 ) {
            raiseDamage = 1000;
            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);
            message_vision("$N�C�}�����o�ʡy"HIY+name2[random(sizeof(name2))]+NOR"�z�j�b$n���W���⩿�M���X�F�����I\n"NOR, this_object(), enemy);
            enemy->damage_stat("hp", damage, this_object());
            message_vision( sprintf("�u�ذաv�@�n�A$N���ᤧ���$n�����f�g���y�����СA�����k�h���w(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        }
    }
    add_temp("apply/exact", -exact);
    return;
}
void create()
{
    set_name("ù��", ({ "robin", "_ROBIN_" }) );
    set_race("human");
    set_level(55);
    set_class("thief_sea");         // ����
    set("classify", "strengthen");  // �j��
    set("age", 23);
    set("gender", "female");
    set("title", HIW"�ҥj�Ǯa"NOR);
    set("long", "�����ԥj���v��s�̮q�W�ߤ@�����٪̡A�]�O��ɪ��������ߤ@��\n"
                "�@�����Է��`���H�A�Q�@�ɬF���q�r�ӵL�a�i�k�A�u��[�J���餣\n"
                "���I�q�k�`�����N�O�M��u�������v����C\n" );

    set("chat_chance", 30);
    set("chat_msg", ({
        (: do_heal :),
    }) );
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("set_drop", ({
        ([ "type":"obj", "id":16, "amount":1, "p1":10, "p2":100 ]),   // �Z�����+1
        ([ "type":"obj", "id":17, "amount":1, "p1":10, "p2":100 ]),   // �Z���ӱ�+1
        ([ "type":"obj", "id":20, "amount":1, "p1":10, "p2":100 ]),   // �Z�����z+1
        ([ "type":"obj", "id":21, "amount":1, "p1":10, "p2":100 ]),   // �Z���O�q+1
    }) );

    setup();
    set_skill("combat", 180);
    set_skill("dodge", 200);
    set_skill("parry", 160);
    set_skill("heavy hit", 160);
    set_skill("savage hit", 160);
    set_skill("continual hit", 160);

    add_temp("apply/exact", 50);        // �j��
    add_temp("apply/intimidate", 100);  // �����ޥ�
    add_temp("apply/wittiness", 50);    // ���m�ޥ�
    add_temp("apply/int", 15);
    add_temp("apply/con", 5);
    add_temp("apply/dex", 5);
    add_temp("apply/str", 5);
}
int accept_kill(object me, string arg)
{
    object ob;
    if( ob = present("_NAMI_", environment(this_object())) ) {
        ob->dismiss_team();
        ob->set_team(0);
        message_vision("\n�R�����D�G"HIG"����ˮ`$N�j�j�I\n"NOR, this_object());
        ob->set_team(this_object());
        ob->add_team_member(this_object());
        ob->kill_ob(me);
        if( function_exists("accept_kill", me) && !me->is_killing(ob) && me->accept_kill(ob) ) return 1;
        me->kill_ob(ob);
    }
    if( this_object()->query_condition("elf", 1) == 0 && ob ) {
        ob->force_me("perform chimera fay.assoil");
    }
}
int accept_fight(object me, string arg)
{
    do_chat( ({
        (: command, "shake" :),
    }) );
    return 0;
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 15 + random(6);

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
    msg = "\n\n"HIW"...�P��...�����Ԫ��U��...�藍�_...\n\n�ڵL�k�����j�a������A�N���v���ѩ�@�F�I\n\n"NOR;
    msg += HIR"�i���|�s�D�j"HIK"�u�c�]���l�v"HIR+this_object()->query("name")+"("+this_object()->query("id")+")�Q�@�ɬF��������"+enemy->query("name")+"("+enemy->query("id")+")�������F�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����ù����o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}