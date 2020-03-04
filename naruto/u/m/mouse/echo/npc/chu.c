#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("���", ({ "tom chu", "chu" }));
    set_race("human");
    set("gender", "female");
    set_level(40);
    set("age", 25);
    set("nickname","�����y�H");
    set("long", "��W���ۤ��j���y�H�A���b��z���Ǫ��˳ơC\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say �u�n���٬��ۡA�@�w�n�����l���H�����I" :),
        (: command, "say ���Ӥp�ݨ��ǳD�H���I" :),
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "�D�H" || arg == "��m" )  {
        do_chat(({
            (: command, "say �ڬ�s�F�e�̤@�q��l�C" :),
            (: command, "say �o�{�e�̴N�b�^���}�ު��t�@��C" :),
            (: command, "say ���L�ƶq���O�ܦh...�i����ڤH�����F�C" :),
            (: command, "say �]�����D�O�����]�C" :),
            (: command, "say ���e�̻{���^�W�����~���D���A�K���^�쥻���ڤH�C" :),
        }));
        return;
    }
    if( arg == "�����~" )  {
        do_chat(({
            (: command, "think" :),
            (: command, "say �o�n�ݦѱi����M���C" :),
            (: command, "say ��ɧڥX�h���y���b�����C" :),
        }));
        return;
    }
    if( arg == "����" )  {
        do_chat(({
            (: command, "say �o�ǳD�H�u�O�ӥi�c�F�I" :),
            (: command, "say ���������A�藍�_���H�I" :),
        }));
        return;
    }
    if( arg == "����" )  {
        if( this_player()->query_temp("quest/helpvill") == 1) {
        do_chat(({
            (: command, "say ���Q�����N���u�����v" :),
            (: command, "say �����A���O���H�A���|�F�ѳo�طPı���C" :),
        }));
        return;
        } else
        if( this_player()->query_temp("quest/helpvill") == 2) {
            do_chat(({
                (: command, "say ���Q�����աH" :),
                (: command, "say ���N�u����v�~�������a�C" :),
            }));
            return;
        }
        this_player()->add_temp("quest/helpvill", 1);
        do_chat(({
            (: command, "hmm" :),
            (: command, "say ����Ʊ����g�L�i�D�A�n�F�C" :),
            (: command, "say ���N�O�@�s�D�H��M�Ө�����C" :),
            (: command, "say �٭n�ڭ̥浹�e�̤@��k�ʷ������~�I" :),
            (: command, "say ��M�����ڵ��F�e�̪��n�D�C" :),
            (: command, "say ��F�ߤW...���ǳD�H�~�M�ޤF�@�s�s�T�ӱO���I" :),
            (: command, "say �s�ߤ@���h���^���s�}�]�Q�e�̤ޤF�@�s�a���b�̭��C" :),
            (: command, "say �L�k�k�������H�̴N���F�e�̪��y���C" :),
            (: command, "say ���F�ѱi�M�ڡA�����Q�����F�C" :),
            (: command, "say �ҥH�ڨM�w�n��o�ǱO�����D�H�����I" :),
            (: command, "say ��M�s�T�M�g���]�O�I" :),
            (: command, "say �A����u���U�v�ڶܡH" :),
        }));
        return;
    }
    if( arg == "���U" ) {
        if( this_player()->query_temp("quest/helpvill") == 2) {
            do_chat(({
                (: command, "say �A�w�g�b���ڤF�I" :),
            }));
            return;
        } else
        if( this_player()->query_temp("quest/helpvill") == 1) {
            this_player()->add_temp("quest/helpvill", 1);
            do_chat(({
                (: command, "jump" :),
                (: command, "say �ӷP�§A�F�I" :),
                (: command, "say �u�n���ڳD�J�B���Y�B�T���C" :),
                (: command, "say �ڴN���A�γo�Ǫ��~�s�����ķ����y�C" :),
                (: command, "say �Ʊ�N�e�̯}�a���O�q�Ƭ���ū���O�C" :),
            }));
            return;
        } else {
            do_chat(({
                (: command, "?" :),
                (: command, "say �٤��F�Ѫ��p�N�Q�����H" :),
            }));
            return;
        }
    }
    if( arg == "����" || arg == "����" )  {
        if( this_player()->query_temp("quest/helpvill") < 1) {
            do_chat(({
                (: command, "?" :),
                (: command, "say �A�S�����U�ڧa�C" :),
            }));
        } else {
        this_player()->delete_temp("quest/helpvill");
            do_chat(({
                (: command, "sigh" :),
                (: command, "say �n�a�A�ڦۤv��I�e�̡C" :),
            }));
            return;
        }
    }
}
int give_check(object ob)
{
    if( ob->id("_WOLF_TOOTH_") ) return 1;   // �T��
    if( ob->id("_MOUSE_HEAD_") ) return 2;   // ����
    if( ob->id("_SNAKE_EGG_") ) return 3;    // �D�J
    else return 0;
}
int accept_object(object me, object ob)
{
    int amount;
    object item;

    amount = ob->query_amount();

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
            if( me->query_temp("quest/helpvill") == 2) {
                if( amount < 1 ) {
                    do_chat((: command, "say �ܤ֭n���@���H�W���T���I" :));
                    return 0;
                }
                if( file_size(__DIR__"item/powder.c") < 0 ) return 0;
                if( catch(item = new(__DIR__"item/powder.c")) ) return 0;
                if( amount ) {
                    if( function_exists("set_amount", ob) ) {
                        item->set_amount(amount);
                    } else
                    if( function_exists("set_volume", ob) ) {
                        item->set_volume(amount);
                    }
                }
                if( item->move(me) ) {
                    message_vision("$N���D�R"HIG"�h��$n�������A�o�˧��H�b�Ѥ��F�]�o��w���I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"���A�P�˼ƶq��"+item->name()+"�@"NOR"("HIY+amount+NOR")"HIG"�]�C\n"NOR, this_object(), me);
                } else
                if( item->move(environment(me)) ) {
                    message_vision("$N���D�R"HIG"�h��$n�������A�o�˧��H�b�Ѥ��F�]�o��w���I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"���A�P�˼ƶq��"+item->name()+"�@"NOR"("HIY+amount+NOR")"HIG"�]�A�ӭ����A��a�W�C\n"NOR, this_object(), me);
                } else {
                    destruct(item);
                    return 0;
                }
                ob->set_amount(0);
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�A�����U�ڶܡH\n"NOR, this_object(), me);
            break;
        case 2:
            if( me->query_temp("quest/helpvill") == 2) {
                if( amount < 1 ) {
                    do_chat((: command, "say �ܤ֭n���@���H�W�������I" :));
                    return 0;
                }
                if( file_size(__DIR__"item/fat.c") < 0 ) return 0;
                if( catch(item = new(__DIR__"item/fat.c")) ) return 0;
                if( amount ) {
                    if( function_exists("set_amount", ob) ) {
                        item->set_amount(amount);
                    } else
                    if( function_exists("set_volume", ob) ) {
                        item->set_volume(amount);
                    }
                }
                if( item->move(me) ) {
                    message_vision("$N���D�R"HIG"�h��$n�������A�o�˧��H�b�Ѥ��F�]�o��w���I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"���A�P�˼ƶq��"+item->name()+"�@"NOR"("HIY+amount+NOR")"HIG"���C\n"NOR, this_object(), me);
                } else
                if( item->move(environment(me)) ) {
                    message_vision("$N���D�R"HIG"�h��$n�������A�o�˧��H�b�Ѥ��F�]�o��w���I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"���A�P�˼ƶq��"+item->name()+"�@"NOR"("HIY+amount+NOR")"HIG"���A�ӭ����A��a�W�C\n"NOR, this_object(), me);
                } else {
                    destruct(item);
                    return 0;
                }
                ob->set_amount(0);
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�A�����U�ڶܡH\n"NOR, this_object(), me);
            break;
        case 3:
            if( me->query_temp("quest/helpvill") == 2) {
                if( amount < 1 ) {
                    do_chat((: command, "say �ܤ֭n���@���H�W���D�J�I" :));
                    return 0;
                }
                if( file_size(__DIR__"item/jelly.c") < 0 ) return 0;
                if( catch(item = new(__DIR__"item/jelly.c")) ) return 0;
                if( amount ) {
                    if( function_exists("set_amount", ob) ) {
                        item->set_amount(amount);
                    } else
                    if( function_exists("set_volume", ob) ) {
                        item->set_volume(amount);
                    }
                }
                if( item->move(me) ) {
                    message_vision("$N���D�R"HIG"�h��$n�������A�o�˧��H�b�Ѥ��F�]�o��w���I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"���A�P�˼ƶq��"+item->name()+"�@"NOR"("HIY+amount+NOR")"HIG"���C\n"NOR, this_object(), me);
                } else
                if( item->move(environment(me)) ) {
                    message_vision("$N���D�R"HIG"�h��$n�������A�o�˧��H�b�Ѥ��F�]�o��w���I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"���A�P�˼ƶq��"+item->name()+"�@"NOR"("HIY+amount+NOR")"HIG"���A�ӭ����A��a�W�C\n"NOR, this_object(), me);
                } else {
                    destruct(item);
                    return 0;
                }
                ob->set_amount(0);
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�A�����U�ڶܡH\n"NOR, this_object(), me);
            break;
        default:
            do_chat((: command, "say �o�ǪF�褣�O�ڭn��..." :));
            return 0;
            break;
    }
    return 1;
}
