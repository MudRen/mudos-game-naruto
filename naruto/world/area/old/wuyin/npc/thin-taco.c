#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIY"���Y����"NOR, ({ "thin taco","taco" }) );
    set_race("beast");
    set_level(32);

    set("long", "���G�p�㪺�����A�M�λL���O�@�j���A�t�ײ��ʫD�`���֡A�����L���٤��ɯd�X���ġC\n");

    set("limbs", ({ "Ĳ�}", "�L��", "�Y��", "����" }) );
    set("verbs", ({ "bite" }) );
 
    setup();

    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/taco-burn.c");
    if( random(100) > 70 ) carry_object("/world/area/wuyin/eq/octopus-cap.c")->wear();
    if( random(100) > 70 ) carry_object("/world/area/wuyin/eq/eyepatch.c")->wear();
    if( random(100) > 95 ) carry_object("/world/area/wuyin/wp/pirate-blade.c");

}
