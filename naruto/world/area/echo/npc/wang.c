#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "angry" :),
        (: command, "say �ѡI�ֵ����ѡI" :),
    }) );
}
void create()
{
    set_name("���ʸU", ({ "wang by one", "wang", "one" }));
    set_race("human");
    set_level(40);
    set("title",HIC"�ѭ��a"NOR);
    set("long", "�ΪέD�D���ѭ��a�A�a�]�U�e�������h�R�ѦY�C\n");
    set("age", 40);
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
}
int relay_say(object me, string arg)
{
    if( arg == "��" ) {
        do_chat( ({
           (: command, "say �A�O���ѱi�����Ѩӵ��ڪ��ܡI�H" :),
        }) );
        return 1;
    }
    if( arg == "�ѱi" || arg == "������" || arg == "�ѱi������" ) {
        do_chat( ({
           (: command, "stare" :),
           (: command, "say ���J�ѧ��ܤF�ڪ��@�͡C" :),
           (: command, "say �쥻�ڬO�Ӥ��򳣦Y�A���������o�ɨ��C" :),
           (: command, "say �Y�L�F���J�ѡA�~�u�����D����s�H�������I" :),
           (: command, "sigh" :),
           (: command, "say ���L��ӧڦA�]�䤣��ѱi�����u�F�C" :),
           (: command, "say �uť�����H�b�H���ӪL�ݹL�ѱi�b���̭��C" :),
           (: command, "say ���L�o���i��O�I���ذ���F�¶]��ӪL�h�I" :),
           (: command, "say �p�G���ů������ڧ��L�ܡH" :),
           (: command, "say �����藍�O���D�I" :),
        }) );
    }
    if( arg == "����" || arg == "��L" ) {
        if( me->query_level() < 5 ) {
            message_vision("$N���G���ӷQ�z$n\n", this_object(), me);
            return 0;
        }
        if( this_player()->query_temp("quest/noodle_help") == 1) {
            do_chat( ({
               (: command, "glare" :),
               (: command, "say �n�j���A�A���I�n�ܡC" :),
            }) );
        }
        this_player()->add_temp("quest/noodle_help", 1);
        do_chat( ({
           (: command, "ya" :),
           (: command, "say �浹�A�O�I" :),
        }) );
        return 1;
    }
    return 1;
}
int give_check(object ob)
{
    if( ob->id("_BEEF_NOODLES_") ) return 1;    // ������
    if( ob->id("_GOOD_FOOD_") ) return 2;       // �@����
    else return 0;
}
int accept_object(object me, object ob)
{
    int amount;
    object item;

    if( is_busy() ) {
        tell_object(me, "�L���b�Y�Ѥ��A�еy���C\n");
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �����B�ʤ@�U�]�����I" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 1:
            if( this_player()->query_temp("quest/noodle_help") < 1 ) {
                do_chat((: command, "say �A�G�N���ѨӮ�ڶܡI" :));
                return 0;
            }
            amount = ob->query_amount();
            if( amount > 100 ) {
                do_chat((: command, "say �@�����o��h�ӭ��F�A���嵹�a�I" :));
                return 0;
            }
            message_vision("$N���L$n�P�ʪ��y�U���\�C\n"NOR, this_object(), ob);
            do_chat( ({
               (: command, "say �o...��b�ӴΤF�I" :),
               (: command, "spank " + this_player()->query("id") :),
               (: command, "say �o"+amount*100000+"��Ȥl�N���h�a�I�ڭn�n�n�ɨ��o�ѤF�C" :),
               ( : destruct , ob : ),
            }) );
            tell_object(me, "( "HIY+amount*100000+HIG" ��Ȥl�w�g�۰ʦs�b�Ȧ�̡C"NOR")\n");
            me->add("bank", amount*100000);
            me->delete_temp("quest/noodle_help");
            break;
        case 2:
            if( this_player()->query_temp("quest/noodle_help") < 1 ) {
                do_chat((: command, "say �ɶ���Į�j���t�Y���G���ѡH�����]�h�R�@�J�C" :));
                return 0;
            }
            amount = ob->query_amount();
            message_vision("$N���L$n�D�D�����C\n"NOR, this_object(), ob);
            do_chat( ({
               (: command, "say ��A�T�w�O�u�~�A���L���O�����ѯu�i���I" :),
               (: command, "say �o"+amount*1000+"��Ȥl���A��]���O�a�C" :),
               ( : destruct , ob : ),
            }) );
            tell_object(me, "( "HIY+amount*1000+HIG" ��Ȥl�w�g�۰ʦs�b�Ȧ�̡C"NOR")\n");
            me->add("bank", amount*1000);
            me->delete_temp("quest/noodle_help");
            break;
        default:
            do_chat((: command, "say �o�O������I��Y�ܡI" :));
            return 0;
            break;
    }
    return 1;
}
