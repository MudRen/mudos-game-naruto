#include <npc.h>
#include <ansi.h>
#include "skill.h"

void create()
{
    set_name("�˨��褧��", ({ "wheya gon lon", "lon" }) );
    set_level(60);
    set_class("superior");
    set_race("human");
    set("gender", "male");
    set("camp", "wheya");
    set("age", 85);
    set("title",HIR"�˨��ڪ�"NOR);
    set("long",@LONG
�˨��ڪ��A�@�ӤK�Q�h�����p���Y�A���O�L�����U�Q�A�|�P���@����
�k���L�L�������C��~�˨��ڤH�Q�l���ɪ��˲������d�b���W�A����
�U�B�����j�j�p�p���˲��A���L�o�Ƕ˲��ݦ���αq�����~��������
�A�ڻ��˨��ڤH�֦����~���ɡA��N�ۤv���W�����Y�ޥX�A���M�|��
�ۤv�y���ˮ`�A�ҩޥX���Z���o����H�ߩҼ����ܤơA��@�몺�Z��
�٭n�n�ΡC�]�]���o�ˡA�ҥH�˨��@�ڤS�Q�٬��y�c�]�@�ڡz
LONG);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: do_check :),
        (: command, "say ���F�D�H�S�ӭөǪ�...":),
        (: command, "say �ڤH�����h��I�D�H�F�C":),
        (: command, "say �u�n�O�j�D�Y�j�H�U�I�����ȡA�@�w�n�����C":),
    }));
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":1+random(5), "p1":60, "p2":100 ]), // ����
        ([ "type":"obj", "id":78, "amount":1, "p1":100, "p2":100 ]),          // ���]����
        ([ "type":"wp", "id":50, "amount":1, "p1":1, "p2":200 ]),             // �ᰩ�C
        ([ "type":"eq", "id":85, "amount":1, "p1":1, "p2":150 ]),             // �G�L�Э�
    }) );
    setup();
}

void relay_say(object ob, string arg)
{
    if( arg == "�D�H" )  {
        do_chat(({
            (: command, "say �o�̸򯫼q�B�ԨƪL�B����h�A�H�e���O�D�H���a�L�C" :),
            (: command, "say �ڭ̨ӤF����I�_�e���Գ��A���e�̨�a�L�k���q�C" :),
            (: command, "say ���ۥ��O�����ԨƪL���̪��D�ڥ����C" :),
            (: command, "say �N�b�ڭ̩M�D�H��ѭѶˮ�...���M�]�X�@��Ǫ��C" :),
            (: command, "say ���ǩǪ���ڭ̩M�D�H���]�A�N���ڤF���̡C" :),
        }));
        return;
    }
    if( arg == "�Ǫ�" )  {
        do_chat(({
            (: command, "say �e�̦��ۺ�⪺����A�ٮ��ۤ@���M" :),
            (: command, "say �ڭ̳q�٨e�̥s�u�q���Q�v�C" :),
            (: command, "say �e�̲{�b�N�w�~�b�ԨƪL�C" :),
            (: command, "say �����e�̭n�p�ߡC" :),
            (: command, "say �e�̪����]�|���˦����q���q���Q�V�b�̭��C" :),
            (: command, "ah" :),
            (: command, "say �٦�...�ԨƪL�������ⶡ�}�ΡC" :),
            (: command, "say �q���Q�̦n�������@�N����䤤���@���C" :),
            (: command, "say ���n�ݬ�����A���D�o�Ӥ@�w��A�����U���C" :),
        }));
        return;
    }
    if( arg == "�j�D�Y" )  {
        do_chat(({
            (: command, "say �L�O�ڭ̦˨��@�ڪ����H�I" :),
        }));
        return;
    }
    if( arg == "�ڤH" )  {
        do_chat(({
            (: command, "say ��M�N�O�ڭ̦˨��@�ڡI" :),
        }));
        return;
    }
}

void die()
{
    string msg;
    object ob, *obs, enemy, killer;
    int i;

    obs = all_inventory(this_object());
    enemy = this_object()->last_damage_giver();
    i = random(3) + 2;

    if( !enemy ) {
        ::die();
        return;
    }

    if( this_object()->query_temp("quest/psychical") == 1 ) {
        message_vision("�]��$N�����ҥH"HIW"�ᰩ�C"NOR"�������ƤF...�C\n"NOR, this_object());
        this_object()->delete_temp("quest/psychical");
        foreach( ob in obs ) destruct(ob);
    }

    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n\n"RED"�j�D�Y�j�H�I�S�Q��ڤ����L�k�����z���J��\n\n�s�u�@�n�e���Գ��o���n�a��������I�ڷ\��z�������I";
    msg += HIR"\n\n�i���|�s�D�j"+this_object()->query("name")+"("+this_object()->query("id")+")�~�M�b�a�Q���K���e���Գ��ѵ��F"+enemy->query("name")+"("+enemy->query("id")+")�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A�����˨��褧����o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
}