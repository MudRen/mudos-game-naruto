#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�j�͵��l", ({ "she sheng tong zi" , "zi" }) );
    set_race("human");
    set_level(75);
    set_attr("str", 50);
    set_attr("con", 50);
    set_attr("dex", 50);
    set_attr("int", 50);
    set_stat_maximum("ap",1000);
    set_stat_maximum("hp",1000);
    set_stat_maximum("mp",1000);
    set("long","�����]�g���U�Y�����N�A�����n�۩_�S���ʦL�A����T�ϴu�A\n"
                "�M���@�Y���j�T�~�A��u�۲��Ŷ����j�͹D�C\n"
                "�@���T�ϴ��ʡA�b�ɹq�y���{�A�N��L�ɪ������C\n");
    set("age",30);
    set("title", "�j�͹D�u����");
    setup();
    carry_object(__DIR__"eq/pike.c")->wield("twohanded");
    set_skill("combat",50);
    set_skill("parry",50);
    set_skill("dodge",50);
    set_skill("savage hit",50);
    set_skill("continual hit",50);
    set_skill("heavy hit",50);
    set_temp("apply/attack",-100);         // �����O�q

}

