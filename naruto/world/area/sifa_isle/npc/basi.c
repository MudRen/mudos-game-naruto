#include <npc.h>
#include <ansi.h>

inherit F_SEASOLDIER;

void to_do_say()
{
    do_chat( ({ 
        NOR"���䪺�Y���D�R"HIG"���䪺�ڥs���u���ڴ��d��|�I�v\n"NOR,
        NOR"�k�䪺�Y���D�R"HIG"�k�䪺�ڥs���u�k�ڴ��d��|�I�v\n"NOR,
        CYN"�������Y�u��v���@�n�M�@�Ʊ����S��ˤl�C\n"NOR,
        NOR"�������Y�j�ۡR"HIG"�������ڴN�s���u������e�����I�v\n"NOR,
        (: command, "hit kabilu" :),
        NOR"���k�ڴ��d��|�P�n���D�R"HIG"�A�O�֪��I\n"NOR,
    }) );
}
void create()
{
    set_name("�ڴ��d��|", ({ "basi kabilu", "basi", "kabilu" }) );
    set_race("human");
    set_level(45);
    set("age", 75);
    set("camp", "police");
    set("title", HIR"�z�P��"NOR);
    set("long", "�q�k�q���j�k�x�A�_�Ǫ��O�L�~�M���T���Y�A²���N���a�����u����\n"
                "�@�ˡC�T���Y�����٦����۪���͡A�N�����G�]���Ӥ@�ˡA���L�L��\n"
                "���O�U���Q�f�̳��O�����P�˪����СC�u���D�I�v\n");

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":100+random(300), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"obj", "id":28, "amount":1, "p1":50, "p2":100 ]),                // ����
        ([ "type":"wp", "id":53, "amount":1, "p1":1, "p2":500 ]),                  // ���l�b
        ([ "type":"eq", "id":104, "amount":1, "p1":5, "p2":100 ]),                 // �q�k���P��
        
    }) );
    setup();
    carry_object(_DIR_WP_"longsword.c")->wield();
    add_temp("apply/armor", 200);
}
void die()
{
    object enemy, killer;
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        ::die();
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            ::die();
            return;
        } else
        if( environment(enemy) != environment(this_object()) ) {
            ::die();
            return;
        }
    }
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n\n"HIY+this_object()->query("name")+"�h�W���j�ۡG�n�O���ڧ��A�A�ڤ@�w�|�P�A���D���I\n"NOR;
    msg += HIR"\n"HIR"�i���|�s�D�j"+this_object()->query("name")+"("+this_object()->query("id")+")����"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")����F�I\n\n"NOR;

    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    if( random(100) < 30 ) {
        killer->add("exchange", 1);
        tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F 1 �I�I���I�ơC)\n"NOR);
    }
    ::die();
    return;
}
