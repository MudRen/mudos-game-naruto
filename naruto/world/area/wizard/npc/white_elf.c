#include <ansi.h>
#include <npc.h>

void create()
{
    set_name(HIW"�պ��F"NOR, ({ "white elf", "elf" }));
    set_level(1);
    set_race("beast");
    set("verbs", ({ "bite" }) );
    set("long", "�b�p���զ���F�A���祴�ۯͻH�w�w���R�C\n");
    set("limbs", ({ "�Y��", "����", "�L��", "�ͻH", "��A" }) );
    // �H������
    set("chat_chance", 30);
    set("chat_msg", ({
        (: random_move :),
    }));
    setup();
    add_temp("apply/hp", 300);
    add_temp("apply/ap", 300);
    add_temp("apply/mp", 300);
    do_heal();
}
void die()
{
    object enemy;
    int i;
    enemy = this_object()->last_damage_giver();
    if( !enemy ) {
        destruct(this_object());
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            destruct(this_object());
            return;
        } else
        if( environment(enemy) != environment(this_object()) ) {
            destruct(this_object());
            return;
        }
    }
    i = enemy->query_level()*5 + random(20);

    // ����@�U�i�H�������ŧa�A�K�o�s��Q�m��
    if( i > 70 ) i = 70;
    if( enemy->query_level() > 15 ) i = 1;
    else if( enemy->query_point("learn") > 100000 ) {
        tell_object(enemy,RED"\n�A�����I�W�L�F�Q�U�I�A�]�����I�u�����@�I�C\n"NOR);
        i = 1;
    }

    enemy->add_temp("ELF_HOUSE", 1);
    tell_object(enemy,HIW"\n�պ��F�Ƭ���������A�絹�F�A"HIY"["HIC+chinese_number(i)+HIY"]"HIW"�I���I�C\n\n"NOR);
    enemy->add_point("learn", i);
    if( enemy->query_temp("ELF_HOUSE") >= 20 ) {
        message_vision(CYN"���F�̹�$N�P��`�ȡA�N$N���X���F�����F�C\n"NOR, enemy);
        enemy->move("/world/area/wizard/elf_door.c");
    }
    destruct(this_object());
    return;
}
