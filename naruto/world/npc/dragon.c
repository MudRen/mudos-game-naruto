#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("���s���֤����Y", ({ "long skin of the dragon", "dragon" }));

    set_race("beast");
    set_level(39);

    set("age", 150);

    set("title", "�n��");

    set("long", "�Y�֫ܪ����@���s�A�Y���Q�\��F�A�����^�^�������ݤ�����C\n");

    set("limbs", ({ "�s�Y", "����", "�{�l", "�s�}", "����", "�s�I", "�s��" }) );

    set("verbs", ({ "bite" }) );

    setup();
}
