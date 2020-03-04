#include <npc.h>
#include <ansi.h>
#include "fire_sk.h"

void create()
{
    set_name("���U��", ({ "beautiful monkey", "monkey", "_KING_TWO_" }) );
    set_level(40);
    set_race("human");
    set("gender", "male");
    set("title", HIR"���E�n�p�y��"NOR);
    set("nickname", HIY"�L"NOR);
    set("limbs", ({ "�U�Y", "���u", "����", "�ݤf", "�U�}", "�ӻH", "�y��", "����" }) );
    set("age", 3000);
    set("long", "�a�U�l���A��F�@�藍���D�q���̷m�Ӫ��H����A���~�A���������{\n"
                "�{�A���L�]���o�̦a�Ϊ����A�ҥH�j������A���ֿN���F�C\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        NOR"���U��"HIR"���ۤ@����l�ݸԵۦۤv���e��...���G�ܺ��N�C\n"NOR,
    }));
    set("chat_chance_combat", 35);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":151, "amount":1+random(15), "p1":80, "p2":100 ]),  // �o�g
        ([ "type":"obj", "id":152, "amount":1+random(25), "p1":80, "p2":100 ]),  // �ЮJ
        ([ "type":"obj", "id":153, "amount":1+random(3), "p1":80, "p2":100 ]),   // ��G
        ([ "type":"obj", "id":156, "amount":1+random(10), "p1":80, "p2":100 ]),  // �H��
        ([ "type":"obj", "id":148, "amount":1+random(10), "p1":30, "p2":100 ]),  // ����
        ([ "type":"obj", "id":158, "amount":1+random(3), "p1":10, "p2":100 ]),   // �N�g
    }) );
    setup();
    add_temp("apply/attack", 50);
}

void die()
{
    object enemy, killer, *targets;
    int i, ntar, x, y;
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        ::die();
        return;
    }
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    i = query_level()*10;
    msg = "\n"HIW"�i�|�褧��j"HIR"��������G�ӺG�s�@�n�A"+enemy->query("name")+"�N�G�Ӧu���"NOR"�u"+this_object()->query("title")+"�v"HIR+this_object()->query("name")+"�����e�F�I\n\n"NOR;

    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    if( killer->query_level() - 10 <= this_object()->query_level() ) {
        if( random(100) < 15 ) {
            tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F 1 �I�I���I�ơC)\n"NOR);
            killer->add("exchange", 1);
        }
        tell_object(killer, HIR"\n�A�����F"+this_object()->query("name")+"���B�~��o�F "HIY+i+HIR" �I���I�C\n"NOR);
        killer->add_point("learn", i);
    }
    if( random(10) > 5 ) {
        targets = query_enemy();
        x = random(30);
        y = random(30);

        // �N���a���Ҧ��ʧ@�����M�����L��m�h
        // �����w�y�СA�n�����a���d���]��ۭ��L�h
        for(ntar=0;ntar<sizeof(targets);ntar++) {
            if( killer->is_busy() ) targets[ntar]->interrupt(targets[ntar], "*unconcious");
            if( userp(targets[ntar]) ) tell_object(targets[ntar], YEL"\n"+this_object()->query("name")+"�{���e�κɳ̫᪺�O�q�N�A��������襤�I\n"NOR);
            if( targets[ntar]->is_busy() ) {
                if( userp(targets[ntar]) ) tell_object(killer, "���Q�A���ưk�L�@�T�C\n\n"NOR);
            } else {
                if( !area_move(environment(targets[ntar]), targets[ntar], x, y) ) {
                    if( userp(targets[ntar]) ) tell_object(targets[ntar], "���Q�A���ưk�L�@�T�C\n\n"NOR);
                }
            }
        }
    }
    ::die();
    return;
}
