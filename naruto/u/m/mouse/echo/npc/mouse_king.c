#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIK"�a����"NOR, ({ "the king of mouse", "mouse", "king" }) );
    set_race("beast");
    set_level(21);
    set("title", "�a�a��");
    set("long", "�@���έD���s�~���W�D�a���A�P��L�a���۲��Ƥj�C\n");
    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("chat_chance", 5);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"food", "id":35, "amount":1, "p1":80, "p2":100 ]),   // ����
        ([ "type":"food", "id":36, "amount":1, "p1":80, "p2":100 ]),   // ���}
        ([ "type":"food", "id":37, "amount":1, "p1":80, "p2":100 ]),   // ����
        ([ "type":"food", "id":56, "amount":1, "p1":30, "p2":100 ]),   // ����
        ([ "type":"eq", "id":53, "amount":1, "p1":80, "p2":100 ]),     // ���Y
        ([ "type":"eq", "id":54, "amount":1, "p1":3, "p2":100 ]),      // �j�ɤ�
    }) );
    setup();
    set_skill("combat", 110);
    set_skill("dodge", 110);
    set_skill("parry", 110);
    set_skill("savage hit", 110);
    set_skill("heavy hit", 110);
    set_skill("continual hit", 110);
    set_temp("apply/attack", 20);
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
        message_vision(HIR"$N���M�s�s�s�F�_�ӡI�}�l����$n�F�I\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
