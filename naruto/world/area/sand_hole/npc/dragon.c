#include <npc.h>
#include <ansi.h>

void do_fight()
{
    mapping cnd = ([]);
    int damage;
    object enemy;

    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_condition("body_strength_cond", 1) == 0) {
        message_vision("\n$N���X�X����w�A�@�f���V�ۤv��W���X�ӥ޹D�u"BRED+HIW"�٦ױj��"NOR"�v�I\n"NOR,this_object(), enemy);
        message_vision("�L�S�h�[$N�����u�٦��z���A�����O�j�T�W�ɤF�C\n\n"NOR,this_object(), enemy);

        cnd["name"] = HIR"���׶}�o"NOR;
        cnd["duration"] = 100;
        cnd["attack"] =  66;
        cnd["armor"] =  40;

        this_object()->set_condition("body_strength_cond", cnd);
    } else {
        message_vision("\n$N�N��N�M�I�J�F�a��ϥX�u"GRN"���s�ɤѦ�"NOR"�v�j�O�����M�į}�F�a����$n�I\n"NOR,this_object(), enemy);
        if( !COMBAT_D->isHit(this_object(), enemy) ) {
            message_vision("�M�դ@�n�A���M�b�F��W��X�F�@�Ӥj�|�A�|�P�F�h���_�Ƹ��C\n\n"NOR, this_object(), enemy);
            this_object()->start_busy(1);
        } else {
            damage = COMBAT_D->isDamage(this_object(), enemy, this_object()->query_temp("weapon/righthand"));
            if( damage < 400 ) {
                damage = 300 + random(100);
            } else {
                damage += 400;
            }
            enemy->damage_stat("hp", damage, this_object());
            message_vision( sprintf("��a�@�n�A���M�A��b$n�����W�A�Q�x�X�j�q�A��A���H�Y�Q�F�a�ҧl��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->start_busy(1);
        }
    }
    return;
}

void do_startWar()
{
    if( query_stat("hp") < 3000 ) {
        message_vision("$N"HIW"���X��N�M��ۤv�ϥΥ~���N�A���W���ˤf�ֳt�^�_�F�C\n", this_object());
        set_stat_current("hp", query_stat_maximum("hp"));
        set_stat_current("ap", query_stat_maximum("hp"));
        set_stat_current("mp", query_stat_maximum("hp"));
    } else if( query("war_qk") == 0 ) {
        if( WAR_D->doStartWar(this_object(), "/world/war/sand_hole.c") ) message_vision(CYN"$N�N���M���b�a�ϤW�I�ש�M�w�i����u�F�I\n"NOR, this_object());
        else message_vision(CYN"$N���_��W���a�ϬݤF�ݡA���G�b�䤰��a������C\n"NOR, this_object());
        this_object()->set("war_qk", 1);
        call_out("war_qk", 301, this_object());
    } else {
        do_chat((: command, "say ���I�A���F��X�h�j�A�ǿ��]�a..." :));
    }
}

void war_qk()
{
    message_vision("$N�ϥ��Y�Q�F�@�U���D�G"HIG"��...�t���h�O�ɭԤF�C\n"NOR, this_object());
    this_object()->delete("war_qk");
    return;
}

void create()
{
    set_name("�s����", ({ "lon jiao san", "lon", "san" }) );
    set("channel_id", "�s����");
    set_level(48);
    set_race("human");
    set("age", 42);
    set("camp", "sand_bandit");
    set("title",YEL"�F�ޭ���"NOR);
    set("nickname",GRN"�s�S"NOR);
    set("long", "�Y�v�V���@�����A��⮳�۪��{�{����N�M�A���W����A�O������\n"
                "�窺���T�¦�A�ݰ_�ӴN���O���̨Ӫ��K��C\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: do_startWar :),
    }));
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":49, "amount":1, "p1":10, "p2":100 ]),      // �s�M
        ([ "type":"wp", "id":27, "amount":1, "p1":5, "p2":100 ]),       // ��N�M
        ([ "type":"wp", "id":28, "amount":1, "p1":1, "p2":1000 ]),      // �C�s
        ([ "type":"eq", "id":29, "amount":1, "p1":60, "p2":100 ]),      // ����Ф��Y�y
        ([ "type":"eq", "id":27, "amount":1, "p1":80, "p2":100 ]),      // �Ф�U
    }) );
    setup();
    carry_object("/world/wp/scalpel.c")->wield("righthand");
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
    msg = "\n\n"HIG+this_object()->query("name")+"���D�G�ѧ̡I�F�ޭ��⤧��N�浹�A�F�I\n"NOR;
    msg += HIR"\n"HIR"�i���|�s�D�j"+this_object()->query("name")+"("+this_object()->query("id")+")����"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")����F�I\n\n"NOR;

    killer->add("exchange", 1);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A�����s������o�F 1 �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}