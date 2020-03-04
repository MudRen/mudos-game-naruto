#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "sad" :),
        (: command, "say �����H���ϬP�o�_����o�ӤU���I" :),
        (: command, "draw" :),
    }) );
}
void create()
{
    set_name("���Ѫ���", ({ "spiderman" }));
    set_race("human");
    set_level(50);
    set("title",HIR"�H���ϬP"NOR);
    set("long", "��ۤ@���_�ǪA�˪��H�A���ۦb�����̵e���...\n");
    set("age", 22);
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
        (: command, "draw" :),
    }) );
    setup();
}
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "�j��ӦZ" ) {
        do_chat( ({
           (: command, "say �W���J��e�O���b����������C" :),
           (: command, "say �����D���S������m..." :),
        }) );
        return 1;
    }
    if( arg == "�H���ϬP" ) {
        do_chat( ({
           (: command, "sigh" :),
           (: command, "say ���ӴN�O�ڦ������p�߳Q�j��ӦZ���r��F�C" :),
           (: command, "say ���G�j�ѿ��Ө����ܧ��F..." :),
           (: command, "say ...�ٴ��ӤF�@�ط|�Q�j�ﵷ����O�C" :),
           (: command, "say ��ӧڵ��ΤF�o�ؤO�q�A���F�H���ӾľԡI" :),
           (: command, "sad" :),
           (: command, "say �i���ڤ��O�j��A�@�ѯ�s�y���j�ﵷ�w�g�����ڮ��ӤF�C" :),
           (: command, "say �Q�ӳo�̱��j�﮳�L�̪����h�ΡA�o�U���F��C" :),
           (: command, "cry" :),
           (: command, "say �֯������ڪ���I" :),
           (: command, "draw" :),
        }) );
        return 1;
    }
    if( arg == "����" || arg == "���A" ) {
        if( this_player()->query_temp("quest/spiderman") == 1) {
            do_chat( ({
               (: command, "hold "+this_player()->query("id") :),
               (: command, "say �ӷP�§A�F�I" :),
            }) );
        } else {
            do_chat( ({
               (: command, "wa" :),
               (: command, "say ���N�·ЧA�F�I" :),
               (: command, "say �u�n���ڤQ�ӻj���H�G�N�i�H�F�I" :),
            }) );
        this_player()->add_temp("quest/spiderman", 1);
        }
        return 1;
    }
    return 1;
}

int give_check(object ob)
{
    if( ob->id("_SPIDER_MUCUS_") ) return 1;    // �j���H�G
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;

    if( is_busy() ) {
        do_chat((: command, "say Wait�IWait Me�I" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say ���b�԰��I���ڤ@�U�a�I" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 1:
            if( this_player()->query_temp("quest/spiderman") < 1 ) {
                do_chat((: command, "say ���M�ܷQ��...���L�ڨS�ЧA�����C" :));
                return 0;
            }
            if( ob->query_amount() != 10 ) {
                do_chat((: command, "say �@���Q�ӴN�n�I�Ӧh�Ӥ֧A�ڳ��Y���C" :));
                return 0;
            }
            message_vision("$N���L$n�������j�s�R"HIG"Oh Ya�I\n"NOR, this_object(), ob);
            do_chat( ({
               (: command, "say �ӷP�§A�F�I���H�����H�A���a�I" :),
               (: command, "spank " + this_player()->query("id") :),
               (: command, "say �o "HIY"4000"HIG" ��Ȥl�N���Ȯ𪺦��U�a�I"NOR :),
               ( : destruct , ob : ),
            }) );
            tell_object(me, "( "HIY+4000+HIG" ��Ȥl�w�g�۰ʦs�b�Ȧ�̡C"NOR")\n");

            me->add("bank", 4000);

            // �����Ȧs�����
            me->delete_temp("quest/spiderman");
            break;
        default:
            do_chat((: command, "say �u�O�藍�_�A�ڥu�n�j���H�G�C" :));
            return 0;
            break;
    }
    return 1;
}
