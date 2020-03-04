#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

int num=0;

string *name1 = ({ "�ӶQ", "�[��", "�B�A", "����", "�[��", "����", "�@�l",
                   "�ե�", "���", "�դs", "����", "�Ѧa", "�կ�", "�°�",
                   "����", "����", "�ŷ�", "����", "�դ�", "�¤�", "����",
                   "�Y", "�z", "�s", "�t", "�e", "��", "�}", "�b", "��",
                   "�u", "�U", "�L", "�f", "�x", "��", "��", "��", "��",
                   "�b�L��", "������", "�l�ȭ�", "�W����", "�U����" });

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$N" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$N" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$N" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_check()
{
    if( num > 0) {
        set("chat_chance", 10);
        this_object()->heal_stat("hp", num);
        message_vision("$N"HIW"�q�a�W�߰_�e���ɥR��~���Ӱ��Y���ˮ`�C("HIR+num+HIW")"+report_status(this_object())+""NOR, this_object());
        num = 0;
        return;
    }
    message_vision(CYN"$N�ˬd�ۥ|�P���S���ĤH....\n"NOR, this_object());
    return;
}
void do_whip(object enemy)
{
    int damage, i;
    object* targets;
    // �S���ĤH
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 30;
    message_vision("$N"NOR"�q���W�z�X�X�ڰ��Y�ϥX�u"HIY"�h���R"NOR"�v���Y���@�l�르�V�|��I\n"NOR, this_object(), enemy);
    for(i=0;i<sizeof(targets);i++) {
        if( i > 4) break;   // �來�ӤH����
        damage = random(101)+20;
        if( random(targets[i]->query_ability("evade")) > 150) {
            message_vision("        $N�T�V�����L�F�����I(0)"+report_status(targets[i])+"", targets[i], this_object());
            this_object()->start_busy(1);
        } else {
            targets[i]->damage_stat("hp", damage, targets[i]);
            message_vision("        $N�Q���Y�����A���W���W�h�F�@�D�˲��C("+damage+")"+report_status(targets[i])+"", targets[i], this_object());
        }
    }
}
void do_flower()
{
    int damage;
    object enemy;
    // �S���ĤH
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 50;
    message_vision("$N"NOR"�Ⱙ�����z�X�A�ܦ����p��j�몺�u"HIR"�K�u�ᤧ�R"NOR"�v�I\n"NOR, this_object(), enemy);
    damage = random(this_object()->query_ability("attack")) - random(enemy->query_ability("defend"));
    if( damage <= 0 || random(enemy->query_ability("wittiness")) > 120) {
        message_vision("        $N�O�F�@�f�\�Ҥ~�N���ۤƸѡI(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        �u�P�v�a�@�n�b$N���W�W�X�@�D��}�A��y����C("+damage+")"+report_status(enemy)+"", enemy, this_object());
    enemy->start_busy(1);
    return;
}
void do_finger()
{
    int damage;
    object enemy;
    // �S���ĤH
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 50;
    message_vision("$N"NOR"�Q���񥭴µ�$n�g�X�u"HIW"����"NOR"�v�I\n"NOR, this_object(), enemy);
    damage = random(31)+20;
    if( random(enemy->query_ability("evade")) > 170) {
        message_vision("        $N�ֳt���{�L�F�����I(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(1);
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $N�u�P�v�a�@�n�Q�����W�X�F�@�D�ˤf�C("+damage+")"+report_status(enemy)+"", enemy, this_object());
    }
    damage = random(31)+20;
    if( random(enemy->query_ability("evade")) > 170) {
        message_vision("        $N�ֳt���{�L�F�����I(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(1);
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $N�u�P�v�a�@�n�Q�����W�X�F�@�D�ˤf�C("+damage+")"+report_status(enemy)+"", enemy, this_object());
    }
    damage = random(31)+20;
    if( random(enemy->query_ability("evade")) > 170) {
       message_vision("        $N�ֳt���{�L�F�����I(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(1);
        return;
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $N�u�P�v�a�@�n�Q�����W�X�F�@�D�ˤf�C("+damage+")"+report_status(enemy)+"", enemy, this_object());
        return;
    }
}
void do_fight()
{
    int damage;
    object enemy;
    // �S���ĤH
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 200;
    message_vision("$N"NOR"���l���a�U�@�I�A�ϥX�˩R����"HIY"�y"HIR+BLINK"�������R"NOR+HIY"�z"NOR"�������Y�W�V�|���K��I\n"NOR,this_object(), enemy);
    damage = random(this_object()->query_ability("attack"))*2 + 100;
    damage -= random(enemy->query_ability("defend"));
    if( damage <= 0 || random(enemy->query_ability("evade")) > 230) {
        message_vision("        $N�v���ݬ�F�����~�׶}���ۡI(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        �u�P�P�v�s��X�n�A$N���w�Q�W�����ۡA��y�p�`�C("+damage+")"+report_status(enemy)+"", enemy, this_object());
    return;
}
void do_clone()
{
    object enemy, item;
    // �S���ĤH
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    item = new(__DIR__"wp/spinal.c");
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_temp("quest/psychical") == 1) {
    return;
    }
    this_object()->add_temp("quest/psychical", 1);
    num = num + 300;
    message_vision("$N"HIW"�I���C�C�Y�_�@���զⰩ�Y�A����ޥX��~�M�O�L�ۤv����հ��I\n"NOR, this_object());
    item->move(this_object());
    do_chat((: command, "wield sword" :));
    return;
}
void create()
{
    set_name("���]"+name1[random(sizeof(name1))], ({ "wheya ninja", "ninja" }) );
    set_level(35);
    set_class("middle");
    set_race("human");
    if( random(2) == 1) {
        set("gender", "male");
    } else {
        set("gender", "female");
    }
    set("age", 15+random(41));
    set("title",HIR"���~����"NOR);
    set("vendetta_mark", "wheya");  // �@���G���]�@��
    set("long",@LONG
���]�@�ڡA�b�ܤ[�H�e���@���Ԫ���A��M�X�{���s�ڸs�A�L�̤j�h
�O�Ԫ��L��s���U�Ӫ��H�A�]���@�ǬO��N�l�]�C�L�̷|�Q�H�o�{��
�̤j��]�A�N�O�L�̯���N���Y�Ƭ��Q�b�A�b���n���ɨ��ٯ�N�ۤv
���W�����Y�ޥX�����Z���A�]�ӹL��{�ӳQ�@�H�{���O�c�]�@�ڡA��
���ӳQ����Ԫ��j�D�Y�Ҧ��d�A�K�w�~�b�L���H��ள��Z����
�y�e���Գ��z���U�j�D�Y�����䪺�D�H�@�ڡC
LONG);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: do_check :),
        (: random_move :),
    }));
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: do_clone :),
        (: do_flower :),
        (: do_finger :),
        (: do_whip :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":100+random(200), "p1":60, "p2":100 ]), // �Ȥl
        ([ "type":"food", "id":16, "amount":1, "p1":3, "p2":100 ]),    // �j��O�Y
        ([ "type":"food", "id":18, "amount":1, "p1":5, "p2":100 ]),    // �j��O�Y
        ([ "type":"food", "id":20, "amount":1, "p1":3, "p2":100 ]),    // �j�d�J�Y
        ([ "type":"obj", "id":78, "amount":1, "p1":80, "p2":100 ]),    // ���]����
        ([ "type":"wp", "id":50, "amount":1, "p1":1, "p2":700 ]),      // �ᰩ�C
        ([ "type":"eq", "id":85, "amount":1, "p1":1, "p2":600 ]),      // �G�L�Э�
    }) );
    setup();
    add_temp("apply", (["hp":1500 ]) );
    // ���վ�L ap, hp, mp ���n do_heal(), �~�������A�ɺ�
    do_heal();
}
void die()
{
    object ob, *obs;
    obs = all_inventory(this_object());
    if( this_object()->query_temp("quest/psychical") == 1 ) {
        message_vision("�]��$N�����ҥH"HIW"�ᰩ�C"NOR"�������ƤF...�C\n"NOR, this_object());
        this_object()->delete_temp("quest/psychical");
        foreach( ob in obs ) destruct(ob);
    }
    ::die();
}
