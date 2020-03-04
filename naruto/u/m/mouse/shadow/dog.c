#include <npc.h>
#include <ansi.h>

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight()
{
    int damage;
    object enemy;
    string msg;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("$N"CYN"�L�L�s�F�X�n�A�q�L�̦��X�@��"HIY"�Ӻֺj"NOR+CYN"���"NOR"$n"CYN"�@�j�F�h�I\n"NOR, this_object(), enemy);
    damage = this_object()->query_ability("attack");
    damage += random(50);
    if( random(enemy->query_ability("evade")) > 100) {
        message_vision("        $n�ֳt�q�@���׶}�I(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(3);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n�Q�l�u�����A�n�����F�I�ˡI("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    enemy->start_busy(2);
    return;
}
void do_drop()
{
    object enemy;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("$N"HIR"�w�F�U�ӡA�I�W���}�����A�C�C�q�̭��X�{�@���p�����u�I\n"NOR, this_object(), enemy);
    this_object()->start_busy(5);
    call_out("drop_1",10,this_object(),enemy);
}
void drop_1()
{
    int damage;
    object enemy;
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    damage = 100 + random(300);
    message_vision(HIG"�u�ؼЮե��v"HIR"���u�I�I���@�n��"NOR"$n"HIR"�e�g�ӥh�I\n"NOR, this_object(), enemy);
    if( random(enemy->query_ability("evade")) > 200) {
        message_vision("        �u�F���v�@�n���T�A$n���}�F�z���d��I(0)"+report_status(enemy)+"\n"NOR, this_object(), enemy);
        enemy->start_busy(3);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        �u�F���v�@�n���T�A$n�Q�����J���F�I("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    enemy->start_busy(6);
    return;
}
void create()
{
    set_name("�Ӻ�", ({ "rifle", "dog" }));
    set_race("beast");
    set_level(40);
    set("title",HIY"�j�a����"NOR);
    set("age", 10);
    set("long", "�A�n���Ӻ֡�@���������P�츭�����G�ơC\n");
    set("limbs", ({ "���Y", "����", "����", "���L", "����", "�զ�" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "dog" :),
    }) );
    // �԰��ʧ@
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: do_fight :),
        (: do_fight :),
        (: do_drop :),
    }) );
    setup();
    add_temp("apply", (["hp":7799, "attack":-100 ]) );
    do_heal();
}
int give_check(object ob)
{
    if( ob->id("_BOW_LU_") ) return 1;           // �_��
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say �ڥ����ۡC" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �԰����C" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( ob->query_amount() > 1 ) {
                return 0;
            }
            do_chat(({
               (: command, "dog" :),
               (: command, "follow " + this_player()->query("id") :),
               (: command, "guard " + this_player()->query("id") :),
            }));
            break;
        default:
            do_chat((: command, "dog" :));
            return 0;
            break;
    }
    return 1;
}
