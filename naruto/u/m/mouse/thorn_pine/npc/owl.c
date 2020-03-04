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
void do_fight(string arg)
{
    string area_file = "/u/m/mouse/thorn_pine/waterfall.c";
    int damage;
    object enemy, area;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("$N"HIY"�i�j�ͻH���ʡI�o�X�g��ŧ�V"NOR"$n"HIY"�I\n"NOR, this_object(), enemy);
    damage = 50+random(151);
    if( random(enemy->query_ability("wittiness")) > 200 ) {
        message_vision("        $n��í�F���l�S�Q�g���ҧj�ʡI(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    if( !objectp(area = load_object(area_file)) ) {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�Q�j�F�_�ӡA�����^�b�a�W�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        enemy->start_busy(1);
        return;
    }
    if( !area->is_area() ) {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�Q�j�F�_�ӡA�����^�b�a�W�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        enemy->start_busy(1);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n���l�Q�g���ұ��_�A���������F�X�h�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    if( !area_move(area, enemy, random(20), 26+random(15)) ) {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�Q���ռv�T�A�̫᭫�����^���b��a�C", this_object(), enemy);
        enemy->start_busy(1);
        return;
    }
    message_vision("$N�q�ѤW���F�U�ӡA�@�ɵL�k���ʡC\n", enemy);
    enemy->start_busy(2);
    return;
}
void create()
{
    set_name("�a����", ({ "fly owl", "owl" }) );
    set_race("beast");
    set("title", HIY"�p���l����" NOR);
    set_level(40+random(6));
    set("age", 100+random(251));
    set("long", @LONG
�����q��B���Ӫ����t���l���A�ͩʳ��w�����j�B�W�ɮ�y�j�P���a
��A�o�F���r���N���n�����F�e�̨̳Ϊ��Ϯ����a�C���س����]���M
��Ϯ��a�D�`���e���A�ҥH�C��e�̧��@�B�Ϯ����a��A�K�|�ܺ�
�ү઺�����쥻�Ϯ��b��a������ͪ��C
LONG);

    set("limbs", ({ "�Y��", "����", "�{�l", "�ͻH", "����", "���L", "�I��" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":63, "amount":1, "p1":30, "p2":100 ]),  // ���L
        ([ "type":"obj", "id":27, "amount":5+random(16), "p1":100, "p2":100 ]), // �Ф�
        ([ "type":"eq", "id":84, "amount":1, "p1":1, "p2":600 ]),   // �����l
        ([ "type":"eq", "id":83, "amount":1, "p1":1, "p2":100 ]),   // ������
        ([ "type":"obj", "id":67, "amount":1, "p1":20, "p2":100 ]), // ������
        ([ "type":"obj", "id":68, "amount":1+random(5), "p1":40, "p2":100 ]), // ����
    }) );
    setup();
}
