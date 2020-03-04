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
    set("long","�츭�����Ԫ̡A���G���b���H�����U�L�C\n");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: command, "say �e�U���OŢ���ȫ�򳣨S�H�n�����O...":),
    }));
    setup();
}
void relay_say(object ob, string arg)
{
    object item;

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
            (: command, "say ����񪺡y�e���Գ��z��u�˨��@�ڡv" :),
            (: command, "say �L�̬O�j�D�Y�X�U���@��ڸs�C" :),
            (: command, "say �j�D�Y�N�O���L�̥h���OŢ���A�ҥH�ݥL�����ӷ|��M���C" :),
        }));
        return;
    }
    if( arg == "�e���Գ�" || arg == "�˨��@��" )  {
        do_chat(({
            (: command, "hmm" :),
            (: command, "say �a�Ϸ|�ݧa�H" :),
            (: command, "say �N�O help world �աC" :),
            (: command, "say �e���Գ��N�b���W���C" :),
            (: command, "say �˨��@�ڷ�M�N�b����C" :),
            (: command, "ah" :),
            (: command, "say ��F..." :),
            (: command, "say �d�U�O��˨��@�ڪ��H�_�Ĭ��..." :),
            (: command, "say �L�̥H�e�Q�٬��c�]�@��..�O�ܦM�I���ڸs�C" :),
        }));
        return;
    }
    if( arg == "�Ѯ�w����" )  {
        item = new("/world/area/ship/npc/item/paper.c");
        if( item->move(this_player()) )
            tell_object(this_player(), HIY"(�A��o�F�@�i�Ѯ�w����C)\n"NOR);
        else {
            if( environment(this_player())->is_area() ) move_side(item, this_player());
            else item->move(environment(this_player()));
            tell_object(this_player(), HIY"(�A��o�F�@�i�Ѯ�w����A���O���b�a�W�F�C)\n"NOR);
        }
        do_chat(({
            (: command, "say �Q�n���D�̪�Ѯ�H" :),
            (: command, "say �o�N�O���A���h�a�C" :),
        }));
        return;
    }
}
