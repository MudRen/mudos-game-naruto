#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void create()
{
    if( random(2) == 1) {
        set_name("�D�H", ({ "snake man", "man" }) );
        set("gender", "male");
    } else {
        set_name("�D�k", ({ "snake woman", "woman" }) );
        set("gender", "female");
    }
    set_level(24+random(2));
    set_race("human");
    set("age", 10+random(51));
    set("limbs", ({ "�D�Y", "�D��", "����", "�ݤf", "�}��", "�ӻH", "�y��" }) );
    set("title",HIG"���q���"NOR);
    set("long", "�~��p�P�D��A�o�ΨⰦ�}�������D�H�A���G��b�o�̡C\n");
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        (: command, "say �i�c���H���I" :),
        (: command, "say �D�ڤ~�O�̰��j���رڡI" :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":400 ]),     // �D������
        ([ "type":"food", "id":29, "amount":1, "p1":25, "p2":100 ]),  // �D�J
        ([ "type":"food", "id":30, "amount":1, "p1":15, "p2":100 ]),  // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":15, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":10, "p2":100 ]),    // �D��
          ([ "type":"obj", "id":88, "amount":1, "p1":1, "p2":800 ]),  // �_�q���ѱ���
    }) );
    setup();
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

    // �ݨ�ѱi�k��K�}��
    if( this_player()->id("_HELP_GIRL_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N�@����$n�K�j�n�۵ۡG�u�����~�]�F�I�֥h��^�ӡI�v\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
    /* �D���a���ΧP�_ */
    if( !userp(this_player()) ) return;

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
            switch( query("attitude") ) {
                case "aggressive":
                /* �D�ʧ������ͪ� */
                COMBAT_D->auto_fight(this_object(), inv[i], "aggressive");
                break;
            }
        }
    }
}
