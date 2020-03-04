#include <npc.h>
#include <ansi.h>

int i;

void do_fight()
{
    int damage, number;
    object enemy;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( query_temp("tonbeli_king") == 1 ) number = random(1000);
    else number = 500;

    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( number ) {
        case 0..200:
            message_vision("\n$N"HIW"�q�h�̮��X�@��j���U�������a��"NOR"$n"HIW"���Y���å�A�ѪųQ�U���n���@�����¡C\n"NOR, this_object(), enemy);
            if( random(5) == 0) {
                message_vision("���O�U�����¼v�v�������F$n�A�U���U�������D�Q�����̥h�F�C\n\n"NOR, this_object(), enemy);
            } else {
                damage = enemy->query_ability("intimidate")*5 + random(100);
                if( damage > 1500 ) damage = 1500 + random(200);
                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("�j���U���¼v�v���X�j�A���_�q�Ť����U�{�b$n�Y�W�A��$n�|�B�k«(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            }
            break;
        case 201..700:
            if( i > 1 ) {
                message_vision("$N"HIG"�C�C���e���F�@�B�I\n"NOR, this_object(), enemy);
                i = i-1;
                message_vision("$N"HIG"�ٶZ��"NOR"$n ("HIY+i+NOR") "HIG"�B�I\n"NOR, this_object(), enemy);
                return;
            }
            message_vision("\n$N"HIR"����F"NOR"$n"HIR"���e�A�G�X�F�U�Q����M�A�y�W�S�X�_�Ǫ��L��...\n"NOR, this_object(), enemy);
            if( random(10) >= 7) {
                message_vision("$N�k�k�Y�A���_��M�ΤO���Ů�@�W...�����D�b�Fԣ...\n\n"NOR, this_object(), enemy);
                i = random(7)+1;
                message_vision("$N"HIG"�S��������F"NOR"$n ("HIY+i+NOR") "HIG"�B�I\n"NOR, this_object(), enemy);
            } else {
                damage = enemy->query_stat_maximum("hp")/10 + random(50);
                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("$N���_��M��$n�@�W�A�P�a�@�n��M��i$n�ݤf�A�������_�X�j�q�A��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                i = random(10)+1;
                message_vision("$N"HIG"�S��������F"NOR"$n ("HIY+i+NOR") "HIG"�B�I\n"NOR, this_object(), enemy);
            }
            break;
        default:
            // �쥻�����ӧO�H�@��..��gy�F..-Acme
            // ���ܤ@�U�g�k�A���ӷ|����M��
            if( random(50) > 1 ) enemy = this_object();
            message_vision("\n$N"HIG"�n�̵ۤ�W���OŢ�A���M��@���N�OŢ�|���A�o�X�����~�ӫG$n�C\n"NOR, this_object(), enemy);
            if( enemy->query_stat("hp") >= enemy->query_stat_maximum("hp") ) {
                message_vision("�����G�S������Ʊ��o�͡A�L�׵o�����OŢ�ߨ�t�H�F�U�h�C\n\n"NOR, this_object(), enemy);
            } else {
                if( userp(enemy) ) enemy->heal_stat("hp", 200);
                else enemy->heal_stat("hp", enemy->query_stat_maximum("hp")/10);
                message_vision( sprintf("��⪺���~����Ţ�n��$N�����A�ֳt�a�v���F$N���˶�(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                // ���঳�}�����p����
                if( enemy->query_stat("hp") > enemy->query_stat_maximum("hp") ) enemy->set_stat_current("hp", enemy->query_stat_maximum("hp"));
            }
            break;
    }
    return;
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
    set("chat_chance", 15);
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
            ([ "type":"obj", "id":89, "amount":1, "p1":1, "p2":500 ]), // �긭���ѱ���
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
    if( query_temp("tonbeli_go") == 1 ) {
        message_vision("$N�M�w�}�l���H$n�@�_��ʡC\n", this_object(), this_player());
        this_object()->set_leader(this_player());
        return 0;
    }
    if( random(20) > 18) {
        set_name("�q���Q��", ({ "tonbeli king", "king" }));
        set_level(40);
        set("nickname",HIY"��M��"NOR);
        set("age", 45);
        set("long","��ⴣ�ۿOŢ�����ǡA��W���ۤ@��_�Ǫ���M�A�Y�W���۬ӫa�C\n");
        message_vision(HIG"�u�I�v���@�}����«�_�A"NOR"�q���Q"HIG"�~�M�ܨ����F"NOR"$N"HIG"�I\n"NOR, this_object());
        set("chat_chance", 15);
        set("chat_msg", ({
            (: random_move :),
            CYN"�q���Q�����ۿO�s�ӫG�|�P�C\n"NOR,
        }));
        set("set_drop", ({
            ([ "type":"food", "id":28, "amount":1, "p1":20, "p2":100 ]),   // �j��
            ([ "type":"food", "id":45, "amount":1, "p1":20, "p2":100 ]),   // ��Į
            ([ "type":"obj", "id":77, "amount":1, "p1":5, "p2":100 ]),     // �q���Q�OŢ
            ([ "type":"wp", "id":46, "amount":1, "p1":1, "p2":300 ]),      // ��M
            ([ "type":"eq", "id":86, "amount":1, "p1":20, "p2":100 ]),     // �q�j��
            ([ "type":"obj", "id":89, "amount":1, "p1":1, "p2":450 ]),     // �긭���ѱ���
        }) );
        add_temp("apply/hp", 1100);
        add_temp("apply/ap", 1100);
        add_temp("apply/mp", 1100);
        add_temp("apply/attack", 250);
        add_temp("apply/armor", 300);
        add_temp("apply/intimidate", 150);
        add_temp("apply/wittiness", 100);
        add_temp("apply/exact", 50);
        add_temp("apply/evade", 50);
        add_temp("tonbeli_king", 1);
        do_heal();
    }
    add_temp("tonbeli_go", 1);
    message_vision("$N�M�w�}�l���H$n�@�_��ʡC\n", this_object(), this_player());
    this_object()->set_leader(this_player());
    i = random(10)+1;
    message_vision("$N"HIG"�ٶZ��"NOR"$n ("HIY+i+NOR") "HIG"�B�I\n"NOR, this_object(), this_player());
}
