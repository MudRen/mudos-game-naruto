#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�F�]����", ({ "yan mo han ba" , "ba" }) );
    set_race("human");
    set_level(80);
    set("long", "�λ�Ĥ@�����]�ڧg�D�A�ͤ_�F���B���]�F�����@���Q�D�A�]�g�ө�Ż�i�Ѯ��A\n"
                "�g�Ƥ��a���N�R�A�Z�\�Q�D�����A�{�ĮɾեH�j�N��ߡB\n"
                "��D�}�����ԳN�A�˲v�]�ɥ��W���N�A�H���諸�j�����ҩ���C\n");
    set("age",999);
    set("title", "�����]�g");
    setup();
    //carry_object(__DIR__"eq/blade.c")->wield();
}
