#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

int i;

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
    if( this_object()->query_temp("quest/force_sk") == 1) {
        message_vision("$N�۵۰��B�A�@�ۡy"HIR"�Y��"NOR"�z���V$n�ݤf�I\n"NOR, this_object(), enemy);
        damage = 20+random(56);
        if( random(enemy->query_ability("intimidate")) > 100) {
            message_vision("        $n�H�X�g��ƸѤF��աC(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(2);
            return;
        }
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�u�I�I�v�a�@�n�h��X�B�A�L���٬y�X�A��C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        return;
    } else
    if( this_object()->query_temp("quest/psy_sk") == 1) {
        message_vision("$N�N���������x�A�@���u"HIY"����i"NOR"�vŧ�V$n�I\n"NOR, this_object(), enemy);
        damage = 20+random(56);
        if( random(enemy->query_ability("intimidate")) > 100) {
            message_vision("        $n���P���N���O�����F�C(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(2);
            return;
        }
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�u�F�I�v�Q�İh�F�X�B�A�L���٬y�X�A��C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        return;
    }
    return;
}
void create()
{
    set_name("�\�H�o��", ({ "bow criminal", "criminal" }));
    set_race("human");
    set_level(25+random(11));
    set("age", 5+random(81));
    set("limbs", ({ "�Y��", "����", "����", "�L��", "����", "�զ�", "�ӳ�", "�I��" }));
    set("long", "�ǤF���W���\�H�A���b�F���r�o�̱����B�@�C\n");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: random_move :),
        (: command, "jump �r��" :),
        (: command, "climb �r��" :),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":45, "amount":1, "p1":20, "p2":100 ]),  // ��C
        ([ "type":"wp", "id":33, "amount":1, "p1":10, "p2":100 ]),  // �j���
        ([ "type":"wp", "id":41, "amount":1, "p1":10, "p2":100 ]),  // ���M
        ([ "type":"wp", "id":39, "amount":1, "p1":1, "p2":100 ]),   // �n�j
        ([ "type":"wp", "id":36, "amount":1, "p1":1, "p2":150 ]),   // �课�C
    }) );
    i = random(2)+1;
    if( this_object()->query("level") >= 30 ) {
        if( i == 1 ) {
            this_object()->add_temp("quest/force_sk", 1);
        } else
        if( i == 2 ) {
            this_object()->add_temp("quest/psy_sk", 1);
        }
    }
    setup();
}
