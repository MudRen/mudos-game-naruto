#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�j�͵��l", ({ "she sheng tong zi" , "zi" }) );
    set_race("human");
    set_level(75);
    set("long","�����]�g���U�Y�����N�A�����n�۩_�S���ʦL�A����T�ϴu�A\n"
                "�M���@�Y���j�T�~�A��u�۲��Ŷ����j�͹D�C\n"
                "�@���T�ϴ��ʡA�b�ɹq�y���{�A�N��L�ɪ������C\n");
    set("age",30);
    set("title", "�j�͹D�u����");
    setup();
    carry_object(__DIR__"eq/pike.c")->wield("twohanded");

}

