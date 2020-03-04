#include <ansi.h>
#include <npc.h>

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
    object enemy;
    int damage;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    damage = random(this_object()->query_ability("attack") + this_object()->query_ability("intimidate")) + random(50) + 50;
    damage -= random(enemy->query_ability("defend") + enemy->query_ability("wittiness"));
    message_vision("$N"HIR"�i�j�L�ڤ@�R�A�~�M�Q�X�@�ά���G��I\n"NOR, this_object(), enemy);
    if( damage <= 0 || random(enemy->query_ability("intimidate")) > 100) {
        message_vision("        $n�V����@���A��a�����@�n�_�_���ϡC(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    enemy->damage_stat("hp", damage, this_object());
    message_vision("        $n�Q�G��Q��Aı�o�����n������T�׿N�ˡC("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void create()
{
    set_name(RED"�j��ӦZ"NOR, ({ "queen spider", "spider" }) );
    set_race("beast");
    set("title","���v�j��");
    set_level(30);
    set("long", "���l�����j�ﳣ�٭n���j�A�������Q�X�����n���n�N�A�ͧ]�C\n");
    set("limbs", ({ "�j�Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),       // �j��L
        ([ "type":"obj", "id":81, "amount":1, "p1":80, "p2":100 ]),       // �j��Х�
        ([ "type":"obj", "id":80, "amount":1+random(4), "p1":70, "p2":100 ]), // �H�G
        ([ "type":"food", "id":19, "amount":1, "p1":5, "p2":100 ]),       // �d�J�ԤY
        ([ "type":"eq", "id":91, "amount":1, "p1":1, "p2":600 ]),         // �}�˿�
        ([ "type":"eq", "id":92, "amount":1, "p1":5, "p2":100 ]),         // �j����
        ([ "type":"food", "id":17, "amount":1, "p1":5, "p2":100 ]),       // ��O�Y
    }) );
    setup();
    set_skill("combat", 120);
    set_skill("dodge", 120);
    set_skill("parry", 120);
    set_skill("savage hit", 120);
    set_skill("heavy hit", 120);
    set_skill("continual hit", 120);
}
