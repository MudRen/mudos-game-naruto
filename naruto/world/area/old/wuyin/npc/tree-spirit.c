#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(GRN"��p��"NOR, ({ "tree spirit","tree","spirit" }) );
    set_race("beast");
    set_level(17);

    set("long", "�Q���H�I�i�L�����k�N�ӷ|���������A�@���ĤH����N�|�۰ʧ����ĤH�C\n");

    set("limbs", ({ "��F", "��K", "���", "���Y", "��" }) );
    set("verbs", ({ "bite" }) );
    
    set("attitude", "aggressive");         // �D�ʧ���

    setup();

    if( random(100) > 60 ) carry_object("/world/wp/rattan.c")->wield("lefthand");
    if( random(100) > 60 ) carry_object("/world/wp/rattan.c")->wield("righthand");

}

