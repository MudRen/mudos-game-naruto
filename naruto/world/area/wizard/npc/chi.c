#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("���fè", ({ "yi kou chi master", "master" }) );
    set_race("human");
    set_level(40);
    set_class("superior");
    set("age", 25);
    set("title", "�s��ɮv");
    set("long", "�L�O�@��s��ɮv�A�оɧA�p��b�o�ӥ@�������I�p�G�A�Q�n�����L\n"
                "�����ɡA�п�J���O�Gask master\n"
                "�Y�Q�i�@�B�A�ѫ��O���Ϊk�A�п�J�Ghelp ask\n"
    );
    setup();
}
void init()
{
    if( this_player()->query_class() == "commoner" && userp(this_player()) ) {
        do_chat( ({ 
            (: command, "say �A�n�ڡA�o��i���ͫܡA�O�s�Ӫ��ܡH" :), 
            (: command, "say �Y�n�����s��оǽп�J���O�Gask master" :),
            (: command, "say �Y�n�d�߻������п�J���O�Ghelp" :),
        }) );
    }
    return;
}
