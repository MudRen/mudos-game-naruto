#include <npc.h>
#include <ansi.h>

string *name = ({ HIW"", HIK"", HIC"", HIY"", HIM"",
                  HIB"", HIG"", HIR"", REV"" });
void do_fight()
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
    switch( this_object()->query("sktree") ) {
        case 1: // �P�} & �P�}�E�t�T
            if( random(3) == 0 ) {
                command("perform kick haze.kick on " + enemy->query_id());
            } else {
                command("perform kick wolf.kick on " + enemy->query_id());
            }
            break;
        case 2: // ���t�p & �۷Q����
            if( this_object()->query_condition("elf") == 0 ) command("perform chimera fay.assoil");
            break;
        case 3: // ���u & ��������j
            command("perform psychical bullet.shoot on " + enemy->query_id());
            break;
        case 4: // �����O�ܤ� & ����
            if( this_object()->query_condition("firewall") == 0 ) command("perform fire wall.fire");
            break;
        case 5: // �ղ� & �K�����Q�|�x
            if( this_object()->query_condition("white_eyes") != 0 ) command("perform soft fist.attack on " + enemy->query_id());
            else command("perform white eyes.open");
            break;
        case 6: // ���ƳN & �׼u�Ԩ�
            if( this_object()->query_condition("dp") != 0 ) command("perform muscle tank.attack on " + enemy->query_id());
            else command("perform double physique.dp");
            break;
    }
}

void do_move()
{
    object ob = this_object();
    if( ob->query("sktree") ==6 && ob->query_condition("white_eyes") != 0 ) delete_condition("white_eyes");
    else do_chat((: random_move :));
}

void create()
{
    set_name( name[random(sizeof(name))]+"�ܤ��]"NOR, ({ "mindflayer" }));
    set_race("human");
    set_level(40);
    set("age", 300 + random(5000));
    set("long", "��Ϊ����ߤW���ۤ@�����j�������A�������{�{���C���⪺���~�A��\n"
                "�H�e������g�b�����C���ߪ��|�����ۥ|��Ĳ��A�Ψӱ�Ĳ��L�ͪ�\n"
                "�H�ܨ���ߴ��C�ܤ��]�ժ��ϥ��]�k�ޥ��A�s���`�����ʳ��O�H�}�B\n"
                "�����A��i�A�i�����]�k��O���j�j�C\n");

    set("attitude", "aggressive");         // �D�ʧ���
    set("sktree", random(6)+1);            // �ޯ�P�_

    // �H������
    set("chat_chance", 10);
    set("chat_msg", ({
        (: do_move :),
    }));

    // �԰��ʧ@
    set("chat_chance_combat", 35);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // �H���D��
    switch( random(1000) ) {
        case 0..350:
            set("set_drop", ({
                ([ "type":"obj", "id":130, "amount":1, "p1":15, "p2":100 ]),  // ����
                ([ "type":"obj", "id":28, "amount":1, "p1":30, "p2":100 ]),   // ����
            }) );
            break;
        case 650..1000:
            set("set_drop", ({
                 ([ "type":"obj", "id":131, "amount":1, "p1":15, "p2":100 ]),  // �s��
                ([ "type":"obj", "id":28, "amount":1, "p1":30, "p2":100 ]),   // ����
            }) );
            break;
        case 351..649:
             set("set_drop", ({
                 ([ "type":"obj", "id":132, "amount":1, "p1":10, "p2":100 ]),  // �߻�
                 ([ "type":"obj", "id":28, "amount":1, "p1":30, "p2":100 ]),   // ����
             }) );
             break;
    }
    setup();

    // ���A
    set_stat_current("hp", 3500);
    set_stat_current("ap", 2500);
    set_stat_current("mp", 5000);
    set_stat_maximum("hp", 3500);
    set_stat_maximum("ap", 2500);
    set_stat_maximum("mp", 5000);

    // �򥻧ޯ�
    set_skill("parry", 160);
    set_skill("dodge", 160);
    set_skill("combat", 160);
    set_skill("heavy hit", 160);
    set_skill("savage hit", 160);
    set_skill("continual hit", 160);

    // �H���ɧU����
    switch( random(4) ) {
        case 0: set_skill("substitute", 160);
                map_skill("dodge", "substitute");
                break;
        case 1: set_skill("solid", 160);
                map_skill("parry", "solid");
                break;
        case 2: set_skill("body iron", 160);
                break;
        case 3: set_skill("paper step", 160);
                break;
    }
    switch( query("sktree") ) {
        case 1: // �P�} & �P�}�E�t�T
            set_skill("spurn", 160);
            set_skill("kick haze", 160);
            set_skill("kick wolf", 160);
            set_skill("sock power", 50);
            break;
        case 2: // ���t�p & �۷Q����
            carry_object("/world/area/ship/npc/wp/sky_stick.c");
            set_skill("activity", 160);
            set_skill("anemometer", 160);
            set_skill("chimera fay", 160);
            break;
        case 3: // ���u & ��������j
            set_skill("emit", 160);
            set_skill("psychical bullet", 160);
            set_skill("machine gun", 160);
            break;
        case 4: // �����O�ܤ� & ����
            set_skill("variation", 160);
            set_skill("fire variation", 160);
            set_skill("fire wall", 160);
            break;
        case 5: // �ղ� & �K�����Q�|�x
            set_skill("force", 160);
            set_skill("white eyes", 160);
            set_skill("soft fist", 160);
            break;
        case 6: // ���ƳN & �׼u�Ԩ�
            set_skill("force", 160);
            set_skill("double physique", 160);
            set_skill("muscle tank", 160);
            break;
    }
    // �W�j
    add_temp("apply/exact", 100);       // �R���v
    add_temp("apply/evade", 100);       // �j�ײv
    add_temp("apply/intimidate", 150);  // ������O
    add_temp("apply/wittiness", 150);   // ���m��O
    add_temp("apply/int", 5);
    add_temp("apply/con", 5);
    add_temp("apply/str", 5);
    add_temp("apply/dex", 5);
    call_out("die_1", 240+random(240), this_object());
}

void die_1()
{
    message_vision("$N"HIK"�S��^�F�·t�����C\n"NOR, this_object());
    destruct(this_object());
    return;
}
