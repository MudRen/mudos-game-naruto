#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("���ѽ�", ({ "flying pig","pig" }) );
    set_race("beast");
    set_level(20);

    set("long", "�@���M�½ޤ��@�˪����ѥսޡA�`���½ޤ��O�D�l��²���O���Q�B���@�ʨB�C\n");

    set("limbs", ({ "�Y��", "������", "����", "����" }) );
    set("verbs", ({ "bite" }) );
    
    set("attitude", "aggressive");         // �D�ʧ���

    setup();


}
