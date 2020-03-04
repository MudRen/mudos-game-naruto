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
    int damage;
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
    if( this_object()->query_temp("quest/snake_blade") == 1) {
    return;
    }
    message_vision("$N"HIG"�����s�M�¦a�W�@���A���_�a�W��֥۶�����"NOR"$n"HIG"�C\n"NOR, this_object(), enemy);
    damage = 20+random(36);
    if( random(enemy->query_ability("intimidate")) > 120) {
        message_vision("        $n�N�۶���֥����A�~�����$N�C(0)"+report_status(enemy)+"", this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        �۶�����$n�⦣�}�áA���֦a�賣�Q�{�ˡC("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    this_object()->add_temp("quest/snake_blade", 1);
    call_out("blade_1",5,this_object(),enemy);
    return;
}
void blade_1()
{
    int damage;
    object enemy;
    enemy = this_object()->query_opponent();
    this_object()->delete_temp("quest/snake_blade");
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    damage = random(this_object()->query_ability("attack")) + random(101) + 30;
    damage -= random(enemy->query_ability("defend")) + random(150);
    message_vision("$N"HIY"�X�۶�����"NOR"$n"HIY"���ɡA���ձq���@�M�A�ӡI\n"NOR, this_object(), enemy);
    if( damage <= 0 || random(enemy->query_ability("intimidate")) > 80) {
        message_vision("        $n�����o��A���Q�ƸѦ��ۡC(0)"+report_status(enemy)+"\n"NOR, this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n�u��v�a�@�n�Q�s�M�夤�A�y���G���ˮ`�I("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void create()
{
    set_name("�ԳD", ({ "warrior snake", "snake" }) );
    set_race("human");
    set("gender", "male");
    set_level(33+random(3));
    set("age", 20+random(21));
    set("limbs", ({ "�D�Y", "�D��", "����", "�ݤf", "�}��", "�ӻH", "�y��" }) );
    set("title",HIG"�D�ھԤh"NOR);
    set("long", "����s�M�A���ۤ@�`��μC�ު��D�H�C\n");
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: command, "say ���I���d���f�I" :),
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":100 ]),     // �D������
        ([ "type":"wp", "id":49, "amount":1, "p1":1, "p2":300 ]),     // �s�M
        ([ "type":"wp", "id":48, "amount":1, "p1":1, "p2":275 ]),     // �޼C
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // �D��
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // �D�r
    }) );
    setup();
}
