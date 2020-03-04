#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�G����", ({ "jelly chicken","chicken"  }) );
    set_race("beast");
    set_level(1);

    set("long", "������S�����i�R������p���A���b�����ꪺ���W�A�@�ѥi�H�J��n�X�ӡC\n");

    set("limbs", ({ "���a", "����", "���L", "������", "����" }) );
    set("verbs", ({ "bite" }) );
 
    set("chat_chance", 3);
    set("chat_msg", ({
        "�G��������A�����ǸC�j���ݵۧA�C\n",
        "�G�������p�Ĥl�������۸���.\n",
        "�G�����}�l�ʵۤp�L�˥i�R\n",
                (: random_move :),
        }));

    setup();
    // �d�z
    set_temp("apply/attack", -5);         // �����O�q
    set_temp("apply/defend", -5);         // ���m�O�q
    set_temp("apply/exact", -5);          // �R���v
    set_temp("apply/evade", -5);          // �j�ײv
    set_temp("apply/intimidate", -5);     // ������O
    set_temp("apply/wittiness", -5);      // ���m��O

    carry_money("silver", 1);
    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/jelly.c");

}

