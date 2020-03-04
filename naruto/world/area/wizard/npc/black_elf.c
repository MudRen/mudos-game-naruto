#include <ansi.h>
#include <npc.h>

void create()
{
    set_name(HIK"�º��F"NOR, ({ "black elf", "elf" }));
    set_level(1);
    set_race("beast");
    set("verbs", ({ "bite" }) );
    set("long", "�b�p���¦���F�A�@�y���c���ˤl��B�]�����C\n");
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
    object enemy, item;
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
    i = enemy->query_level()*20 + random(160);
    item = new("/obj/money/silver.c");

    // ����@�U�i�H�������ŧa�A�K�o�s��Q�m��
    if( i > 360 ) i = 360;
    if( enemy->query_level() > 15 ) i = 1;
    else if( enemy->query("bank") > 500000 ) i = 1;

    item->set_amount(i);

    enemy->add_temp("ELF_HOUSE", 1);
    if( environment(enemy)->is_area() ) {
        if( !area_move(environment(enemy), item, enemy->query("area_info/x_axis"), enemy->query("area_info/y_axis")) ) {
            tell_object(enemy,HIK"\n�º��F���c�����F�X�n�A�������������F�C\n\n"NOR);
        } else tell_object(enemy,HIK"\n�º��F�N�a�@�n���b�a�W�A�Ƭ�"HIR"["HIY+chinese_number(i)+HIR"]"HIK"��Ȥl�C\n\n"NOR);
    } else if( item->move(environment(enemy)) ) {
        tell_object(enemy,HIK"\n�º��F�N�a�@�n���b�a�W�A�Ƭ�"HIR"["HIY+chinese_number(i)+HIR"]"HIK"��Ȥl�C\n\n"NOR);
    } else {
        tell_object(enemy,HIK"\n�º��F���c�����F�X�n�A�������������F�C\n\n"NOR);
    }
    if( enemy->query_temp("ELF_HOUSE") >= 20 ) {
        message_vision(CYN"���F�̹�$N�P��`�ȡA�N$N���X���F�����F�C\n"NOR, enemy);
        enemy->move("/world/area/wizard/elf_door.c");
    }
    destruct(this_object());
    return;
}
