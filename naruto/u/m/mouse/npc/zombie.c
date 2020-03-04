#include <npc.h>
#include <ansi.h>

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$N" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$N" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$N" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_vemon(object enemy)
{
    int damage, i;
    object* targets;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("$N"HIM"�Q�X�j�q���ͬr�A�v�T�|�P���ĤH�I\n"NOR, this_object());
    for(i=0;i<sizeof(targets);i++) {
        if( i > 2) break;   // ��T�ӤH����
        damage = random(this_object()->query_attr("str")) + random(this_object()->query_attr("con"));
        if( random(targets[i]->query_skill("dodge")) > random(this_object()->query_skill("dodge"))) {
            message_vision("        $N���t�����}�F�ͬr���d��I(0)"+report_status(targets[i])+"", targets[i], this_object());
            this_object()->start_busy(1);
        } else {
            targets[i]->damage_stat("hp", damage, this_object());
            message_vision("        $N�l�J�F�j�q���ͬr�A�y��o���������æR�ۡC("+damage+")"+report_status(targets[i])+"", targets[i], this_object());
        }
    }
}
void check_hp()
{
    if( this_object()->query_stat_current("hp") <= 10 ) {
        message_vision(HIK"\n$N�Ө���������A�u�y�v�a�@�n�Ƭ��Фg�F�C\n"NOR, this_object());
        destruct(this_object());
    }
}
void create()
{
    set_name("�L��", ({ "zombie" }));
    set_race("beast");
    set("no_zombie", 1);
    set("long", "����S���@�Ӧa��O���㪺�A�ݰ_�ӴN���@�����C\n");
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
       (: do_vemon :),
    }) );
    set("chat_msg", 100);
    set("chat_msg", ({
       (: check_hp :),
    }));
    call_out("die_1", random(100)+200, this_object());
    setup();
}
void die_1()
{
    message_vision(HIY"�ũG����q�������h�A"NOR"$N"HIY"�Ƭ��ǹЦ^�k�j�a�C\n"NOR, this_object());
    destruct(this_object());
    return;
}
void unconcious()
{
    this_object()->die();
    return;
}
void die()
{
    message_vision(HIK"\n$N�Ө���������A�u�y�v�a�@�n�Ƭ��Фg�F�C\n"NOR, this_object());
    destruct(this_object());
    return;
}
