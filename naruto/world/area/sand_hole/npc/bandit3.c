#include <npc.h>
#include <ansi.h>
#include "enhance.h"

inherit F_FIGHTER;

void do_fight()
{
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
    message_vision("\n$N�k����M�f�t�����M�P�ɶi��u"HIY"���M�ñ�"NOR"�v�@�s��X�K�K���Q�|�M�I\n"NOR,this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("���O$n�w�g�ݯ}�F$N����աA���_�Z���[��F$N�A�N������������C\n\n"NOR, this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    damage = COMBAT_D->isDamage(this_object(), enemy, this_object()->query_temp("weapon/righthand"));

    if( damage < 150 ) damage = 100 + random(50);
    else damage += 150;

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->damage_stat("hp", damage, this_object());
    message_vision( sprintf("�u��$N�k����M��ꤣ���A�f�t�����M���_����$n�j�j�p�p���ˤf(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);

    damage = COMBAT_D->isDamage(this_object(), enemy, this_object()->query_temp("weapon/lefthand"));

    if( damage < 100 ) damage = 50 + random(25);
    else damage += 75;

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->damage_stat("hp", damage/2, this_object());
    message_vision( sprintf("�u��$N�����M��ղr�P�A�f�t�k����M���_����$n�j�j�p�p���ˤf(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    this_object()->start_busy(1);
    return;
}
void create()
{
    set_name("�s�űj�s", ({ "bandit" }) );
    set_level(40);
    set_race("human");
    if( random(2) == 1) {
        set("gender", "male");
    } else {
        set("gender", "female");
    }
    set("camp", "sand_bandit");
    set("age", 18+random(51));
    set("title",YEL"�a�U�F��"NOR);
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("long", "�a�۵R���U�l�A�⮳���M�A�W���s�����j�s�C���L�٬O�j�s�C\n");
    set("item_drop", "/world/area/sand_hole/npc/wp/long_blade.c");
    set("molecule", 5);            // ���l
    set("denominator", 100);       // ����
    set("set_drop", ({
        ([ "type":"wp", "id":34, "amount":1, "p1":10, "p2":100 ]),                 // �K�M
        ([ "type":"wp", "id":52, "amount":1, "p1":1, "p2":300 ]),                  // �}�H�b
        ([ "type":"obj", "id":29, "amount":10 + random(400), "p1":80, "p2":100 ]), // �Ȥl
        ([ "type":"eq", "id":31, "amount":1, "p1":20, "p2":100 ]),                 // �R���U
        ([ "type":"eq", "id":15, "amount":1, "p1":15, "p2":100 ]),                 // �ե��c
    }) );
    setup();
    carry_object("/world/eq/head/rhino.c")->wear();
    carry_object(__DIR__"wp/long_blade.c")->wield("righthand");
    carry_object("/world/wp/blade.c")->wield("lefthand");
    add_temp("apply/armor", 200);
    add_temp("apply/attack", 50);
}