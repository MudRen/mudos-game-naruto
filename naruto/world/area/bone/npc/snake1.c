#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void do_fight()
{
    int damage, raiseDamage, exact, evade;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_temp("quest/snake_blade") == 1) return;

    exact = COMBAT_D->intimidate(this_object(), 1)*2;
    evade = COMBAT_D->wittiness(enemy, 1);

    this_object()->damage_stat("mp", 1, this_object());
    message_vision("\n$N"HIG"�����s�M�¦a�W�@���A���_�a�W��֥۶�����"NOR"$n"HIG"�C\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n�N�۶���ֳq�q���}�A���@�����v�T�~�����$N�C\n\n", this_object(), enemy);
        return;
    }
    raiseDamage = 50;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);

    enemy->receive_damage(damage, this_object());
    this_object()->add_temp("quest/snake_blade", 1);
    message_vision( sprintf("�۶�����$n�⦣�}�áA���֦a�賣�Q�{��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    call_out("blade_1", 5, this_object());
    return;
}

void blade_1(object me)
{
    int damage, raiseDamage, exact, evade;
    object enemy;

    enemy = me->query_opponent();

    me->delete_temp("quest/snake_blade");

    if( !enemy ) return;
    if( environment(me)->is_area() ) {
        if( !area_environment(me, enemy) ) return;
    } else {
        if( environment(enemy) != environment(me) ) return;
    }
    if( !me->is_fighting(enemy) ) return;

    exact = COMBAT_D->intimidate(this_object(), 1);
    evade = COMBAT_D->wittiness(enemy, 1);

    me->damage_stat("mp", 15, me);
    message_vision("\n$N"HIY"�q���_���۶���֤����եѤU�ӤW��$n���n�`�A�X�@�O���ۡI\n"NOR, me, enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("���O$n�o���w�g�o�{�F$N�����ϡA���P�a�N$N��������}�F�C\n\n"NOR, me, enemy);
        return;
    }
    raiseDamage = 450;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(me, enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 150 ) damage = 100 + random(50);

    enemy->receive_damage(damage, me);
    message_vision( sprintf("$n�̵M�k���L$N�������A���o���o�O�Q�s�M�A���ݽ��A�y���Y�������(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
    return;
}

void create()
{
    set_name("�ԳD", ({ "warrior snake", "snake" }) );
    set_race("human");
    set("gender", "male");
    set_level(33+random(3));
    set("age", 15+random(21));
    set("limbs", ({ "�D�Y", "�D��", "����", "�ݤf", "�}��", "�ӻH", "�y��" }) );
    set("title",HIG"�D�ھԤh"NOR);
    set("long", "����s�M�A���ۤ@�`��μC�ު��D�H�C\n");
    set("camp", "snaker");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: command, "say ���I���d���f�I" :),
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":100 ]),     // �D������
        ([ "type":"wp", "id":49, "amount":1, "p1":1, "p2":300 ]),     // �s�M
        ([ "type":"wp", "id":48, "amount":1, "p1":1, "p2":275 ]),     // �޼C
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // �D��
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // �D�r
    }) );
    setup();
}