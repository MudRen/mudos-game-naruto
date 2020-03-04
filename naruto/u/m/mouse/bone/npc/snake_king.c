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
    message_vision("$N"HIW"���_���j�@�ݡA�p�F�D�몺�W�V"NOR"$n"HIW"�|�����`�B�I\n"NOR, this_object(), enemy);
    damage = this_object()->query_ability("attack") + this_object()->query_ability("intimidate") + random(100);
    damage -= random(enemy->query_ability("defend") + enemy->query_ability("wittiness"));
    if( random(this_object()->query_ability("exact")) - random(enemy->query_ability("evade")) <= 0) {
        message_vision("        $n�ֳt���{�L�F�����I�u�O�n�I�C(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n�Q�W�X�|�Ӧ�}�A�@�ɶ����H�����C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    enemy->start_busy(1);
    return;
}
void create()
{
    set_name("�D��", ({ "snake king", "snake", "king" }) );
    set_race("human");
    set("gender", "male");
    set_level(45);
    set("age", 35);
    set("limbs", ({ "�D�Y", "�D��", "����", "�ݤf", "�}��", "�ӻH", "�y��" }) );
    set("title",HIW"�D�ڬӫ�"NOR);
    set("long", "����@����ܭ��A��W���ۤ@��զ⪺���j�A�ݰ_�ӫܫ­��C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "say �D�ڬO�̰��j���رڡI" :),
        (: command, "nomatch" :),
        (: command, "say �`���@�ѤѤU�|�H�D�ڬ��L�I" :),
    }));
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":5, "p2":100 ]),     // �D������
        ([ "type":"wp", "id":47, "amount":1, "p1":1, "p2":800 ]),     // �լӳD�j
        ([ "type":"wp", "id":49, "amount":1, "p1":15, "p2":100 ]),    // �s�M
        ([ "type":"wp", "id":48, "amount":1, "p1":20, "p2":100 ]),    // �޼C
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // �D��
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // �D�r
    }) );
    setup();
}
