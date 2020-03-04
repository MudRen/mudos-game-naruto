#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "say �Q�n�u�ѥ[�v�����y�H�ҸնܡI�H" :),
        (: command, "say �w�靈��O���L���y�H���W�ѥ[�I" :),
    }) );
}
void create()
{
    set_name("�į�", ({ "saze" }));
    set_race("human");
    set_level(60);
    set_class("hxh_intermediate");
    set("title","�y�H����D�ҩx");
    set("long", "�y�W�S������A���N�����H�Pı�ˤ��C\n");
    set("camp", "hunter");
    set("age", 35);
    set("gender", "male");
    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
}
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "�ѥ[" || arg == "�ѥ[�Ҹ�" ) {
        if( me->query_level() < 20 ) {
            do_chat((: command, "say "+me->query("name")+"��O�٤Ӯt�F�A����ѥ[�����y�H�ҸաC" :));
            return 1;
        }
        if( me->query_class() != "hxh_initial") {
            do_chat((: command, "say "+me->query("name")+"�A�u���L���y�H�~��ѥ[�ҸաC" :));
            return 1;
        }
        if( me->query_temp("inter_test") ) {
            do_chat((: command, "say "+me->query("name")+"�w�g�ѥ[�����y�H�ҸդF��C" :));
            return 1;
        }
        do_chat(({
            (: command, "say �n�a�I"+me->query("name")+"ť�ۦҸ��D�ءC" :),
            (: command, "say �h�շҬ}�]�����Ѩ�L�L���y�H�����X�P�C" :),
            (: command, "say �u�n�ள��T�i���X�P���ڡA�A�N���������y�H�F�I" :),
        }));
        me->set_temp("inter_test", 1);
    }
    return 1;
}
int accept_object(object me, object item)
{
    int pass=0;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( !item->query("inter_test") ) return 0;

    if( me->query_level() < 20 ) {
        do_chat((: command, "say "+me->query("name")+"��O�٤Ӯt�F�A����ѥ[�����y�H�ҸաC" :));
        return 0;
    }
    if( me->query_class() != "hxh_initial") {
        do_chat((: command, "say "+me->query("name")+"�A�u���L���y�H�~��ѥ[�ҸաC" :));
        return 0;
    }
    if( !me->query_temp("inter_test") ) {
        do_chat((: command, "say "+me->query("name")+"�S���ѥ[�����y�H�ҸդF��C" :));
        return 0;
    }
    message_vision("$N���L$n����"+item->query("name")+"���D�G"HIG"�ܦn�I�~��V�O�a�I\n"NOR, this_object(), me);

    if( item->query("inter_test") == 1 ) me->add_temp("inter_test_b1", 1);

    if( me->query_temp("inter_test_b1") >= 3 ) pass = 1;

    if( pass ) {
        me->delete_temp("inter_test");
        me->delete_temp("inter_test_b1");
        me->set_class("hxh_intermediate");
        do_chat(({
            (: command, "say "+me->name()+"�w�g�q�L�����y�H�ҸդF�I���ߡI" :),
            (: command, "cong "+me->query_id() :),
            (: destruct, item :),
        }));
        return 1;
    }
    do_chat(((: destruct, item :)));
    return 1;
}
