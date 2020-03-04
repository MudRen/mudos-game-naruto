#include <npc.h>
#include <ansi.h>
#include "sand_sk.h"

void create()
{
    set_name("�r�h��", ({ "king fen", "fen", "_KING_TWO_" }) );
    set_level(40);
    set_race("human");
    set("gender", "male");
    set("title", HIY"�Ů�ìV"NOR);
    set("nickname", HIK"�L"NOR);
    set("limbs", ({ "��d", "Ĳ��", "�H�G", "����", "�L��", "�d��" }) );
    set("age", 3000);
    set("long", "�h�A�����A����e�{�����A���G�a���@�r�A�u���e�ɱ`�R�X�����\n"
                "�����馾�V�|�P���Ů�A�p�G�b�~�������D�Q�}�X�i�@��F�C\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        NOR"�r�h��"GRN"�R�ۺ�⪺�r���...\n"NOR,
    }));
    set("chat_chance_combat", 35);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":151, "amount":random(25)+1, "p1":80, "p2":100 ]),  // �o�g
        ([ "type":"obj", "id":152, "amount":random(15)+1, "p1":80, "p2":100 ]),  // �ЮJ
        ([ "type":"obj", "id":153, "amount":random(3)+1, "p1":80, "p2":100 ]),   // ��G
        ([ "type":"obj", "id":156, "amount":random(10)+1, "p1":80, "p2":100 ]),  // �H��
        ([ "type":"obj", "id":154, "amount":random(10)+1, "p1":30, "p2":100 ]),  // �F�t
        ([ "type":"obj", "id":149, "amount":random(3)+1, "p1":10, "p2":100 ]),   // ����
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
    msg = "\n"HIW"�i�|�褧��j"HIY"�[�Ĥ���G�ӪŮ��ܦn�F�A�]��"+enemy->query("name")+"�����F�G�Ӧu���"NOR"�u"+this_object()->query("title")+"�v"HIY+this_object()->query("name")+"�I\n\n"NOR;

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
