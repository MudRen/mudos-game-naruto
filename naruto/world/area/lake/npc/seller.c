#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;
int i;

void create()
{
    set_name("�j���ӤH" , ({ "seller" }));
    set("long", "�ΪέD�D���ӤH�A���ɹ�ǤH�S�X���N���L���C\n");
    set_level(60);
    set("gender","male");
    set("age",60);
    set("chat_chance", 6);
    set("chat_msg", ({
        (: command, "say �o�ǫB���ٯu�C���C" :),
        (: command, "say ������M�ڰ��I�u�R��v�ܡH" :),
        CYN"�j���ӤH���G�������@�ФF�C\n"NOR,
        (: command, "angry" :),
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "��}�l" || arg == "�o��" || 
        arg == "�}��~" || arg == "�_�Ǫ���" || arg == "��") {

        do_chat(({ 
           (: command, "say ��}�l��A�Ӫ��ܡH" :),
           (: command, "say �ָ�L����D�a�C" :),
           (: command, "shrug" :),
        }));
        return;
    }
    if( arg == "�R��" )  {
        if( this_player()->query_temp("quest/seller") == 1) {
        do_chat(({ 
            (: command, "say �A�٨S�^���ڪ��H" :),
            (: command, "say ���Q�����N���u�����v" :),
        }));
        return;
        } else
        if( this_player()->query_temp("quest/seller") == 2) {
            do_chat(({ 
                (: command, "say ���Q���ڤF�ܡH" :),
                (: command, "say ���N�u����v�M�ڪ�����a�C" :),
            }));
            return;
        }
        this_player()->add_temp("quest/seller", 1);
        do_chat(({ 
            (: command, "say ���I���������ڶܡH" :),
            (: command, "say �ǻ��b���Z�򩳦��ӥj�Ѫ��ؿv����C" :),
            (: command, "say �u�n�A���ڮ��̭����j���X�ӡA�ڴN�������A�Ī��I" :),
            (: command, "say �u���ڤ~�|���Ӧn����I�Ҽ{�ݬݧa�I" :),
        }));
        return;
    }
    if( arg == "������" || arg == "����" ||
        arg == "�n" || arg == "���A" ) {

        if( this_player()->query_temp("quest/seller") == 2) {
            do_chat(({ 
                (: command, "say �A�w�g�n���ڤF���O�ܡI" :),
                (: command, "say ���I�h�a�C" :),
                (: command, "say �A�����I�p�߳Q�L�̷h���F��I" :),
            }));
            return;
        } else
        if( this_player()->query_temp("quest/seller") == 1) {
            this_player()->add_temp("quest/seller", 1);
            do_chat(({ 
                (: command, "jump" :),
                (: command, "say ���N���U�A�աI" :),
                (: command, "say �u�O��~�w�g���B�����Ԫ̨ӧ�L�ڤF�C" :),
                (: command, "say �L�̤ӺC�F���ڤ��o���A��H�����C" :),
                (: command, "say �A�����I�p�߳Q�L�̷h���F��I" :),
            }));
            return;
        } else {
            do_chat(({ 
                (: command, "?" :),
                (: command, "say �A�b��ԣ���H" :),
            }));
            return;
        }
    }
    if( arg == "����" || arg == "����" )  {
        if( this_player()->query_temp("quest/seller") < 1) {
            do_chat(({ 
                (: command, "?" :),
                (: command, "say ��������A�ڤS�S��A�����C" :),
            }));
        } else {
        this_player()->delete_temp("quest/seller");
            do_chat(({ 
                (: command, "sigh" :),
                (: command, "say �n�a�I�ڦA�t�~��H�n�F�C" :),
            }));
            return;
        }
    }
}
int give_check(object ob)
{
    if( ob->id("_OLD_VASE_") ) return 1;           // �j����~
    if( ob->id("_EXQUISITE_DOLL_") ) return 2;     // ��o����
    if( ob->id("_UNKNOWN_POTTERY_") ) return 3;    // ��������
    if( ob->id("_WOOD_TREASURY_") ) return 4;      // ��y��
    if( ob->id("_BAD_BELL_") ) return 5;           // �l�a��������
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say �F��Ӧh�����L�Ӫ��I" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �ϩR���I���H���I" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/seller") == 2) {
                if( ob->query_amount() > 1 ) {
                    do_chat((: command, "say �@�Ӥ@�ӵ��a�A�@���Ӧh�ڤ���KŲ�w�C" :));
                    return 0;
                }
                i = 100+random(400);
                message_vision("$N���L�j����~�J��Ų�w�C\n", this_object(), me);
                if( i >= 400) {
                    message_vision("$N�����a���R"HIG"�o�ӵ����~�O�s���u�n���I���L�������H�٥H����~���F�O�I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else if( i >= 300) {
                    message_vision("$N���L�a���R"HIG"�i���F�o�Ӫ�~���I�٦n�������O���Y���C\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else if( i >= 200) {
                    message_vision("$N�d�h�a���R"HIG"�˪��u�O���Y���F�I�u������f��I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else {
                    message_vision("$N�s�˦a���R"HIG"�j�������F�a�I�ݦb�A���W���Ӫ����W��\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                }
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�Q�����쪺�j����ڪ��I\n"NOR, this_object(), me);
            message_vision("$N���D�R"HIG"�Q�`�ڥi�S�o��e���I\n"NOR, this_object(), me);
            return 0;
            break;
        case 2:
            if( me->query_temp("quest/seller") == 2) {
                if( ob->query_amount() > 1 ) {
                    do_chat((: command, "say �@�Ӥ@�ӵ��a�A�@���Ӧh�ڤ���KŲ�w�C" :));
                    return 0;
                }
                i = 150+random(550);
                message_vision("$N���L��o�����J���[��C\n", this_object(), me);
                if( i >= 600) {
                    message_vision("$N���D�R"HIG"�o�ӫ����֩w���Ӧn�����I�����S������ˮ`�O�I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else if( i >= 400) {
                    message_vision("$N���D�R"HIG"��㦳�@�I�I�}�l�A���L�ɤ@�ɤj���N�ݤ��X�ӤF�C\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else if( i >= 250) {
                    message_vision("$N�d�h�a���R"HIG"�˪��u�O���Y���F�I�u������f��I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else {
                    message_vision("$N�s�˦a���R"HIG"�j�������F�a�I�ݦb�A���W���Ӫ����W��\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                }
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�Q�����쪺�j����ڪ��I\n"NOR, this_object(), me);
            message_vision("$N���D�R"HIG"�Q�`�ڥi�S�o��e���I\n"NOR, this_object(), me);
            return 0;
            break;
        case 3:
            if( me->query_temp("quest/seller") == 2) {
                if( ob->query_amount() > 1 ) {
                    do_chat((: command, "say �@�Ӥ@�ӵ��a�A�@���Ӧh�ڤ���KŲ�w�C" :));
                    return 0;
                }
                i = 200+random(700);
                message_vision("$N���L���������J��Ų�w�C\n", this_object(), me);
                if( i >= 800) {
                    message_vision("$N�����a�j�ۡR"HIG"�o�i�O�j�N���u�ݪ��I�S�Q��~�M���o��n���F��C\n"NOR, this_object(), me);
                    message_vision("$N�n�֦a���R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else if( i >= 600) {
                    message_vision("$N�r���a���R"HIG"�o�������M�����X�۽֤�A���]�Q������O�C\n"NOR, this_object(), me);
                    message_vision("$N���ۻ��D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else if( i >= 400) {
                    message_vision("$N���D�R"HIG"�o�j���O��s�~�a�I�����D���F�L�h�֦����H�C\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else {
                    message_vision("$N�ͮ�a���R"HIG"�o�ضî��@�q�������]��s�j���I�H\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"��$n"HIY+i+HIG"��Ī������u�@�a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                }
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�Q�����쪺�j����ڪ��I\n"NOR, this_object(), me);
            message_vision("$N���D�R"HIG"�Q�`�ڥi�S�o��e���I\n"NOR, this_object(), me);
            return 0;
            break;
        case 4:
            if( me->query_temp("quest/seller") == 2) {
                if( ob->query_amount() > 1 ) {
                    do_chat((: command, "say �@�Ӥ@�ӵ��a�A�@���Ӧh�ڤ���KŲ�w�C" :));
                    return 0;
                }
                i = 400+random(800);
                message_vision("$N���L��y�ë᪽���N��y�í�}�d�ݤ������~�C\n", this_object(), me);
                if( i >= 1000) {
                    message_vision("$N��Y�a���R"HIG"�o�Ǭï]����i���O�j�����u�~�O�I�y�L�˹��@�U�֩w���Ӧn���I\n"NOR, this_object(), me);
                    message_vision("$N�ּ֦a���R"HIG"�o"HIY+i+HIG"��Ī���$n�ٵy�������O�I�A�h���ڮ��X�ӤW�ӧa�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else if( i >= 900) {
                    message_vision("$N���D�R"HIG"�̭������_���٥��g�Z�i�A�����u��]�O�@���j������I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�o"HIY+i+HIG"��Ī���$n���n�O�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else if( i >= 700) {
                    message_vision("$N���D�R"HIG"�i���u��٪��W���ū~�I�浹�@��H�a�j�������C\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else if( i >= 500) {
                    message_vision("$N�s�n�Į�R"HIG"�o���_�ۦ��G�Ӥp�F�@�I�A�i��s���ӧ٫��������a�C\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"�N��$n"HIY+i+HIG"��Ī��a�I\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                } else {
                    message_vision("$N�q�q�ӻ��R"HIG"�d���n�~�������٤�̭��ȿ��a�I\n"NOR, this_object(), me);
                    message_vision("$N���D�R"HIG"��$n"HIY+i+HIG"��Ī��N��N��a�C\n"NOR, this_object(), me);
                    tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
                    me->add("bank", i);
                }
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N���D�R"HIG"�Q�����쪺�j����ڪ��I\n"NOR, this_object(), me);
            message_vision("$N���D�R"HIG"�Q�`�ڥi�S�o��e���I\n"NOR, this_object(), me);
            return 0;
            break;
        case 5:
            if( ob->query_amount() > 1 ) {
                do_chat((: command, "say �@�Ӥ@�ӵ��a�A�@���Ӧh�ڤ���KŲ�w�C" :));
                return 0;
            }
            message_vision("$N���L�l�a��"HIY"������"NOR"�ᨸ�����@���C\n", this_object(), me);
            message_vision("$N���c�a���R"HIG"���a�F�ө������F�a�I�ڳo�̥i�O�H"HIY"200"HIG"��Ȥl����I\n"NOR, this_object(), me);
            message_vision("$N���c���D�R"HIG"���¥��{�����w��h�h���a���ӷ����\n"NOR, this_object(), me);
            tell_object(me, "(�Ī��w�g�۰ʦs�b�Ȧ�̡C)\n");
            me->add("bank", 200);
            do_chat( ({ ( : destruct , ob : ), }) );
            break;
        default:
            do_chat((: command, "say �ڥu�n�j���աI" :));
            return 0;
            break;
    }
    return 1;
}
