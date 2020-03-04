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
    set_level(20+random(6));
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
        message_vision(HIR"$N�@����$n�K�j�n�۵ۡG�u�����~�]�F�I�֥h��^�ӡI�v\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
