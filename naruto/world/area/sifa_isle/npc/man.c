#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�o��", ({ "culprit" }) );
    set_race("human");
    set_level(1);
    set("age", random(20)+15);
    set("long", "�쥻���ӬO�Ӥj�c�H�A���O�Q�e�ӥq�k�q���ե��S�F�A�{�b�]�\�s\n"
                "�Ӥp�Ĥl���໴�P���ѥL�C\n");

    // �@��ɰʧ@
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "sigh" :),
        (: command, "say �ڤ��Q�i�`���j�ʺ���..." :),
    }) );
    setup();
}
