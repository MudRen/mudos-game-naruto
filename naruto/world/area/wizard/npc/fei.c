#include <npc.h>

void create()
{
    set_name("�O�m�u", ({ "fei fei duan", "fei", "duan" }) );
    set_race("human");
    set_level(40);
    set("age", 65);
    set("title", "�s��ɮv");
    set("long", "�t�@��s�⪺�ɮv�A�L��q�j�y�A���L�ä����ɥ��󪺧ޯ�C\n");
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "�ǯQ�ʭ��ԩI" )  {
        do_chat( ({ 
            (: command, "say �o�y���N��O�G�e�i�@�B�n�h���B�C" :),
            (: command, "say �ڪ������O�G�����Ӱh�C" :),
        }) );
        return;
    }
    if( arg == "�����ή����ռK" )  {
        do_chat( ({ 
            (: command, "say �o�y���N��O�G���¯����|��ӫ��C" :),
            (: command, "say �ڪ������O�G�g�۪��������@�C" :),
        }) );
        return;
    }
    if( arg == "�F�ڭ��I�j�ԥ���I" )  {
        do_chat( ({ 
            (: command, "say �o�y���N��O�G���j���ѡI��ť�ڭ̪��@��I" :),
            (: command, "say �ڪ������O�G���v���E�V�ߤO����k�C" :),
        }) );
        return;
    }
    if( arg == "�Q�\�Q�\��Ĭ��Ĭ" )  {
        do_chat( ({ 
            (: command, "say �o�y�u�O�L��o�X���n���Ӥw�C" :),
        }) );
        return;
    }
    if( arg == "�ŷf�ԧ��ԧ�" )  {
        do_chat( ({ 
            (: command, "say �o�y���N��O�G�ǩӥj�Ѫ��ֵ��C" :),
            (: command, "say �ڪ������O�G�n���S����N��C" :),
        }) );
        return;
    }
    if( arg == "�w�s�_�i�ȪL" )  {
        do_chat( ({ 
            (: command, "say �o�y���N��O�G���k��O�T��C�C" :),
            (: command, "say �ڪ������O�G�k�J�l�񥪺J�l�h�C" :),
        }) );
        return;
    }
}
