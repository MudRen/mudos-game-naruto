#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "say �o�ǻa�����u�O�Ӳs�g�F�C" :),
        (: command, "say �u�����D�ӫ���I�e�̡C" :),
        (: command, "sigh" :),
    }) );
}
void create()
{
    set_name("�\�Y", ({ "bow head", "head", "_BOW_HEAD_" }));
    set_race("human");
    set_level(60);
    set("title","�\�H�ڪ�");
    set("long", "�\�ڪ��ѡA�b�y���������o�a�ۤ@�شd�h�C\n");
    set("age", 80);
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
        CYN"�n�ȵo�X�n�T...�u��..�v\n"NOR,
    }) );
    setup();
}
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "���Ⱚ�Ⱚ����" ) {
        if( this_player()->query_temp("quest/gogogood") == 1) {
            do_chat( ({
               (: command, "ack" :),
               (: command, "say �S�Q��"+this_player()->query("name")+"�u����o�Ӻ٩I��������I" :),
               (: command, "say ���N���A�a�I��������~���H�F�C" :),
            }) );
            this_player()->add_temp("quest/gogogood", 1);
            this_player()->set("nickname",HIW"����"HIY"����"HIC"������"NOR);
        } else
        if( this_player()->query_temp("quest/gogogood") > 1) {
            do_chat( ({
               (: command, "say ���⨺��Q�����ٸ��˥�F�O�I" :),
               (: command, "say �A��"+this_player()->query("name")+"�@���a�I" :),
               (: command, "say �A�˥�ڥi���ޤF�I" :),
            }) );
            this_player()->delete_temp("quest/gogogood");
            this_player()->set("nickname",HIW"����"HIY"����"HIC"������"NOR);
        } else {
            do_chat( ({
               (: command, "cac" :),
               (: command, "say ���i�O�ڦ~���ɤj�a���ڪ��٩I�O�I" :),
               (: command, "say �u�n��u��I�v�a�����A�o�٩I���A�]�}�I" :),
               (: command, "nomatch _BOW_HEAD_" :),
            }) );
        }
        return 1;
    }
    if( arg == "�a����" || arg == "�s�g" ) {
        do_chat( ({
           (: command, "say ����e�N���ڥͮ�C" :),
           (: command, "angry" :),
           (: command, "say �ڦ~�����ɭԴN���@���a�����ӹL�F���r�C" :),
           (: command, "say ���G�Q�H�١u���Ⱚ�Ⱚ����v���ڵ����]�F�C" :),
           (: command, "cac" :),
           (: command, "eh _BOW_HEAD_" :),
           (: command, "say ����..���O�n���o�ӡC" :),
           (: command, "say �O�e�̳̪�~�M�S�]�Ӧ����F���r�C" :),
           (: command, "say �w�g�����ڭ̤��֥h�F���r�׽m���ڤH�F�I" :),
           (: command, "say �[�W�ڦ~�Ƥw��..." :),
           (: command, "ah" :),
           (: command, "say �̪�ڭ̦b��H�u��I�v�o�ǻa�����C" :),
           (: command, "say ������i�H��ڬ��ͪ��C" :),
           (: command, "wink "+this_player()->query("id") :),
        }) );
        return 1;
    }
    if( arg == "��I" || arg == "������" || arg == "���" || arg == "����" ) {
        if( this_player()->query_temp("quest/owleyes") == 1) {
            do_chat( ({
               (: command, "say �[�o�[�o�I" :),
               (: command, "laddoil "+this_player()->query("id") :),
               (: command, "say �p�G���\�i�H�Ⱚ�Ⱚ�Ⱚ���⪺�W�����A��I" :),
            }) );
        } else {
            do_chat( ({
               (: command, "say �Ӧn�F�I�ש���H���I�աI" :),
               (: command, "goodboy "+this_player()->query("id") :),
               (: command, "say �u�n���ڱ������N���ҩ��A�����e�F�I" :),
               (: command, "say �[�o�a�I" :),
            }) );
        this_player()->add_temp("quest/owleyes", 1);
        }
        return 1;
    }
    return 1;
}

int give_check(object ob)
{
    if( ob->id("_OWL_EYE_") ) return 1;    // ������
    else return 0;
}
int accept_object(object me, object ob)
{
    int amount;
    object item;

    if( is_busy() ) {
        tell_object(me, "���b���L���A�����a�C\n");
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �S�ݨ찪�⥿�b���[�ܡI" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 1:
            if( this_player()->query_temp("quest/owleyes") < 1 ) {
                do_chat((: command, "say �ڨS�����U�A��I�e�̧a�I" :));
                return 0;
            }
            amount = ob->query_amount();
            message_vision("$N�ݵ�$n�������q��ȤW���F�_�ӡC\n"NOR, this_object(), ob);
            do_chat( ({
               (: command, "say �F���n���I" :),
               (: command, "spank " + this_player()->query("id") :),
               (: command, "say �o"+amount*50000+"��Ȥl�O�ڦۤv�h�����I" :),
               ( : destruct , ob : ),
            }) );
            tell_object(me, "( "HIY+amount*50000+HIG" ��Ȥl�w�g�۰ʦs�b�Ȧ�̡C"NOR")\n");
            tell_object(me, HIY"�ѯť���"NOR"�W�[�F("HIY+amount*5+NOR")�I�C\n");

            me->add("bank", amount*50000);

            // �[c�ť���
            me->gain_score("clevel", amount*5);

            // �W�[����nick
            me->add_temp("quest/gogogood", 1);

            // �����Ȧs�����
            me->delete_temp("quest/owleyes");
            break;
        default:
            do_chat((: command, "say �A�H���ڦѽk��F�ܡI" :));
            return 0;
            break;
    }
    return 1;
}
