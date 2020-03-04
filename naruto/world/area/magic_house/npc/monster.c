#include <ansi.h>
#include <npc.h>

void do_exit()
{
    mapping ward, war_data;
    string file, war;
    object room, *inv;
    int ntar;

    file = "/world/area/magic_house/house.c";
    room = load_object(file);
    inv = all_inventory(room);
    ward = WAR_D->getController();
    delete_temp("close_war");

    if( random(100) == 50 ) {
        foreach(war, war_data in ward) {
            if( war == "/world/war/magic_house.c" && war_data["start"] != 0 ) {
                // �䤣�쪱�a�N�i�H�� war ���F
                for(ntar=0;ntar<sizeof(inv);ntar++) {
                    if( userp(inv[ntar]) ) {
                        set_temp("close_war", 1);
                        break;
                    }
                    if( inv[ntar]->query("sktree") ) continue;
                }
                if( !query_temp("close_war") ) WAR_D->doEndWar(this_object(), "/world/war/magic_house.c");
            }
        }
    }
    if( environment(this_object())->query("MONSTER_WAR") == 1 ) {
        do_chat((: random_move :));
    } else {
        message_vision("$N�Q���Ӫ��p����^Ţ�l�̥h�F...\n"NOR, this_object());
        destruct(this_object());
    }
    return;
}
void create()
{
    set_name("�����γ��~", ({ "monster" }));
    set_level(28+random(6));
    set_race("beast");
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("set_drop", ({
        ([ "type":"food", "id":15, "amount":1, "p1":10, "p2":100 ]), // ��O�Y
        ([ "type":"food", "id":17, "amount":1, "p1":10, "p2":100 ]), // ��O�Y
        ([ "type":"food", "id":19, "amount":1, "p1":10, "p2":100 ]), // �]�O�Y
        ([ "type":"eq", "id":108, "amount":1, "p1":1, "p2":400 ]),   // �]�N����
    }) );
    // �H������
    set("chat_chance", 10);
    set("chat_msg", ({
        (: do_exit :),
    }));
    set("sktree", random(5)+1);

    setup();
    switch( query("sktree") ) {
        case 1:
            set_name(HIW"����"NOR, ({ "sheep chicken", "sheep", "chicken" }));
            set("limbs", ({ "���Y", "����", "����", "���L", "����", "�Ϩ�", "���a" }) );
            set("long", "�S���ϤS�������_�ǥͪ��A�ʮ�Q�����z�C\n");
            break;
        case 2:
            set_name(HIC"���x"NOR, ({ "kea" }));
            set("limbs", ({ "�Y��", "����", "����", "�}��", "����", "�ͻH" }) );
            set("long", "�Q�����Ӯg�ɰ{ģ�ۦ��p������G�����x�M�C\n");
            break;
        case 3:
            set_name(HIR"�_�Q"NOR, ({ "kilin" }));
            set("limbs", ({ "�s�Y", "����", "����", "����", "�\��", "���a" }) );
            set("long", "���������⪺�r�~�A�]���߭��_�̤S�������~�Q��ӱo�W�C\n");
            break;
        case 4:
            set_name(HIB"�P��"NOR, ({ "wind bird", "bird" }));
            set("limbs", ({ "�Y��", "����", "����", "�}��", "����", "�ͻH" }) );
            set("long", "�ͪ��b�s�P���W���Ŧ�j���A�ʮ���r�㦳�j�P�����ʡC\n");
            break;
        case 5:
            set_name(HIK"����"NOR, ({ "pupa" }));
            set("limbs", ({ "����", "����", "����", "����", "����", "Ĳ��" }) );
            set("long", "�Y�إͪ������A�]�����פѼĦӳv���i�Ʀ����]�i�H���ʡC\n");
            break;
    }
    // �W�j
    add_temp("apply/attack", 60);
    add_temp("apply/armor", 30);
    add_temp("apply/exact", 10);
    add_temp("apply/evade", 10);
    add_temp("apply/intimidate", 5);
    add_temp("apply/wittiness", 5);
    add_temp("apply/int", 5);
    add_temp("apply/con", 5);
    add_temp("apply/str", 5);
    add_temp("apply/dex", 5);
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

    // �D���a���ΥD�ʧ���
    if( !userp(this_player()) ) return;

    switch( random(3) ) {
        case 0: msg = ""HIR"$N"HIR"���ʤj�o�A�@�ݨ�$n�ߨ輳�F�W�ӡI"NOR"\n\n"; break;
        case 1: msg = ""HIR"$N"HIR"�ǥs�@�n�i���R�������W�e�ӡI"NOR"\n\n"; break;
        case 2: msg = ""HIR"$N"HIR"�C�n�q�s�r�a�@�ӽĨ뼳�V$n�I"NOR"\n\n"; break;
    }
    for(i=0;i<sizeof(inv);i++) {
        if( inv[i] == this_object() ) continue;
        if( !userp(inv[i]) ) continue;
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
            // �b�����������p�U�A���Ť��� 28 �ŴN������
            if( inv[i]->query_level() < 28 ) continue;
            message_vision(msg, this_object(), inv[i]);
            this_object()->kill_ob(inv[i]);
            if( function_exists("accept_kill", inv[i]) && !inv[i]->is_killing(this_object()) && inv[i]->accept_kill(this_object()) ) continue;
            if( !inv[i]->is_killing(this_object()) ) inv[i]->kill_ob(this_object());
        }
    }
    return;
}
void die()
{
    string file;
    object enemy, room, *inv;
    int i, j, ntar;

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
    file = "/world/area/magic_house/house.c";
    room = load_object(file);
    inv = all_inventory(room);
    delete_temp("close_war");

    for(ntar=0;ntar<sizeof(inv);ntar++) {
        if( inv[ntar]->query("verbs") && inv[ntar]->query("sktree") ) {
            add_temp("close_war", 1);
            if( query_temp("close_war") > 2 ) break;
        } else continue;
    }
    // �������S�o�{�ʪ��N�� war
    if( query_temp("close_war") < 2 ) WAR_D->doEndWar(this_object(), "/world/war/magic_house.c");

    i = random(this_object()->query_level())*2 + 100;
    j = i*2 + random(500);

    if( enemy->query("bank") > 1000000 && enemy->query_point("learn") < 500000 ) {
        enemy->add("bank", -j);
        tell_object(enemy, HIY"\n�]������"NOR+this_object()->query("name")+HIY"�����αq�A�Ȧ�̮����F"HIR"["+chinese_number(j)+"]"HIY"����v���B�B�~��o�F"HIG"["HIC+chinese_number(i)+HIG"]"HIY"�I���I�C\n\n"NOR);
    } else if( enemy->query_point("learn") < 500000 ) {
        tell_object(enemy,HIY"\n�]������"NOR+this_object()->query("name")+HIY"�A�B�~��o�F"HIG"["HIC+chinese_number(i)+HIG"]"HIY"�I���I�C\n\n"NOR);
    }
    enemy->add_point("learn", i);
    ::die();
    return;
}
