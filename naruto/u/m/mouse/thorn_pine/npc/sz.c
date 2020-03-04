#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "sweat" :),
        (: command, "say �ڥ��b�o�̦�����G���ħ���s�C" :),
        (: command, "say ���L�~������L�`�ڨ�B���O���ˡC" :),
        (: command, "say �A�]�X�h�d���n�S�R�^�ӤF�I" :),
        (: command, "sigh" :),
    }) );
}
void create()
{
    set_name("�ۿP�h" , ({ "dr. sz", "sz" }));
    set_race("human");
    set("long", "����ճT���k�l�A���W��B���O�ˡC\n");
    set_level(61);
    set("title",HIW"�ճT���"NOR);
    set("gender","male");
    set("age",25);
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
    carry_object(__DIR__"eq/cloth.c")->wear();
}
void relay_say(object ob, string arg)
{
    if( arg == "��L" )  {
        do_chat(({ 
            (: command, "say �A����o�̤F���ӻ�йL�a�H" :),
            (: command, "say �Q���Ǩ�L����ٯu�O�h�O�I" :),
        }));
        return;
    }
    if( arg == "�ħ�" || arg == "��s" )  {
        do_chat(({ 
            (: command, "say ť���o��Q�L���᭱�٦����\�ڪ����l�C" :),
            (: command, "say �e�̨��˳��O�γo��G�Ӫv����I" :),
            (: command, "say �ҥH�ڨӳo�̰���s�C" :),
            (: command, "say �Ʊ��s����G����Ӫ��ĪG��n�I" :),
        }));
        return;
    }
    if( arg == "��G" )  {
        if( this_player()->query_temp("quest/helpwater") == 1) {
        do_chat(({ 
            (: command, "say �A�٨S�^���ڪ��H" :),
            (: command, "say ���Q�����N���u�����v" :),
        }));
        return;
        } else
        if( this_player()->query_temp("quest/helpwater") == 2) {
            do_chat(({ 
                (: command, "say ���Q���ڤF�ܡH" :),
                (: command, "say ���N�u����v�~�������ڧa�C" :),
            }));
            return;
        }
        this_player()->add_temp("quest/helpwater", 1);
        do_chat(({ 
            (: command, "say ���I�A�i�H���U�ڶܡH" :),
            (: command, "say �����~������H���|����G�C" :),
            (: command, "say ���ӵ��ڴN�i�H�F�I" :),
            (: command, "say �@�N���ܴN�u�����v�ڧa�I" :),
        }));
        return;
    }
    if( arg == "����" || arg == "���A" ) {
        if( this_player()->query_temp("quest/helpwater") == 2) {
            do_chat(({ 
                (: command, "say �A�w�g�n���ڤF���O�ܡI" :),
                (: command, "say ��ߧa�I���A���^�Ӽ��y�֤��F���C" :),
                (: command, "say ���Q�����N�u����v���U�ڧa�C" :),
            }));
            return;
        } else
        if( this_player()->query_temp("quest/helpwater") == 1) {
            this_player()->add_temp("quest/helpwater", 1);
            do_chat(({ 
                (: command, "dance" :),
                (: command, "say �@�����U�A�F�I" :),
            }));
            return;
        } else {
            do_chat(({ 
                (: command, "?" :),
                (: command, "say �S�ƧO���Z�ڰ�����C" :),
            }));
            return;
        }
    }
    if( arg == "����" || arg == "����" )  {
        if( this_player()->query_temp("quest/helpwater") < 1) {
            do_chat(({ 
       
         (: command, "?" :),
                (: command, "say �ڤS�S��A�����C" :),
            }));
        } else {
        this_player()->delete_temp("quest/helpwater");
            do_chat(({ 
                (: command, "glare" :),
                (: command, "say ���֯����کO..." :),
            }));
            return;
        }
    }
}
int give_check(object ob)
{
    if( ob->id("_HIG_WATER_") ) return 1;    // ����G
    if( ob->id("_HIM_WATER_") ) return 2;    // �����G
    if( ob->id("_HIR_WATER_") ) return 3;    // �����G
    if( ob->id("_HIY_WATER_") ) return 4;    // ������G
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say �Ӧ��F�I�����I" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �֨ӱϱϧڪ��I" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/helpwater") == 2) {
                message_vision("$N���������D�R"HIG"�h�§A����G���I\n"NOR, this_object(), me);
                tell_object(me, "(�A���ǲ��I�ƼW�[ " + 2*ob->query_amount() +" �I�F�C)\n");
                me->add_point("learn", 2*ob->query_amount() );
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�ڦn���S�ЧA�����I\n"NOR, this_object(), me);
            break;
        case 2:
            if( me->query_temp("quest/helpwater") == 2) {
                message_vision("$N���������D�R"HIG"�h�§A����G���I\n"NOR, this_object(), me);
                tell_object(me, "(�A���ǲ��I�ƼW�[ " + 5*ob->query_amount() +" �I�F�C)\n");
                me->add_point("learn", 5*ob->query_amount() );
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�ڦn���S�ЧA�����I\n"NOR, this_object(), me);
            break;
        case 3:
            if( me->query_temp("quest/helpwater") == 2) {
                message_vision("$N���������D�R"HIG"�h�§A����G���I\n"NOR, this_object(), me);
                tell_object(me, "(�A���ǲ��I�ƼW�[ " + 10*ob->query_amount() +" �I�F�C)\n");
                me->add_point("learn", 10*ob->query_amount() );
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�ڦn���S�ЧA�����I\n"NOR, this_object(), me);
            break;
        case 4:
            if( me->query_temp("quest/helpwater") == 2) {
                message_vision("$N���������D�R"HIG"�h�§A����G���I\n"NOR, this_object(), me);
                tell_object(me, "(�A���ǲ��I�ƼW�[ " + 50*ob->query_amount() +" �I�F�C)\n");
                me->add_point("learn", 50*ob->query_amount() );
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�ڦn���S�ЧA�����I\n"NOR, this_object(), me);
            break;
        default:
            do_chat((: command, "say �o�n�����O��G�C�I" :));
            break;
    }
    return 1;
}
