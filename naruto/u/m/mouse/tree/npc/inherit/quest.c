#include <ansi.h>

void relay_say(object ob, string arg)
{
    if( arg == "�ݭn" )  {
        this_object()->do_chat( ({ 
            (: command, "say �u�n�൹�ڨ�����U���A�N���A���쪺���ֶ���C" :),
        }) );
        return;
    }
}

int give_check(object ob)
{
    if( ob->id("_TREE_FRUIT_") ) return 1;            // ��G
    if( ob->id("_MONKEY_TOOTH_") ) return 2;          // �U��
    else return 0;
}

int accept_object(object me, object ob)
{
    object item;
    if( this_object()->is_busy() ) {
        this_object()->do_chat((: command, "say �椰��I���֥i�O�ܪ�ɶ����I" :));
        return 0;
    }
    if( this_object()->is_fighting() ) {
        this_object()->do_chat((: command, "say �ݧڳQ���٤��������I���Q�n����աI" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/necklace") == 1) {
            if( ob->query_amount() < 100 ) {
                this_object()->do_chat((: command, "say ��G�����ƥؤ����A�A�h�h���I�a�C" :));
                return 0;
            }
            if( file_size(__DIR__"eq/necklace.c") < 0 ) return 0;
            if( catch(item = new(__DIR__"eq/necklace.c")) ) return 0;
            if( item->move(me) ) {
                message_vision("$N�N"YEL"��G"NOR"�M�I��q���䮳�X�@��" + item->name() + "��$n�C\n", this_object(), me);
                message_vision("�g�۲��v�ũM�a���R"HIG"$n�����}�a�A��L�g�ۭ̥i���w��~�H�C\n"NOR, this_object(), me);
            } else {
                if( item->move(environment(me)) ) {
                    message_vision("$N�N"YEL"��G"NOR"�M�I��q���䮳�X�@��" + item->name() + "��$n�A���O���b�a�W�F�C\n", this_object(), me);
                    message_vision("�g�۲��v����a���R"HIG"$n�~�M�åᯫ�쪺����I���F�F��ֺu�I\n"NOR, this_object(), me);
                } else {
                    me->delete_temp("quest/necklace");
                    destruct(item);
                    return 0;
                }
            }
            me->delete_temp("quest/necklace");
            ob->set_amount(0);
            this_object()->do_chat( ({ ( : destruct , ob : ), }) );
            break;
            } else {
                message_vision("�g�۲��v���D�R"HIG"�e�@���٨S�䧹�O�A�椰��C\n"NOR, this_object(), me);
                return 0;
            }
        case 2:
            if( me->query_temp("quest/necklace")) {

                message_vision("�g�۲��v���D�R"HIG"�w�g���L�աI�֧�ĤG�اa�C\n"NOR, this_object(), me);
                return 0;
            } else {
            if( ob->query_amount() < 200 ) {
                this_object()->do_chat((: command, "say �U�������ƥؤ����A�A�h�h���I�a�C" :));
                return 0;
                } else {
                me->add_temp("quest/necklace", 1);
                message_vision(CYN"�g�۲��v�M�I��"HIW"�U��"NOR""CYN"���ƶq�C\n"NOR, this_object(), me);
                message_vision("�g�۲��v���D�R"HIG"�t�I�ѤF���ٻݭn�@������G�A���K���ڧa�C\n"NOR, this_object(), me);
                }
            break;
            }
        default:
            this_object()->do_chat((: command, "say ���F�ثe�ݭn�����~��L�ڤ��n�I" :));
            return 0;
            break;
    }
    return 1;
}
