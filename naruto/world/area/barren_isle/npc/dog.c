#include <ansi.h>
#include <npc.h>

void do_check()
{
    object ob, me;
    me = this_object();
    ob = present("_CORSAIR_", environment(me));

    if( !ob ) {
        message_vision("\n$N�]���䤣��D�H�A���L���]�F�C\n"NOR, me);
        destruct(me);
        return;
    }
}
void create()
{
    set_name("��", ({ "animal", "_ANIMAL_" }) );
    set_race("beast");
    set_level(20);
    set("long", "�r�~�ϩҾi���d���A�ݰ_�ӫ­������C\n");
    set("limbs", ({ "�~�Y", "����", "����", "�~�L", "����" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 100);
    set("chat_msg", ({
        (: do_check :),
    }) );
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: command, "dog" :),
    }) );
    setup();
}
void unconcious()
{
    this_object()->die();
    return;
}
void die()
{
    message_vision("\n$N���G�P��`�ȡA��W�a�]���F�C\n"NOR, this_object());
    destruct(this_object());
    return;
}
