#include <npc.h>
#include <ansi.h>

void do_fight()
{
    message_vision("\n$N���X�y"CYN"���P"NOR"�z���L������b���ǵe�X�@�ӥ��j����Ρu"HIC"���پ�"NOR"�v\n", this_object());
    message_vision("���O$N�¤�¸}���A��e���n�C��K�A�@�I�ĪG�]�S���C\n\n"NOR, this_object());
    this_object()->start_busy(1);
    return;
}
void create()
{
    set_name("����", ({ "water ninja", "ninja" }));
    set_race("human");
    set_level(10);
    set("age", 16);
    set("nickname",HIC"�B���Ԫ�"NOR);
    set("gender","female");
    set("long", "�B�����Ԫ̡A�o�����D�����]���b�o���Τl�̡C\n");
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
}
