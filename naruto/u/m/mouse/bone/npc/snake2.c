#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

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
    int damage, i;
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
    i = random(3);
    if( i == 0 ) {
        message_vision("$N"HIR"���_����H��@���A�ֳt���X���u��"NOR"$n"HIR"�Y�ӡI\n"NOR, this_object(), enemy);
        if( random(this_object()->query_ability("attack")) > random(enemy->query_ability("defend")) ) {
            damage = 90;
        } else {
            damage = 1+random(90);
        }
        if( random(3) > 1) {
            message_vision("        ���O���u�����F�C(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(1);
            return;
        }
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        �u�F���v�@�n�A$n�Q�N���@��r�骺�¤H�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        return;
    } else
    if( i == 1) {
        message_vision("$N"HIC"���_�����"NOR"$n"HIC"�@���I�o�X��D�B�붶�ۤ����V�W�h�I\n"NOR, this_object(), enemy);
        if( random(this_object()->query_ability("attack")) > random(enemy->query_ability("defend")) ) {
            damage = 75;
        } else {
            damage = 1+random(75);
        }
        if( random(3) > 1) {
            message_vision("        ���O�B�뭸��@�b�N���ƤF�C(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(1);
            return;
        }
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        �u���j�v�@�n�A�B���W��$n���o�ݡC("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        enemy->start_busy(1);
        return;
    }
    message_vision("$N"HIW"���_������F�X�U�A�o�S�o�ͥ���ơC\n"NOR, this_object(), enemy);
    return;
}
void create()
{
    set_name("�ųD", ({ "wizard snake", "snake" }) );
    set_race("human");
    set("gender", "female");
    set_level(33+random(3));
    set("age", 20+random(41));
    set("limbs", ({ "�D�Y", "�D��", "����", "�ݤf", "�}��", "�ӻH", "�y��" }) );
    set("title",HIG"�D�ڧŮv"NOR);
    set("long", "����@�ڤ�����D�H�A�Y�W�a�ۤ@�����B��e�����C\n");
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: command, "say �����D�ڱj�j���O�q�I" :),
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":100 ]),     // �D������
        ([ "type":"wp", "id":51, "amount":1, "p1":1, "p2":200 ]),     // �D��
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // �D��
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // �D�r
    }) );
    setup();
}
