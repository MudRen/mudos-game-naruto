#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�s�T��", ({ "king of wolf", "wolf" }) );
    set_race("beast");
    set_level(25);
    set("age", 35);
    set("long", "�s�T�̪��T���A��s�X�D�`�x�G�����n�A�O�H�x�Ԥ���C\n");
    set("limbs", ({ "�T�Y", "����", "����", "�T�L", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        CYN"�s�T���o�X���̯몺�z�s�n�u���������v\n"NOR,
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":79, "amount":1, "p1":30, "p2":100 ]),    // �T��
        ([ "type":"food", "id":32, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"food", "id":33, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"eq", "id":57, "amount":1, "p1":20, "p2":100 ]),     // �T�}
        ([ "type":"eq", "id":58, "amount":1, "p1":18, "p2":100 ]),     // �T��
        ([ "type":"eq", "id":59, "amount":1, "p1":20, "p2":100 ]),     // �T�}
        ([ "type":"eq", "id":60, "amount":1, "p1":20, "p2":100 ]),     // �T�Y
        ([ "type":"eq", "id":61, "amount":1, "p1":25, "p2":100 ]),     // �T��
    }) );
    setup();
    carry_object("/world/area/wild/npc/wp/wolf_claw.c")->wield("righthand");
    carry_object("/world/area/wild/npc/wp/wolf_claw.c")->wield("lefthand");
}
void init()
{
    int i;
    object *inv;
    inv = all_inventory(environment(this_object()));

    /* �Y this_player() �ݤ����o�ӤH���A�h���޵o�԰��C */
    if( !this_object()->visible(this_player()) ) return;

    /* �W�[area�P�_ add by -Acme- */
    if( environment()->is_area() && !area_environment(this_object(), this_player())) return;

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
            // �ݨ�ѱi�k��K�}��
            if( inv[i]->id("_HELP_GIRL_") && !inv[i]->is_fighting(this_object()) ) {
                message_vision(HIR"$N�j�n���V���z�s�A�~�M��$n�o�ʧ����I\n\n"NOR, this_object(), inv[i]);

                this_object()->kill_ob(inv[i]);
                continue;
            }
            // �D���a���ΥD�ʧ���
            if( !userp(inv[i]) ) continue;

            switch( query("attitude") ) {
                case "aggressive":
                /* �D�ʧ������ͪ� */
                COMBAT_D->auto_fight(this_object(), inv[i], "aggressive");
                break;
            }
        }
    }
}
