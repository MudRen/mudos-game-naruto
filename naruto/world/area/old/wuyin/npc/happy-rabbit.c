#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIW"�����"NOR, ({ "happy rabbit","rabbit"  }) );
    set_race("beast");
    set_level(10);

    set("long", "����߱ڬO�@�s���⪺�ߤl�A�Ⱝ���R�R����b�I��A����o�A�������a�ơH\n");

    set("limbs", ({ "�ߦ�", "����", "����", "����", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
 
    setup();

    if( random(100) > 0 ) carry_object("/world/area/wuyin/wp/chopping-knife.c")->wield("righthand");
    if( random(100) > 0 ) carry_object("/world/area/wuyin/eq/false-teeth.c")->wear();
    if( random(100) > 85 ) carry_object("/world/area/wuyin/eq/steel-teeth.c");

}
