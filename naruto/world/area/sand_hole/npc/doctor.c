#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

string *name1 = ({ "�¥j�O", "���J", "���S�w", "�B�\\�{", "���{", "�ѳt�ߥ���",
                   "����", "���\\", "�q��", "�ռw", "�K�Q�d", "�y��", "���i��", });

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
    if( this_object()->query_stat("hp") < query_stat_maximum("hp")/2 ) {
        message_vision("$N"HIW"�κ�諸��k���ۤv���ˡA�u��$N���W���ˤf�ֳt�^�_��...\n"NOR, this_object());
        this_object()->heal_stat("hp", query_stat_maximum("hp")/5);
        this_object()->heal_stat("ap", query_stat_maximum("ap")/5);
        this_object()->heal_stat("mp", query_stat_maximum("mp")/5);
        this_object()->start_busy(1);
    }
    return;
}
void create()
{
    set_name(name1[random(sizeof(name1))], ({ "doctor" }) );
    set_level(40);
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
    set("title",YEL"�F�ޱK��"NOR);
    set("long", "�y�W�a�ۤf�n�A�Y�W�a�ۤ�N�Ϊ��U�l�A�ݰ_�ӹ����̪��~����͡C\n");
    set("set_drop", ({
        ([ "type":"wp", "id":27, "amount":1, "p1":1, "p2":300 ]),       // ��N�M
        ([ "type":"eq", "id":111, "amount":1, "p1":1, "p2":300 ]),      // �°��O
        ([ "type":"eq", "id":36, "amount":1, "p1":1, "p2":150 ]),       // ���\
        ([ "type":"obj", "id":58, "amount":1, "p1":10, "p2":100 ]),     // �믫���
        ([ "type":"obj", "id":65, "amount":1, "p1":10, "p2":100 ]),     // ��O���
        ([ "type":"obj", "id":66, "amount":1, "p1":10, "p2":100 ]),     // ���d���
    }) );
    setup();
    carry_object("/world/wp/scalpel.c")->wield("righthand");
    add_temp("apply/evade", 200);
}
void die()
{
    object enemy, room, killer;
    int i;

    enemy = this_object()->last_damage_giver();
    room = load_object(query("SAND_KILL"));
    i = random(2);

    if( !enemy ) {
        room->delete("SAND_HOLE");
        ::die();
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            room->delete("SAND_HOLE");
            ::die();
            return;
        } else
        if( environment(enemy) != environment(this_object()) ) {
            room->delete("SAND_HOLE");
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
    killer->add("exchange", i);
    message("system", "\n\n"HIW+this_object()->query("name")+"���D�G"+enemy->query("name")+"�o�å�U��Ӭ��F�I�S�ֺ̧̭M�h���I\n\n"NOR, users());
    if( i != 0 ) tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    WAR_D->doEndWar(this_object(), "/world/war/sand_hole.c");
    ::die();
    return;
}
