#include <npc.h>
#include <ansi.h>

object query_helper()
{
    if( objectp(query("helper")) ) return query("helper");
    else return 0;
}
void create()
{
    set_name("�֤k", ({ "girl" }) );
    set_race("human");
    set("gender", "female");
    set("age", 15);
    set_level(15);
    set("long", "�@��~�����k�ʡA�Q�j�b���Y�W�A���W�e���F�_�Ǫ���r�C\n");
    set("title","�����~");
    set("chat_chance", 5);
    set("chat_msg", ({
        CYN"�֤k���l�L�L�o�ݡA�`�Ȫ������X�ܨӡC\n"NOR,
    }) );
    setup();
    set_temp("apply/attack", -100);
    set_temp("apply/armor", 50);
}
void relay_say(object ob, string arg)
{
    if( arg == "�ѱi" && !query("helper") ) {
        if( this_player()->query_temp("quest/help_girl") != 1) {
            message_vision(CYN"$N�`�Ȫ������X�ܨӡC\n"NOR, this_object());
            return;
        } else
        this_player()->add_temp("quest/help_girl", 1);
        do_chat( ({
            (: command, "wa" :),
            (: command, "say �����S���I�O�L�n�A�ӱϧڪ��ܡH" :),
        }) );
        return;
    }
    if( arg == "�O" || arg == "�ϧA" && !query("helper") ) {
        if( this_player()->query_temp("quest/help_girl") != 2) {
            message_vision(CYN"$N�`�Ȫ������X�ܨӡC\n"NOR, this_object());
            return;
        }
        this_object()->set("helper", this_player());
        this_player()->delete_temp("quest/help_girl");
        set_name("�ѱi���k��", ({ "daughter", "_HELP_GIRL_" }) );
        set("title",HIM"���h�^�a����"NOR);
        set("long", "�@��~�����k�ʡA���M���|�y�W�o�a�ۯ��e�C\n");
        set("chat_chance", 5);
        set("chat_msg", ({
            CYN"�ѱi���k��[��}�B��W�A����ʡC\n"NOR,
        }) );
        do_chat( ({
            (: command, "cry" :),
            (: command, "say �Ӧn�F�I" :),
            (: command, "follow " + this_player()->query("id") :),
            (: command, "guard " + this_player()->query("id") :),
            (: command, "say �·ЧA�a�ڦ^�h�ڤ��˨��a�I" :),
        }) );
        return;
    }
    if( arg == "���O" && !query("helper") ) {
        if( this_player()->query_temp("quest/help_girl") < 1) {
            message_vision(CYN"$N�`�Ȫ������X�ܨӡC\n"NOR, this_object());
            return;
        }
        this_player()->delete_temp("quest/help_girl");
        do_chat((: command, "say ...." :));
        return;
    }
}
void die()
{
    object helper;
    message_vision(HIR"\n$N����L�h�A�ש��٬O�k���L���`���R�B�C\n"NOR, this_object(), this_player());
    if( objectp(helper = query_helper()) ) helper->delete_temp("quest/help_girl");
    ::die();
}
