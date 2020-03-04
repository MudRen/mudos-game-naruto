#include <npc.h>
#include <ansi.h>
#include "wp.h"

void do_fight()
{
    if( query_ability("attack") > query_ability("defend")) {
        message_vision(HIW"\n$N�N�Z�����|��F�X�y�g�y�A���⴫�C�k�⴫�ޡA�ե�Ţ�n$N�N�𨾤��դF�C\n\n"NOR, this_object());
        add_temp("apply/attack", -300);
        add_temp("apply/armor", 300);
    } else {
        message_vision(HIW"\n$N�N�Z�����|��F�X�y�g�y�A���⴫�ޥk�⴫�C�A�ե�Ţ�n$N�N�𨾤��դF�C\n\n"NOR, this_object());
        add_temp("apply/attack", 300);
        add_temp("apply/armor", -300);
    }
    return;
}
void create()
{
    set_name("�g�ۤk�C�h", ({ "aborigines sworder", "sworder" }) );
    set_level(50);
    set_race("human");
    set("gender", "female");
    set("attitude", "aggressive");
    set("wp_number", 1);
    set("age", 15+random(41));
    set("nickname",HIY"���Y"NOR);
    set("long", "����b�n�����ҡA�Y�W���ۤg�۳��������@�w�����a��~��t�a����\n"
                "��G����A�I�W�I�ۤ@�`�X�G�s���`�k�ʳ��L�k���P�|�_���e�C�A��\n"
                "�o�۫­��P�W�Z����աA�o�N�O�g�ۤk�C�h�C\n");
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    add_temp("apply/hp", random(150));
    carry_object(_DIR_AREA_"thorn_pine/npc/wp/spiral_sword.c")->wield("righthand");
    call_out("die_1", 120+random(240), this_object());
    do_heal();
}

void die_1()
{
    message_vision(GRN"$N�ݤF�@�ݥ|�P�A�S���^�O�L���F�C\n"NOR, this_object());
    destruct(this_object());
    return;
}
