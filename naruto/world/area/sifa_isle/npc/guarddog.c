#include <ansi.h>
#include <npc.h>

inherit F_SEASOLDIER;

void do_fight()
{
    object ob, enemy, me;

    me = this_object();
    enemy = me->query_opponent();

    // �S���ĤH
    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(me)->is_area() ) {
        if( !area_environment(me, enemy) ) return;
    } else {
        if( environment(enemy) != environment(me) ) return;
    }
    // �䤣�쪯���R�O
    if( ob = present("_SIFA_DOG_", environment(me)) ) {

        // �p�G���w�g�b�����ĤH�N���R�O
        if( ob->is_fighting(enemy) ) return;

        message_vision("\n$N�j�۵ۡG"HIG"�W��"+ob->query("name")+"�I�h�r"+enemy->query("name")+"�I\n"NOR, me);
        ob->kill_ob(enemy);
        enemy->kill_ob(ob);
        return;
    }
    return;
}
void do_clone()
{
    object mob;
    int x, y;

    x = this_object()->query("area_info/x_axis");
    y = this_object()->query("area_info/y_axis");
    mob = new(__DIR__"dog.c");

    if( this_object()->query_temp("dog_clone") != 1 ) {
        message_vision("$N"HIY"���X�~�çj�F�X�n�A�q����]�X�@���q�k���C\n"NOR, this_object());
        if( environment(this_object())->is_area() ) {
            if( area_move(environment(this_object()), mob, x, y) ) {
                mob->guard_ob(this_object());
                mob->set_leader(this_object());
                this_object()->guard_ob(mob);
                this_object()->set_temp("dog_clone", 1);
                return;
            }
            message_vision("���O�äl�n���a���F�A�j���X�n���C\n", this_object());
            do_chat((: random_move :));
            return;
        }
        message_vision("���O�o�̬O�ж��A�n���Ǥ��X�h�C\n", this_object());
        do_chat((: random_move :));
        return;
    }
    do_chat((: random_move :));
}
void create()
{
    set_name("�u��", ({ "guard", "_GUARD_" }) );
    set_race("human");
    set_level(30);
    set("title",HIC"�q�k�q"NOR);
    set("nickname",HIR"�k������"NOR);
    set("class", "guard_sea");
    set("camp", "police");
    set("age", 10+random(71));
    set("long", "�M�ۥq�k�q�j���������S�ؤh�L�A�Q�Τ�W�ұa���Q���i������C\n");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: do_clone :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":100, "amount":1, "p1":60, "p2":100 ]),              // �u��
        ([ "type":"obj", "id":102, "amount":1, "p1":40, "p2":100 ]),              // ��÷
        ([ "type":"wp", "id":38, "amount":1, "p1":20, "p2":100 ]),                // �����K��
        ([ "type":"wp", "id":35, "amount":1, "p1":50, "p2":100 ]),                // �K��
    }) );
    setup();
    carry_object(_DIR_AREA_"wild/npc/wp/wolf_claw.c")->wield();
    carry_object(_DIR_AREA_"wild/npc/wp/wolf_claw.c")->wield("lefthand");
}
