#include <ansi.h>
#include <npc.h>

inherit F_SEASOLDIER;

void do_fight()
{
    int damage, raiseDamage;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("\n$N�Τ⤤���K�M�q�����a���״�$n�ΤO�@���I\n", this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("$n���W�Φۤv���L�b�[�}$N�������C\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    damage = 250;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
    add_temp("apply/attack", -raiseDamage);

    if( damage < 50 ) damage = 20 + random(30);

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->damage_stat("hp", damage, this_object());
    message_vision( sprintf("�u��v�a�@�n�A$n�Q�K�M��ˡA�d�U�F�@�D�`�`���ˤf(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}
void create()
{
    set_name("���x�j�L", ({ "officer" }) );
    set_race("human");
    set_level(32);
    set("title",HIB"����"NOR);
    set("gender", "male");
    set("class","officer_sea");
    set("camp", "police");
    set("age", 10+random(71));
    set("long", "���G�O�o����ĥ��ĥ���A���M�ߦa�ݵۮ��ϩM���ҫ����Ƥ�C\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say �ݲM����i��V�I" :),
        (: command, "say ����T�Q�סI" :),
        (: command, "say �k����I�`�N�e����y�I" :),
        (: command, "say �Ʃx�I�s���L�̻{�u�޽m�A�ګ��ť����޽m���n���I" :),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":1, "p1":40, "p2":100 ]),    // ����
        ([ "type":"eq", "id":97, "amount":1, "p1":10, "p2":100 ]),     // ���x�u�S���m
        ([ "type":"eq", "id":95, "amount":1, "p1":1, "p2":300 ]),      // ���x�U
    }) );
    setup();
    carry_object(_DIR_AREA_"thorn_pine/npc/wp/iron_blade.c")->wield();
}