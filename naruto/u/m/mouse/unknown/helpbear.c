#include <npc.h>
#include <ansi.h>

object query_helper()
{
    if( objectp(query("helper")) ) return query("helper");
    else return 0;
}
void create()
{
    set_name("������", ({ "baby fox bear", "bear", "_HELP_BEAR_" }) );
    set_race("beast");
    set_level(5);
    set("long", "���p�������A�ݰ_�ӫܥi�R�C\n");
    set("title","�Q�쪺");
    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say ���������" :),
        CYN"��������㪺�s�ۡA�Ʊ榳�H��u�f�ϡv�e�C\n"NOR,
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "�f��" && !query("helper") )  {
        do_chat( ({ 
            (: command, "lick " + this_player()->query("id") :),
            (: command, "follow " + this_player()->query("id") :),
            (: command, "guard " + this_player()->query("id") :),
        }) );
        this_object()->set("helper", this_player());
        this_player()->add_temp("quest/helpbear", 1);
        return;
    }
}
void die()
{
    object helper;
    message_vision(HIR"\n$N�u�ȡv�F�@�n�C�C�˦V�@�Ǧ��h�F�C"NOR, this_object(), this_player());
    if( objectp(helper = query_helper()) ) helper->delete_temp("quest/helpbear");
    ::die();
}
