#include <npc.h>
#include <ansi.h>

string *name = ({ "�j", "�@", "�ϳ�", "���b��", "��",
                  "�j�å�", "���ۼu", "�ԩ�", "�𫰬�" });

void do_fight()
{
    object ob, enemy;
    int damage, raiseDamage, i, exact, evade;

    ob = this_object();
    enemy = ob->query_opponent();

    if( !enemy ) return;
    if( environment(ob)->is_area() ) {
        if( !area_environment(ob, enemy) ) return;
    } else {
        if( environment(enemy) != environment(ob) ) return;
    }
    // �G�ɧP�_
    if( !query("two_down") && query_stat_current("hp") < query_stat_maximum("hp")*2/3 ) {

        ob->set("nickname", HIW+BLINK"�G��"NOR);
        ob->add_temp("apply/exact", 400);
        ob->add_temp("apply/evade", 400);
        ob->set("two_down", 1);

        ob->set_stat_current("hp", ob->query_stat_maximum("hp"));
        ob->set_stat_current("ap", ob->query_stat_maximum("ap"));
        ob->set_stat_current("mp", ob->query_stat_maximum("mp"));

        message_vision("\n$N���D�R"HIG"�n�h���I�i�c�I�ڥͮ�F�I\n"NOR+CYN"$N��������ۤv�����\�A���ӻ]����뤣������C\n"CYN"$N�����Q�X�զ�]��A�o�X�F�F�n�T�I\n"NOR"$N���D�R"HIG"�i�J�E�G�ɡC\n\n"NOR, ob);

        kill_ob(enemy);
        if( function_exists("accept_kill", enemy) && !enemy->is_killing(ob) && enemy->accept_kill(ob) ) return;
        enemy->kill_ob(ob);
        return;
    }
    // �@��ޯ�P�G�ɧޯ�
    if( query("two_down", 1) ) {
        exact = COMBAT_D->exact(this_object(), enemy, 1) + COMBAT_D->exact(this_object(), enemy, 1)/5;
        evade = COMBAT_D->evade(enemy, this_object(), 1);

        message_vision("\n$N"HIR"�y�W�S�X�@���Q��A�k�}�s�򻴽�a��"HIW"�u�c�v"HIR"��M�����b$n�����e�I�I\n"NOR, this_object(), enemy);
        for(i=0;i<=3;i++) {
            message_vision(CYN"\n$N�@�������X�{�b$n�����ǡI\n"NOR, ob, enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("$N�@��"HIY"�� JET "+name[random(sizeof(name))]+NOR"�����@�뱽�L$n���y�U�A�b�a�W�F�X�Ӥj�}�C\n", ob, enemy);
                ob->start_busy(2);
            } else {
                raiseDamage = 1200;
                ob->add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(ob, enemy, 0);
                ob->add_temp("apply/attack", -raiseDamage);
                enemy->receive_damage(damage, ob);
                message_vision( sprintf("$N�ϥX"HIY"�� JET "+name[random(sizeof(name))]+NOR"�I�j�l���O�D�ߨ��$n�����F�X�h�I(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), ob, enemy);
                ob->start_busy(1);
            }
        }
        message_vision(HIR"\n$N���^�F�s������I\n\n"NOR, ob, enemy);
    } else {
        message_vision("\n$N��q�ۡG"HIG"�Q���ڪ���U�I���i��̡I�ݧڪ�"HIY"��"+name[random(sizeof(name))]+NOR+HIG"�I�I�I\n"NOR, ob, enemy);
        if( !COMBAT_D->isHit(ob, enemy) ) {
            message_vision("$n�n���e�����I�U�����{�F�}�ӡI\n\n", ob, enemy);
            ob->start_busy(3);
        } else {
            raiseDamage = 1500;
            ob->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(ob, enemy, 0);
            ob->add_temp("apply/attack", -raiseDamage);
            enemy->receive_damage(damage, ob);
            message_vision( sprintf("$n�����D�Q�����F�X���A�����S�@�B�O���㪺(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), ob, enemy);
            ob->start_busy(1);
        }
    }
    return;
}

void to_do_say()
{
    if( query("two_down", 1) ) {
        message_vision(CYN"$N�ݤF�f��A���W�G�ɪ��ĪG���������F�C\n"NOR, this_object());
        delete("nickname");
        add_temp("apply/exact", -400);
        add_temp("apply/evade", -400);
        delete("two_down");
    }
    if( random(200) == 100 ) {
        do_chat( ({
            CYN"�|�ҵL�᪺��ۡG����٤���Y����\n"NOR,
            CYN"�|�Ҥj�s�ۡG�ڭn�Y�סI�Y�סI\n"NOR,
            CYN"�|�Ҥj�s�ۡG���N�I�}���ԡ�����I\n"NOR,
        }) );
    }
    do_heal();
}

void create()
{
    set_name("�|��", ({ "luffy" }) );
    set_race("human");
    set_level(60);
    set_class("money_sea");         // �q�r����
    set("classify", "strengthen");  // �j��
    set("age", 17);
    set("title", HIY"�a��U��"NOR);
    set("long", "�Q�@�ɬF�������a�઺�i�Ȯ���A���O�ݥL���y���e���ˤl�@�I�]��\n"
                "���O�Q�c���j���j����C�u���L�y�������b���������������Y�W��\n"
                "�y�W�\�ۥL���зǰt�ơA�]�O�P�Y�H���n���w���L�����_�w"HIY"��U"NOR"�C\n");

    // �@��ɰʧ@
    set("chat_chance", 20);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":103, "amount":1, "p1":1, "p2":100 ]),               // ��U
        ([ "type":"eq", "id":115, "amount":1, "p1":1, "p2":800 ]),               // ��U
        ([ "type":"food", "id":47, "amount":1+random(5), "p1":60, "p2":100 ]),   // �ɦ�
        ([ "type":"food", "id":68, "amount":1+random(21), "p1":80, "p2":100 ]),  // ����
        ([ "type":"food", "id":75, "amount":1+random(11), "p1":80, "p2":100 ]),  // �T����
        ([ "type":"food", "id":76, "amount":1, "p1":60, "p2":100 ]),             // ����K��
    }) );

    setup();
    set_skill("combat", 200);
    set_skill("parry", 200);
    set_skill("dodge", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 200);

    // ���[��O�A������O���I�t
    add_temp("apply/exact", 100);       // �R��
    add_temp("apply/evade", 100);       // �j��
    add_temp("apply/intimidate", 150);  // ������O
    add_temp("apply/wittiness", 150);   // ���m��O
    add_temp("apply/con", 20);
    add_temp("apply/str", 10);

    // �˳�
    carry_object(__DIR__"eq/boater2.c")->wear();
}

void die()
{
    object enemy, killer;
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        destruct(this_object());  // �䤣����A��������
        return;
    }
    if( query("two_down", 1) ) {  // �G�ɤ~������
        int i = 120 + random(31);
        // �d��������D�H��
        if( !userp(enemy) && objectp(enemy->query_owner()) ) {
            killer = enemy->query_owner();
        } else {
            killer = enemy;
        }
        msg = "\n\n"YEL"\t�|���y�W�S�X�}�Ԫ����e��ۦۤv������έ���..."NOR"\n\n"HIW"\t�y�U����u�藍�_���ڭn���"BLINK"���F�I"NOR+HIW"�z"NOR"\n\n"YEL"\t��U����Φ����@�֦ӤW�A�o���M�Ϥ��F�|��..."NOR"\n\n"HIR"\t�j�x���x����U�p�l�A�~�M�Q"HIW+enemy->rank()+enemy->query("name")+HIR"�����F�I"NOR"\n\n\n"NOR;

        killer->add("exchange", i);
        CHANNEL_D->say_channels(this_object(), "news", msg, 1);
        tell_object(killer, HIY"(�]���A�����|����o�F "+i+" �I�I���I�ơC)\n"NOR);
        ::die();
        return;
    } else {
        message_vision("\n$N��]�仡�D�R"HIG"$n�u�O�ӱj�F�A�٬O���ְk���a�I"NOR"\n$N��]�仡�D�R"HIG"�ڨS���z�Ѹ�$n���[�I\n\n"NOR, this_object(), enemy);
        message_vision("$N�@�ȷϦa�N�����H�F�C\n\n"NOR, this_object(), enemy);
        destruct(this_object());
        return;
    }
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
