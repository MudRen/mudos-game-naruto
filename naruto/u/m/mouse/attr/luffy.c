#include <npc.h>
#include <ansi.h>

inherit F_SEABANDIT;

string *name = ({ "�j", "�@", "�ϳ�", "���b��", "��",
                  "�j�å�", "���ۼu", "�ԩ�", "�𫰬�" });

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$N" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$N" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$N" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight()
{
    object enemy;
    int damage, i;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( query("two_down", 1) ) {
        message_vision("\n$N"HIR"�y�W�S�X�@���Q��A�k�}�s�򻴽�a��"HIW"�u�c�v"HIR"��M�����b$n�����e�I�I\n"NOR, this_object(), enemy);
        for(i=0;i<=3;i++) {
            damage = random(query_ability("attack")) + query_ability("attack");
            message_vision(CYN"\n$N�@�������X�{�b$n�����ǡI\n"NOR, this_object(), enemy);
            if( random(query_ability("exact")) + query_ability("exact")/5 < random(enemy->query_ability("evade")) ) {
                message_vision("$n�@��"HIY"�� JET "+name[random(sizeof(name))]+NOR"�����@�뱽�L$N���y�U�A�b�a�W�F�X�Ӥj�}�C"+report_status(enemy)+"", enemy, this_object());
                this_object()->start_busy(1);
            } else {
                enemy->receive_damage(damage, this_object());
                message_vision("$n�ϥX"HIY"�� JET "+name[random(sizeof(name))]+NOR"�I�j�l���O�D�ߨ��$N�����F�X�h�I("+damage+")"+report_status(enemy)+"", enemy, this_object());
                enemy->start_busy(3);
            }
        }
        message_vision(HIR"\n\n$N���^�F�s������I\n\n"NOR, this_object(), enemy);
    } else {
        message_vision("$N��q�ۡG"HIG"�Q���ڪ���U�I���i��̡I�ݧڪ�"HIY"��"+name[random(sizeof(name))]+NOR+HIG"�I�I�I\n"NOR, this_object(), enemy);
        damage = random(query_ability("attack")) + query_ability("attack")/2;
        if( random(query_ability("exact")) + 50 > random(enemy->query_ability("evade")) ) {
            message_vision("\t$N�n���e�����I�U�����{�F�}�ӡI(0)"+report_status(enemy)+"", enemy, this_object());
            this_object()->start_busy(3);
        } else {
            enemy->receive_damage(damage, this_object());
            message_vision("\t$N�����D�Q�����F�X���A�����S�@�B�O���㪺�C("+damage+")"+report_status(enemy)+"", enemy, this_object());
            this_object()->start_busy(1);
        }
     }
     return;
}

void to_do_say()
{
    if( query("two_down", 1) ) {
        message_vision(CYN"$N�ݤF�f��A���W�G�ɪ��ĪG���������F�C\n"NOR, this_object());
        delete("nickname");
        add_temp("apply/exact", -600);
        add_temp("apply/evade", -600);
        add_temp("apply/intimidate", -300);
        add_temp("apply/wittiness", -300);
        delete("two_down");
        do_heal();
    }
    if( random(200) == 100 ) {
        do_chat( ({
            CYN"�|�ҵL�᪺��ۡG����٤���Y����\n"NOR,
            CYN"�|�Ҥj�s�ۡG�ڭn�Y�סI�Y�סI\n"NOR,
            CYN"�|�Ҥj�s�ۡG���N�I�}���ԡ�����I\n"NOR,
        }) );
    }
}

void create()
{
    set_name("�|��", ({ "luffy" }) );
    set_race("human");
    set_level(60);
    set_class("money_sea");  // �q�r����
    set("age", 15);
    set("title", HIY"�a��U��"NOR);
    set("long", "�Q�@�ɬF�������a�઺�i�Ȯ���A���O�ݥL���y���e���ˤl�@�I�]��\n"
                "���O�Q�c���j���j����C�u���L�y�������b���������������Y�W��\n"
                "�y�W�\�ۥL���зǰt�ơA�]�O�P�Y�H���n���w���L�����_�w"HIY"��U"NOR"�C\n");

    // �@��ɰʧ@
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":103, "amount":1, "p1":1, "p2":100 ]),       // ��U
        ([ "type":"food", "id":47, "amount":1, "p1":80, "p2":100 ]),     // �ɦ�
        ([ "type":"food", "id":68, "amount":1, "p1":80, "p2":100 ]),     // ����
        ([ "type":"food", "id":75, "amount":1, "p1":80, "p2":100 ]),     // �T����
        ([ "type":"food", "id":76, "amount":1, "p1":30, "p2":100 ]),     // ����K��
    }) );

    setup();
    set_skill("combat", 200);
    set_skill("parry", 200);
    set_skill("dodge", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 200);
    add_temp("apply/exact", 100);       // �R��
    add_temp("apply/evade", 100);       // �j��
    add_temp("apply/intimidate", 150);  // ������O
    add_temp("apply/wittiness", 150);   // ���m��O
    add_temp("apply/con", 20);
    add_temp("apply/str", 10);
}

void die()
{
    object luffy, enemy;

    if( query("two_down", 1) ) {
        ::die();
        return;
    }
    luffy = new(__DIR__"luffy.c");
    enemy = this_object()->query_opponent();

    if( !enemy ) enemy = this_object()->last_damage_giver();

    if( environment(this_object())->is_area() ) move_side(luffy, this_object());
    else luffy->move(environment(this_object()));

    luffy->set("nickname", HIW+BLINK"�G��"NOR);
    luffy->add_temp("apply/exact", 500);
    luffy->add_temp("apply/evade", 500);
    luffy->add_temp("apply/intimidate", 150);
    luffy->add_temp("apply/wittiness", 150);
    luffy->set("two_down", 1);

    message_vision("\n$N���D�R"HIG"�n�h���I�i�c�I�ڥͮ�F�I\n"NOR, luffy);
    message_vision(CYN"$N��������ۤv�����\�A���ӻ]����뤣������C\n"NOR, luffy);
    message_vision(CYN"$N�����Q�X�զ�]��A�o�X�F�F�n�T�I\n"NOR, luffy);
    message_vision("\n$N���D�R"HIG"�i�J�E�G�ɡC\n\n"NOR, luffy);

    luffy->kill_ob(enemy);
    if( function_exists("accept_kill", enemy) && !enemy->is_killing(luffy) && enemy->accept_kill(luffy) ) return;
    enemy->kill_ob(luffy);
    return;
}

int accept_fight(object me, string arg)
{
    do_chat( ({
        (: command, "shake" :),
        (: command, "say �ھj�F���Q���[" :),
    }) );
    return 0;
}
