#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

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
    // �S���ĤH
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( i > 1 ) {
        message_vision("$N"HIG"�C�C���e���F�@�B�I\n"NOR, this_object(), enemy);
        i = i-1;
        message_vision("$N"HIG"�ٶZ��"NOR"$n ("HIY+i+NOR") "HIG"�B�I\n"NOR, this_object(), enemy);
        return;
    }
    message_vision("$N"HIR"����F"NOR"$n"HIR"���e�A�S�X�F�_�Ǫ��L��...\n"NOR, this_object(), enemy);
    damage = enemy->query_stat_maximum("hp")/10;
    damage += random(50);
    if( random(10) >= 7) {
        message_vision("        $N���_��M�ΤO���Ů�@�W...�����D�b�Fԣ...(0)"+report_status(enemy)+""NOR, this_object(), enemy);
        i = random(10)+1;
        message_vision("$N"HIG"�S��������F"NOR"$n ("HIY+i+NOR") "HIG"�B�I\n"NOR, this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $N���_��M��$n�@�W�A�P���@�n�A��|�q�C("+damage+")"+report_status(enemy)+""NOR, this_object(), enemy);
    i = random(10)+1;
    message_vision("$N"HIG"�S��������F"NOR"$n ("HIY+i+NOR") "HIG"�B�I\n"NOR, this_object(), enemy);
    return;
}
void do_garbage()
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
    message_vision("$N"HIW"�q�h�̮��X�@��U����"NOR"$n"HIW"�å�C\n"NOR, this_object(), enemy);
    damage = enemy->query_ability("intimidate")*2 + random(100);
    if( random(5) == 0) {
        message_vision("        $N�O�D�ӻ��U������n�F...(0)"+report_status(enemy)+""NOR, this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n�Q�U���{�����R�ۮQ��B�k«�C("+damage+")"+report_status(enemy)+""NOR, this_object(), enemy);
    return;
}
void do_light()
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
    if( this_object()->query_temp("quest/lightlight") == 1) {
    return;
    }
    message_vision("$N"HIG"�n�̵ۿOŢ..���ۤv���W�@�ӡC\n"NOR, this_object(), enemy);
    this_object()->add_temp("quest/lightlight", 1);
    if( random(5) <= 1) {
        enemy->heal_stat("hp", 200);
        message_vision("        ���G$N�^�F�@��...���Ө�$n���U$n�^�_��O(200)"+report_status(enemy)+""NOR, this_object(), enemy);
        call_out("light_1",20,this_object(),enemy);
        return;
    }
    this_object()->heal_stat("hp", 400);
    message_vision("        �j���Ӧb$n���W���U�^�_��O�C(400)"+report_status(this_object())+""NOR, enemy, this_object());
    call_out("light_1",20,this_object(),enemy);
    return;
}
void light_1()
{
    this_object()->delete_temp("quest/lightlight");
}
void create()
{
    set_name("�q���Q", ({ "tonbeli" }));
    set_race("human");
    set_level(30);
    set("nickname",HIG"��M��"NOR);
    set("age", 10+random(21));
    set("long","��ⴣ�ۿOŢ���p���ǡA��W���ۤ@��_�Ǫ���M�C\n");
    if( random(2) == 1) {
        set("gender", "female");
    } else {
        set("gender", "male");
    }
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
        CYN"�q���Q�w�w������...\n"NOR,
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"food", "id":23, "amount":1, "p1":30, "p2":100 ]),   // ������
        ([ "type":"food", "id":24, "amount":1, "p1":30, "p2":100 ]),   // ���N��
        ([ "type":"food", "id":27, "amount":1, "p1":30, "p2":100 ]),   // ����
        ([ "type":"food", "id":26, "amount":1, "p1":30, "p2":100 ]),   // �곽
        ([ "type":"food", "id":25, "amount":1, "p1":30, "p2":100 ]),   // �I��
        ([ "type":"obj", "id":77, "amount":1, "p1":1, "p2":200 ]),     // �q���Q�OŢ
        ([ "type":"wp", "id":46, "amount":1, "p1":1, "p2":450 ]),      // ��M
        ([ "type":"eq", "id":86, "amount":1, "p1":5, "p2":100 ]),      // �q�j��
    }) );
    setup();
}
int accept_fight(object ob)
{
    do_chat((: command, "shake" :));
    return 0;
}
int accept_kill(object ob)
{
    if( this_object()->query_temp("quest/tonbeli_go") == 1 ) {
        message_vision("$N�M�w�}�l���H$n�@�_��ʡC\n", this_object(), this_player());
        this_object()->set_leader(this_player());
        return 0;
    }
    if( random(20) > 18) {
        set_name("�q���Q��", ({ "tonbeli king", "king" }));
        set_race("human");
        set_level(40);
        set("nickname",HIY"��M��"NOR);
        set("age", 45);
        set("long","��ⴣ�ۿOŢ�����ǡA��W���ۤ@��_�Ǫ���M�A�Y�W���۬ӫa�C\n");
        message_vision(HIG"�u�I�v���@�}����«�_�A"NOR"�q���Q"HIG"�~�M�ܨ����F"NOR"$N"HIG"�I\n"NOR, this_object());
        set("chat_chance", 1);
        set("chat_msg", ({
            CYN"�q���Q�����ۿO�s�ӫG�|�P�C\n"NOR,
        }));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
            (: do_fight :),
            (: do_garbage :),
            (: do_fight :),
            (: do_light :),
            (: do_fight :),
        }) );
        set("set_drop", ({
            ([ "type":"food", "id":28, "amount":1, "p1":20, "p2":100 ]),   // �j��
            ([ "type":"food", "id":45, "amount":1, "p1":20, "p2":100 ]),   // ��Į
            ([ "type":"obj", "id":77, "amount":1, "p1":5, "p2":100 ]),     // �q���Q�OŢ
            ([ "type":"wp", "id":46, "amount":1, "p1":1, "p2":300 ]),      // ��M
            ([ "type":"eq", "id":86, "amount":1, "p1":20, "p2":100 ]),     // �q�j��
        }) );
        add_temp("apply", (["hp":1100, "ap":1100, "mp":1100, "attack":455,
                            "armor": 383, "intimidate":20, "wittiness":20,
                            "exact":50, "evade":50, "move":20 ]) );
        do_heal();
    }
    this_object()->add_temp("quest/tonbeli_go", 1);
    message_vision("$N�M�w�}�l���H$n�@�_��ʡC\n", this_object(), this_player());
    this_object()->set_leader(this_player());
    i = random(10)+1;
    message_vision("$N"HIG"�ٶZ��"NOR"$n ("HIY+i+NOR") "HIG"�B�I\n"NOR, this_object(), this_player());
}
