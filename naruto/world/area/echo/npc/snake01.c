#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void create()
{
    set_name("�D�u", ({ "snake so", "so" }) );
    set_level(26);
    set_race("human");
    set("gender", "male");
    set("age", 25);
    set("limbs", ({ "�D�Y", "�D��", "����", "�ݤf", "�}��", "�ӻH", "�y��" }) );
    set("title",HIG"�D�ھԤh"NOR);
    set("long", "�Y�W���F�@���j�׽F���D�H�A�����b�o�@�ʤ]���ʡC\n");
    set("guard_exit", ({ "north" })); // �u�ۥX�f
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":150 ]),     // �D������
        ([ "type":"food", "id":29, "amount":1, "p1":35, "p2":100 ]),  // �D�J
        ([ "type":"food", "id":30, "amount":1, "p1":25, "p2":100 ]),  // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":25, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":20, "p2":100 ]),    // �D��
    }) );
    setup();
    set_temp("apply/attack", 100);
    carry_object("/world/area/thorn_pine/npc/wp/thorn_blade")->wield("righthand");
}
int do_guard_exit(int x, int y, string exit)
{
    message_vision("$n���X��צ�$N���h���C\n", this_player(), this_object());
    do_chat((: command, "say �W���O�����~���¡A�A�o�~�H�u�@��h�C":));
    return 1;
}
void init()
{
    if( this_object() == this_player() ) return;

    // �Y this_player() �ݤ����o�ӤH���A�h���޵o�԰��C
    if( !this_object()->visible(this_player()) ) return;

    // �ϰ�]�w
    if( environment()->is_area() && !area_environment(this_object(), this_player()) ) return;

    // �Y���西���ۤ������A�}�l�԰��C
    if( this_player()->is_killing(query("id")) ) {
        COMBAT_D->auto_fight(this_player(), this_object(), "hatred");
        return;
    }
    if( is_killing(this_player()->query("id")) ) {
        COMBAT_D->auto_fight(this_object(), this_player(), "hatred");
        return;
    }
    // �ݨ�ѱi�k��K�}��
    if( this_player()->id("_HELP_GIRL_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N�@����$n�K�j�n�۵ۡG�u�����~�]�F�I�֥h��^�ӡI�v\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
