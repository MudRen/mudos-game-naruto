#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(BLU"�p���B"NOR, ({ "blue shark","shark" }) );
    set_race("beast");
    set_level(29);

    set("long", "�@���p�T���A�p�p�����ݰ_�ӴN�ܱ��ˤO�A����e�A�٬O���ְk�a!�C\n");

    set("limbs", ({ "���I", "���_", "���Y", "����", "����" }) );
    set("verbs", ({ "bite" }) );
    
    set("attitude", "aggressive");         // �D�ʧ���

    setup();

    carry_money("silver", 100);
    if( random(100) > 95 ) carry_object("/world/area/wuyin/eq/shark head")->wear();
}

