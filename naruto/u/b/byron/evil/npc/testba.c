#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�F�]����", ({ "yan mo han ba" , "ba" }) );
    set_race("human");
    set_level(80);
    set_attr("str", 50);
    set_attr("con", 50);
    set_attr("dex", 50);
    set_attr("int", 50);
    set_stat_maximum("ap",1000);
    set_stat_maximum("hp",1000);
    set_stat_maximum("mp",1000);
    set("long","�λ�Ĥ@�����]�ڧg�D�A�ͤ_�F���B���]�F�����@���Q�D�A�]�g�ө�Ż�i�Ѯ��A\n"
                "�g�Ƥ��a���N�R�A�Z�\�Q�D�����A�{�ĮɾեH�j�N��ߡB\n"
                "��D�}�����ԳN�A�˲v�]�ɥ��W���N�A�H���諸�j�����ҩ���C\n");
    set("age",999);
    set("title", "�����]�g");
    setup();
    set_skill("combat",50);
    set_skill("parry",50);
    set_skill("dodge",50);
    set_skill("savage hit",50);
    set_skill("continual hit",50);
    set_skill("heavy hit",50);
    set_temp("apply/attack",0);         // �����O�q
    set_temp("apply/armor",0);         // ���m�O�q
    set_temp("apply/intimidate",0);     // ������O
    set_temp("apply/wittiness",0);      // ���m��O
    set_temp("apply/exact",0);          // �R���v
    set_temp("apply/evade",0);          // �j�ײv
        
}

