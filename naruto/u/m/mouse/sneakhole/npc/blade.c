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
    damage = random(this_object()->query_ability("attack") + this_object()->query_ability("intimidate")) + random(20) + 1;
    damage -= random(enemy->query_ability("defend") + enemy->query_ability("wittiness"));
    message_vision("$N"HIG"���l�@�Y�A��ӭ��F�_�Ӽ��V$n�I\n"NOR, this_object(), enemy);
    if( damage <= 0 || random(enemy->query_ability("intimidate")) > 80) {
        message_vision("        $n�@�}��$N�{�l��F�U�h�A�h��$N�_�_�s�C"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
   message_vision("        $n�{�פ��γQ�Q�}���X�F�X�D�f�l�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void create()
{
    set_name(HIK"�Q�b�j��"NOR, ({ "blade spider", "spider" }) );
    set_race("beast");
    set("title","���v�j��");
    set_level(28);
    set("long", "�K���}���p�M�b�@��y�Q���������ܻj��C\n");
    set("limbs", ({ "�j�Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),       // �j��L
        ([ "type":"obj", "id":81, "amount":1, "p1":30, "p2":100 ]),       // �j��Х�
        ([ "type":"obj", "id":80, "amount":1, "p1":50, "p2":100 ]),       // �H�G
        ([ "type":"food", "id":19, "amount":1, "p1":5, "p2":100 ]),       // �d�J�ԤY
        ([ "type":"eq", "id":91, "amount":1, "p1":1, "p2":900 ]),         // �}�˿�
        ([ "type":"food", "id":17, "amount":1, "p1":5, "p2":100 ]),       // ��O�Y
    }) );
    setup();
    set_skill("combat", 110);
    set_skill("dodge", 110);
    set_skill("parry", 110);
    set_skill("savage hit", 110);
    set_skill("heavy hit", 110);
    set_skill("continual hit", 110);
}
