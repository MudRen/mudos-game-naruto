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
    if( this_object()->query_condition("elf", 1) == 0) {
        message_vision("\n$N���X�@�Ӹ˦��Ŧ�G�骺�w���u"BBLU+HIW"��������"NOR"�v�P���@�n��b�ۤv���W�I\n"NOR,this_object(), enemy);
        message_vision("�L�S�h�[$N�}�B�ܪ���[�ֳt�A�j�ׯ�O���G���ɤF���֡C\n\n"NOR,this_object(), enemy);

        cnd["name"] = HIB"��������"NOR;
        cnd["duration"] = 100;
        cnd["evade"] = 50;

        this_object()->set_condition("elf", cnd);
    } else {
        message_vision("\n$N�Ϥⴤ���N�M�A���M���l��Ӥ@�I�������a�A�@���u"HIW"�r�긨�a��"NOR"�v�I\n"NOR,this_object(), enemy);
        if( !COMBAT_D->isHit(this_object(), enemy) ) {
            message_vision("���M$n�|�����a�W�u�I�v�a�@�n�z�X�Ʈڿ��w�A�t�I��ˤF$n�C\n\n"NOR, this_object(), enemy);
            this_object()->start_busy(1);
        } else {
            damage = COMBAT_D->isDamage(this_object(), enemy, this_object()->query_temp("weapon/righthand"));
            if( damage < 350 ) {
                damage = 250 + random(100);
            } else {
                damage += 350;
            }
            enemy->damage_stat("hp", damage, this_object());
            message_vision( sprintf("����$n�̲����ɡA�a���u�I�v�a�@�n�z�X�Ʈڿ��w�A�������ʪ���i$n�������y���ж�(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->start_busy(1);
        }
    }
    return;
}
void do_heal()
{
    if( query_stat("hp") < 3000 ) {
        message_vision("$N"HIW"���X��N�M��ۤv�ϥΥ~���N�A���W���ˤf�ֳt�^�_�F�C\n", this_object());
        set_stat_current("hp", query_stat_maximum("hp"));
        set_stat_current("ap", query_stat_maximum("hp"));
        set_stat_current("mp", query_stat_maximum("hp"));
    }
    return;
}
void create()
{
    set_name("��O�n", ({ "hu li song", "hu", "song" }) );
    set_level(45);
    set_race("human");
    set("age", 42);
    set("title",YEL"�F�ްƭ�"NOR);

    set("nickname",HIW"���"NOR);
    set("camp", "sand_bandit");
    set("long", "�Y�v�V���@���զ�A��⮳�۪��{�{����N�M�A�k���@�D���Y������\n"
                "�y�U���M�ͬݰ_�ӤQ�����ơA�����F���̪�����C\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: do_heal :),
    }));
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":49, "amount":1, "p1":6, "p2":100 ]),       // �s�M
        ([ "type":"wp", "id":27, "amount":1, "p1":1, "p2":100 ]),       // ��N�M
        ([ "type":"wp", "id":29, "amount":1, "p1":1, "p2":1200 ]),      // �ժ�
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
    msg = "\n\n"HIW+this_object()->query("name")+"���D�G�j���I�F�ު��S�̡̭I�A���F�I\n"NOR;
    msg += HIR"\n"HIR"�i���|�s�D�j"+this_object()->query("name")+"("+this_object()->query("id")+")����"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")����F�I\n\n"NOR;

    killer->add("exchange", 1);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A������O�n��o�F 1 �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}