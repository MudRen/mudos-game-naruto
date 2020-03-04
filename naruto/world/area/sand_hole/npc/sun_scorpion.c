#include <npc.h>
#include <ansi.h>

void do_fight()
{
    int damage, i, raiseDamage, exact, evade;
    object enemy;
    object *targets;
    mapping cnd = ([]);

    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();

    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->exact(this_object(), enemy, 1) + COMBAT_D->intimidate(this_object(), 1);

    if( enemy->query_condition("scorpion_poison") ) {
        message_vision("\n$N"YEL"���W���ȴߺ����o�X���~�٭nģ�������~�A�X�G���H�L�k����...\n"NOR, this_object(), enemy);

        for(i=0;i<sizeof(targets);i++) {
            if( i > 3 ) break;   // �̦h�����|�H
            evade = COMBAT_D->evade(targets[i], this_object(), 1)*2;

            if( !COMBAT_D->SkillHit(this_object(), targets[i], exact, evade) ) {
                message_vision("�@�}�������u"HIR"�Ӷ��g�u"NOR"�v�Q�V$n�A���O�S��...\n", this_object(), targets[i]);
            } else {
                damage = 800;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 300 ) damage = 200 + random(100);

                targets[i]->receive_damage(damage, this_object());
                message_vision( sprintf("�������u"HIR"�Ӷ��g�u"NOR"�v��a�Ӧb$n�����W�A�����N$n�N���ǹФF(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), this_object(), targets[i]);
            }
        }
        message_vision("\n", this_object());
        this_object()->start_busy(2);
    } else {
        message_vision("\n$N"HIM"�N�������$n�A���M���F�L�Ӭ������@���I\n"NOR, this_object(), enemy);
        if( random(500) < random(300) ) {
            message_vision("���O�ȧ��u�O�뤤�F$N����A�A�èS���˨�$N�C\n\n", enemy, this_object());
            this_object()->start_busy(1);
            return;
        }
        enemy->damage_stat("hp", damage, this_object());
        message_vision("$N����@�n�A�Ȭr�C�C���y�i$N���餺�A��$N�h�W�����C\n\n", enemy, this_object());
        enemy->start_busy(1);

        cnd["name"] = MAG+"�Ȭr"+NOR;
        cnd["duration"] = 10;
        cnd["from"] = this_object();

        enemy->set_condition("scorpion_poison", cnd);
    }
    return;
}

void create()
{
    set_name(HIY"�Ӷ�����"NOR, ({ "sun scorpion", "scorpion" }) );
    set_level(60);
    set_race("beast");
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("age", 5001);
    set("title",HIR"�I�Ϊ����ݤ��D"NOR);
    set("limbs", ({ "���Y", "���g", "�ȧ�", "�{�l", "�Ȩ�", "�Ӷ��Z", "�{��" }) );
    set("long", "�j�N���ݤ����u�@�̡A�]�����ݪ��l���ɭP�ȮɳB���v���A�A�~�|\n"
                "���F����ڤF�o�̡C�Ȥl���W���ȴߵo�X���p�Ӷ���ģ�������~�A��\n"
                "�O���g�o�S�O���H�`�Ȫ�����A�֩w�D�`���r�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":110, "amount":1, "p1":1, "p2":100 ]),             // �r�����g
        ([ "type":"eq", "id":112, "amount":1, "p1":5, "p2":100 ]),             // �j�N�Y��
        ([ "type":"obj", "id":113, "amount":2+random(5), "p1":80, "p2":100 ]), // �r�Ȧ�M
    }) );
    setup();
    add_temp("apply/armor", 200);
    add_temp("apply/attack", 50);
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 2 + random(2);

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
    msg = "\n\n\t"+this_object()->query("name")+HIR"�N�ݦs���ͩR�Ƭ��P��A�����N�j�a��ģ���թ]\n\n"NOR;
    msg += HIR"\t\t�u��"NOR+HIW+enemy->query("name")+NOR+HIR"�S�Q�o���~�ҷӫG...\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A�����Ӷ�������o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}