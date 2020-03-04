#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

void do_exit()
{
    if( environment(this_object())->query("SAND_WAR") == 1 ) {
        do_chat((: random_move :));
    } else {
        message_vision("$N����F�F�ަ^�l���R�O�A�}�l�M�h�F�C\n"NOR, this_object());
        destruct(this_object());
    }
    return;
}
void do_fight()
{
    int damage;
    object enemy, exact, evade;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->evade(this_object(), enemy, 1);
    evade = COMBAT_D->evade(enemy, this_object(), 1);

    message_vision("\n$N�N���M���|�A�j�ۤ@�n�u"YEL"�����}�l�I"NOR"�v�ֳt���ĦV$n�I\n"NOR,this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("���O$n���l�@�{�׶}�F�����A$N�������L�k���_�A�����D�Ĩ���̥h�F...\n\n"NOR, this_object(), enemy);
        do_chat((: random_move :));
        this_object()->start_busy(1);
        return;
    }
    damage = COMBAT_D->isDamage(this_object(), enemy, this_object()->query_temp("weapon/righthand"));

    if( damage < 70 ) damage = 50 + random(20);
    else damage += 100;

    // �ˮ`�ާl��
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->damage_stat("hp", damage, this_object());
    message_vision( sprintf("$N�Ĩ�$n���e�ɺL�F�@���I���M���n���L$n�����l�A��$N�u�����h�F...(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    do_chat((: random_move :));
    enemy->start_busy(2);
    return;
}
void create()
{
    set_name("�j�s", ({ "robber" }) );
    set_level(30);
    set_race("human");
    if( random(2) == 1) {
        set("gender", "male");
    } else {
        set("gender", "female");
    }
    set("chat_chance", 20);
    set("chat_msg", ({
        (: do_exit :),
    }));
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("age", 15+random(41));
    set("title",YEL"�a�U�F��"NOR);
    set("long", "�@�y�������ҼˡA��W���ۤ@��ծ̮̪����M�C\n");
    set("set_drop", ({
        ([ "type":"wp", "id":33, "amount":1, "p1":10, "p2":100 ]),                  // �j���
        ([ "type":"wp", "id":41, "amount":1, "p1":10, "p2":100 ]),                  // ���M
        ([ "type":"wp", "id":35, "amount":1, "p1":10, "p2":100 ]),                  // �K��
        ([ "type":"obj", "id":29, "amount":10 + random(1000), "p1":80, "p2":100 ]), // �Ȥl
        ([ "type":"obj", "id":28, "amount":1, "p1":20, "p2":100 ]),                 // ����
    }) );
    setup();
    carry_object(__DIR__"wp/long_blade.c")->wield("righthand");
    add_temp("apply/armor", 200);
    add_temp("apply/evade", 100);
    add_temp("apply/attack", -50);
}
void init()
{
    string msg;
    int i;
    object *inv;
    inv = all_inventory(environment(this_object()));

    /* �Y this_player() �ݤ����o�ӤH���A�h���޵o�԰��C */
    if( !this_object()->visible(this_player()) ) return;

    /* �W�[area�P�_ add by -Acme- */
    if( environment()->is_area() && !area_environment(this_object(), this_player())) return;

    switch(random(4)) {
        case 0: msg = ""HIR"$N"HIR"���D�G�ΦϥX�{�F�I���̶]�I"NOR"\n\n"; break;
        case 1: msg = ""HIR"$N"HIR"�z�z�j�s�G�d�U�R���]�I�u���ջȼ˼˨ӡI"NOR"\n\n"; break;
        case 2: msg = ""HIR"$N"HIR"���R���񪺧��$n�I"NOR"\n\n"; break;
        case 3: msg = ""HIR"$N"HIR"�ܹD�G�Ĩħ����X�ӡI"NOR"\n\n"; break;
    }
    for(i=0;i<sizeof(inv);i++) {
        if( inv[i] == this_object() ) continue;
        if( !this_object()->visible(inv[i]) ) continue;
        if( environment()->is_area() && !area_environment(this_object(), inv[i])) continue;
        if( this_object()->is_fighting(inv[i]) ) continue;
        if( living(inv[i]) ) {
            if( inv[i]->is_corpse() ) continue;

            // �Y���西���ۤ������A�}�l�԰��C
            if( inv[i]->is_killing(query("id")) ) {
                COMBAT_D->auto_fight(inv[i], this_object(), "hatred");
                continue;
            }
            if( is_killing(inv[i]->query("id")) ) {
                COMBAT_D->auto_fight(this_object(), inv[i], "hatred");
                continue;
            }
            // �D���a���ΥD�ʧ���
            if( !userp(inv[i]) ) continue;
            if( query("level_kill") > inv[i]->query_level() ) continue;
            message_vision(msg, this_object(), inv[i]);
            this_object()->set_leader(inv[i]);
            this_object()->kill_ob(inv[i]);
            if( function_exists("accept_kill", inv[i]) && !inv[i]->is_killing(this_object()) && inv[i]->accept_kill(this_object()) ) continue;
            if( !inv[i]->is_killing(this_object()) ) inv[i]->kill_ob(this_object());
        }
    }
    return;
}