#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void create()
{
    set_name("����", ({ "ton gau", "gau" }) );
    set_level(60);
    set_class("superior");
    set_race("human");
    set("gender", "male");
    set("age", 25);
    set("long","�츭�����Ԫ̡A���G���b���H�����U�L�C");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: command, "say �e�U���OŢ���ȫ�򳣨S�H�n�����O...":),
    }));
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "�OŢ" || arg == "�OŢ����" || arg == "�e�U" )  {
        do_chat(({
            (: command, "nod" :),
            (: command, "say �N�O�ԨƪL�q���Q�Ү����OŢ�C" :),
            (: command, "say ť���ڦ����_�����ˮĪG�C" :),
            (: command, "say �ҥH�ڷQ���^�Ӭ�s�C" :),
            (: command, "say ���L�ڥH�e�N�{�Ѥj�D�Y�A�N�o�˶]�h�@�w�|�Q�������C" :),
            (: command, "say �]���o�˧ڹ�OŢ���Ƥ]�O�@���b�ѡC" :),
            (: command, "sigh" :),
            (: command, "say �ҥH�������U�@�ǥͭ��եh���~��C" :),
            (: command, "say ����񪺡y�e���Գ��z��u���]�@�ڡv" :),
            (: command, "say �L�̬O�j�D�Y�X�U���@��ڸs�C" :),
            (: command, "say �j�D�Y�N�O���L�̥h���OŢ���A�ҥH�ݥL�����ӷ|��M���C" :),
            (: command, "say �A��u�����v�ڶܡH" :),
        }));
        return;
    }
    if( arg == "�e���Գ�" || arg == "���]�@��" )  {
        do_chat(({
            (: command, "hmm" :),
            (: command, "say �a�Ϸ|�ݧa�H" :),
            (: command, "say �N�O help world �աC" :),
            (: command, "say �e���Գ��N�b���W���C" :),
            (: command, "say ���]�@�ڷ�M�N�b����C" :),
            (: command, "ah" :),
            (: command, "say ��F..." :),
            (: command, "say �d�U�O����]�@�ڪ��H�_�Ĭ��..." :),
            (: command, "say �L�̥H�e�Q�٬��c�]�@��..�O�ܦM�I���ڸs�C" :),
        }));
        return;
    }
    if( arg == "�c�]�@��" )  {
        do_chat(({
            (: command, "fear" :),
            (: command, "say �O�ݨ���h�A���n��L�̰_�Ĭ�N��F�I" :),
        }));
        return;
    }
    if( arg == "����" ) {
        if( this_player()->query_temp("quest/tonlight") == 1) {
            do_chat(({
                (: command, "say �A�w�g�b���ڤF�I" :),
                (: command, "say ���Q���N���u�����v" :),
            }));
            return;
        }
        this_player()->add_temp("quest/tonlight", 1);
        do_chat(({
            (: command, "jump" :),
            (: command, "say ���N�·ЧA�F�C" :),
            (: command, "say �]���j�D�Y�]�b��o�ӿOŢ�C" :),
            (: command, "say �ҥH�����N�o�Ӥɮ欰�ѯť��ȤF�C" :),
        }));
        return;
    }
    if( arg == "����" )  {
        if( this_player()->query_temp("quest/tonlight") < 1) {
            do_chat(({
                (: command, "?" :),
                (: command, "say �A�������ڶܡH" :),
            }));
        } else {
        this_player()->delete_temp("quest/tonlight");
            do_chat(({
                (: command, "glare" :),
                (: command, "say �쩳�֯ள��o�ӿOŢ�O..." :),
            }));
            return;
        }
    }
}
int give_check(object ob)
{
    if( ob->id("_TONBELI_A_") ) return 1;   // �q���Q�OŢ
    else return 0;
}
int accept_object(object me, object ob)
{
    int amount;
    object item;

    amount = ob->query_amount();

    if( is_busy() ) {
        do_chat((: command, "say �����I�����I" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say ���ڸѨM�L�A���I" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/tonlight") != 1) {
                do_chat((: command, "say �A�������ڶܡH" :));
                return 0;
            }
            amount = ob->query_amount();
            message_vision("$N���L$n�ᰪ�������C\n"NOR, this_object(), ob);
            do_chat( ({
               (: command, "pat" :),
               (: command, "say �Ӧn�աI" :),
               (: command, "say �D�`���§A�������A�o�O����I" :),
               ( : destruct , ob : ),
            }) );
            tell_object(me, "( "HIY+amount*15000+HIG" ��Ȥl�w�g�۰ʦs�b�Ȧ�̡C"NOR")\n");
            tell_object(me, HIY"�ѯť���"NOR"�W�[�F("HIY+amount+NOR")�I�C\n");

            me->add("bank", amount*15000);

            // �[c�ť���
            me->gain_score("clevel", amount);

            // �����Ȧs�����
            me->delete_temp("quest/tonlight");
            break;
        default:
            do_chat((: command, "say �o���O�OŢ���I" :));
            return 0;
            break;
    }
    return 1;
}
