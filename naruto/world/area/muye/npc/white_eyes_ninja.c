#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("��V�C�u", ({ "ninja" }));
    set_race("human");
    set_level(21);
    set_class("middle");  // ���� 
    set("long", "��V�a�ڪ��Ԫ̡A�]���X���ȦӨ��t���ˡA���Ӭ����L���ߤF..\n");

    set("title", HIW"��V�a��"NOR);
    set("age", 24);
    set("gender", "male");

    // �@��ɰʧ@
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "say �i�c�I...�y�y�I" :),
        CYN"��V�C�u�\�y�����A���G�D�`�h�W�C\n"NOR,
    }) );
    setup();
    set_stat_current("hp", 1);
}
