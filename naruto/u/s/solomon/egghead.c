#include <ansi.h>
inherit NPC;
void create()
{
    set_name(HIC"�p�J�Y"NOR, ({ "Little egghead" , "egghead" }) );
    set_race("human");
    set_level(80);
    set("long", "�L�O�@��J�Ъ����H�A���߯կաA�~���O���A�O�J�Ф��i�h�o���n����C\n");
    set("age",18);
    set("title", HIM"�J�Ъ����H"NOR);
    set("chat_chance",10);
    set("chat_msg", ({ 
HIY"�p�J�Y�C�n���D�G�n���I�����o��A���M�N�ˤj���o�C\n"NOR,
HIG"�p�J�Y�j�n�ۻ��a���D�G�J�Х�N�U�Ӫ��u�@�A�ڱq�ӨS���d�{�L�I�I\n"NOR,
HIC"�p�J�Y�ݮ��D�G�`���̫�@�Ӥu�@�������o�A�n�֦n�֡C\n"NOR,
YEL"�p�J�Y�@��j�ۤf��A�@�仴�P�a�ۺq����\n"NOR,
                   (:command("tsk"):),
                   (:command("walileh"):),
                   (:command("sing"):),
                   (:command("laugh"):),
 }));
    setup();
}

void init()
{     
   object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}


void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
 
 command("hi "+ me->query("id"));
}
