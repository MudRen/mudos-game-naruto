#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�s�T", ({ "hill wolf", "wolf" }) );
    set_race("beast");
    set_level(15);
    set("age", 11+random(21));
    set("long", "�@���ݰ_�ӫܥ������s�T�A�ɱ`��Ѩg���C\n");
    set("limbs", ({ "�T�Y", "����", "����", "�T�L", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        CYN"�s�T�V�Ѩg���ۡu���㣹�㣱�㣹��v\n"NOR,
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":79, "amount":1, "p1":15, "p2":100 ]),    // �T��
        ([ "type":"food", "id":32, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"food", "id":33, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"eq", "id":57, "amount":1, "p1":20, "p2":100 ]),     // �T�}
        ([ "type":"eq", "id":58, "amount":1, "p1":18, "p2":100 ]),     // �T��
        ([ "type":"eq", "id":59, "amount":1, "p1":20, "p2":100 ]),     // �T�}
        ([ "type":"eq", "id":60, "amount":1, "p1":20, "p2":100 ]),     // �T�Y
        ([ "type":"eq", "id":61, "amount":1, "p1":25, "p2":100 ]),     // �T��
        ([ "type":"wp", "id":13, "amount":1, "p1":10, "p2":100 ]),     // �T��
    }) );
    setup();
}
void init()
{
    if( this_object() == this_player() ) return;

    // �Y this_player() �ݤ����o�ӤH���A�h���޵o�԰��C
    if( ! this_object()->visible(this_player()) ) return;

    // �ϰ�]�w
    if( environment()->is_area() && !area_environment(this_object(), this_player()) ) return;

    // �Y���西���ۤ������A�}�l�԰��C
    if( this_player()->is_killing(query("id")) ) {
        COMBAT_D->auto_fight(this_player(), this_object(), "hatred");
        return;
    }
    if( is_killing(this_player()->query("id")) )
    {
        COMBAT_D->auto_fight(this_object(), this_player(), "hatred");
        return;
    }
    switch( query("attitude") ) {
        case "aggressive":
            /* �D�ʧ������ͪ� */
            COMBAT_D->auto_fight(this_object(), this_player(), "aggressive");
            break;
        case "peaceful":
        default:
            break;
    }

    // �ݨ�ѱi�k��K�}��
    if( this_player()->id("_HELP_GIRL_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N�g���@�n�A�}�l����$n�F�I\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
