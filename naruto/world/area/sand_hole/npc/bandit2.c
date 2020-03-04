#include <npc.h>
#include <ansi.h>
#include "enhance.h"

inherit F_FIGHTER;

void do_fight()
{
    int damage;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("\n$N�ɳܤ@�n�A�@��"HIC"�u��M���J�v"NOR"�µ�$n���n�`���X�r�O���@�M�I\n"NOR,this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("���O$n�w�g�ݯ}�F$N����աA���_�Z���[��F$N�A�N������������C\n\n"NOR, this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    this_object()->damage_stat("mp", 25, this_object());
    damage = COMBAT_D->isDamage(this_object(), enemy, this_object()->query_temp("weapon/righthand"));

    if( damage < 150 ) damage = 100 + random(50);
    else damage += 150;

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("$N�N��i$n�n�`�����M�ޤF�X�ӡA�A�平��u�몺�����Q�X(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    this_object()->start_busy(1);
    return;
}
void create()
{
    set_name("���űj�s", ({ "bandit" }) );
    set_level(35);
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
    set("long", "�a�ۦФ�U�l�A�⮳�۪��M�A�@�y�ªZ�A�ݰ_�ӤQ�����Ū��j�s�C\n");
    set("item_drop", "/world/area/sand_hole/npc/wp/long_blade.c");
    set("molecule", 1);            // ���l
    set("denominator", 100);       // ����
    set("set_drop", ({
        ([ "type":"wp", "id":34, "amount":1, "p1":8, "p2":100 ]),                  // �K�M
        ([ "type":"obj", "id":29, "amount":10 + random(400), "p1":80, "p2":100 ]), // �Ȥl
        ([ "type":"eq", "id":27, "amount":1, "p1":20, "p2":100 ]),                 // �Ф�U
        ([ "type":"eq", "id":15, "amount":1, "p1":6, "p2":100 ]),                  // �ե��c
    }) );
    setup();
    carry_object("/world/eq/head/plume.c")->wear();
    carry_object(__DIR__"wp/long_blade.c")->wield("righthand");
    add_temp("apply/armor", 150);
    add_temp("apply/attack", 50);
}