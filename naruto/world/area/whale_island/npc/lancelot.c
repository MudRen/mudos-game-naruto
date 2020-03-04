#include <npc.h>
#include <ansi.h>

void do_fight()
{
    int damage, raiseDamage, i;
    object enemy, wp;

    enemy = this_object()->query_opponent();
    wp = this_object()->query_temp("weapon/twohanded");

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    add_temp("apply/exact", 300);
    this_object()->damage_stat("mp", 15, this_object());
    message_vision(HIG"\n$N�i�{�F�ۤv�ާ@�t��O���ޥ��A�F���a���a�⤤"+wp->query("name")+HIG"�t�X�q�@"HIW"�u�զ�˪L�v\n\n"NOR, this_object(), enemy);

    for(i=1;i<6;i++) {
        message_vision(HIW"�ո��@�� "HIG"��"+chinese_number(i)+"���`\n"NOR, this_object());
        COMBAT_D->fight(this_object(), enemy, wp);
        message_vision("\n"NOR, this_object());
    }
    add_temp("apply/exact", -300);
    message_vision(CYN"$N�����F�t�X�I\n\n"NOR, this_object());
    return;
}

void to_do_say()
{
    do_chat( ({ 
        (: command, "say �b�ڨ��᪺�N�O���j����u�|������v�����@�y�C" :),
        (: command, "say �]���b�H���q�ۭӤp��������A�ҥH�S�O���y�H�ӬݺޡC" :),
        (: command, "say �̭��Ǫ����ɡA�S��O�N�O�i�h�F�C" :),
    }) );
}

void create()
{
    set_name("�������S", ({ "lancelot" }));
    set_race("human");
    set_level(60);
    set("camp", "hunter");
    set("title", HIG"Sir Lancelot"NOR);
    set_class("hxh_senior");   // ��¾�y�H
    set("long", "�y�H�`�|���ݪ���¾�y�H�A�]���ӤH��h�Ӥ��@�N��������@�بϩR\n"
                "���S���y�H�A�]���@����b��¾�y�H�L�k�ɤW�P���A����O���N�W�L\n"
                "�P�������F�C���Sù�|�����Q���O���H����O�A�]�����L�ݦu���a�C\n");

    set("age", 27);
    set("gender", "male");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set("chat_chance_combat", 25);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    set_skill("operation", 200);
    set_skill("solid", 200);
    map_skill("parry", "solid");
    carry_object(_DIR_AREA_"bone/npc/wp/lance.c")->wield("twohanded");
}

void relay_say(object ob, string arg)
{
    if( arg == "�|������" )  {
        do_chat( ({ 
            (: command, "say �|������@���|�y�C" :),
            (: command, "say ���O�s�u��������v�u�[�Ĥ���v�u�B�A����v�u��Ѥ���v" :),
            (: command, "say ���O���F�W�r�ثe�S�H���D�o�Ƕ𪺥γ~�C" :),
            (: command, "say �y�H���|�٦b���H�լd���C" :),
        }) );
    }
}