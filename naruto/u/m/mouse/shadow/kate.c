#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;
int i;

string *def_msg = ({
        "$n���l�L�ۡA�M�I���׶}�F���ۡI",
        "$n�`�Ȫ����Y�ۤU�A�B��n�׶}�F�����C",
});
string *atk_msg = ({
        "�u���I�M���L$n�Y�`�A�@���A�學�q�ӥX�C",
        "$n�s�z�F�@�n�A���W���ˤf�����Q�X�j�q���A��C",
});

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
    if( this_object()->query_temp("quest/psychical") == 1) {
    return;
    }
    i = random(3)+1;
    message_vision(HIW"$N�k��@���A�_�X�@�}�@�ϡC\n"NOR, this_object());
    if( i==1) {
        do_chat(({ 
            HIR"�ͯS�⤤��M�_�X�@��"HIK"�¦��I�M"HIR"....\n"NOR,
            "�@���p�����Y�b�I�M����W�j�ۡR"HIG"�u�ڬO�G���I�O�G���I�v\n"NOR,
            (: command, "say �u�O�V�|...���O�G���O..." :),
        }));
        this_object()->add_temp("quest/psychical", 1);
        call_out("deathsickle_1",10,this_object(),enemy);
    } else
    if( i ==2) {
        do_chat(({ 
            "�ͯS�⤤��M�_�X�@��"YEL"�y�j"NOR"....\n",
            "�@���p�����Y�b�y�j�j��W�j�ۡR"HIG"�u�ڬO�C���I�O�C���I�v\n"NOR,
            (: command, "say �o���ު����I�n�T��ϥΫ�~�|�����C" :),
        }));
        this_object()->add_temp("quest/psychical", 1);
        call_out("gunstar_1",10,this_object(),enemy);
    } else
    if( i ==3){
        do_chat(({ 
            "�ͯS�⤤��M�_�X�@��"HIC"�p����"NOR"....\n",
            "�@���p�����Y�b�Τl���ݤW�j�ۡR"HIG"�u�ڬO�T���I�O�T���I�v\n"NOR,
            (: command, "say �u�n�Ψө��A����ʤF�I" :),
        }));
        this_object()->add_temp("quest/psychical", 1);
        call_out("clownstaff_1",10,this_object(),enemy);
    }
}
void deathsickle_1()
{
    int damage;
    object enemy;
    string msg;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    this_object()->delete_temp("quest/psychical");
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy)) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    damage = this_object()->query_ability("attack")*3;
    damage -= random(100) + random(enemy->query_ability("move"));
    message_vision(HIR"$N�����|�_"HIK"�¦��I�M"HIR"�A�|�P�@�}�I�R�u"HIK"������R��"HIR"�v�C\n"NOR, this_object());
    message_vision("$N�⤤�¦��I�M���X���R���꩷�A���A$n���H�Y�I\n"NOR, this_object(), enemy);
    if( random(enemy->query_ability("evade")) > 300 + random(500)) {
        msg = def_msg[random(sizeof(def_msg))];
        message_vision("        "+msg+"(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(4);
        return;
    } else {
        msg = atk_msg[random(sizeof(atk_msg))];
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        "+msg+"("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(1);
    }
    return;
}
void gunstar_1()
{
    int damage;
    object enemy;
    string msg;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    this_object()->delete_temp("quest/psychical");
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    damage = this_object()->query_ability("intimidate") + this_object()->query_ability("exact");
    damage -= random(enemy->query_ability("defend")) + random(enemy->query_ability("wittiness"));
    message_vision("$N���_"YEL"�y�j"NOR"���$n�A�ֳt�����X�@�o�u"HIY"�l�u"NOR"�v�C\n"NOR, this_object(), enemy);
    if( random(enemy->query_ability("defend")) > 200 + random(300)) {
        message_vision("        $n�M�۱j�j�����m�w�O�Ө�������I(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�Q�l�u�e�鶴��A���L����򨭤l�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        enemy->start_busy(1);
    }
    return;
}
void clownstaff_1()
{
    int damage;
    object enemy;
    string msg;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    this_object()->delete_temp("quest/psychical");
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if(enemy->is_busy()) {
        message_vision("$N���D�R"HIG"��Ӥw�g����ʤF�A�u�O�ռo�\�ҡC\n"NOR, this_object(), enemy);
        this_object()->delete_temp("quest/psychical");
        return;
    }
    message_vision("$N���_"HIC"�p����"NOR"���t����ۡA�Τ����F�l���n�}�}���i�x��$n�I\n"NOR, this_object(), enemy);
    if( random(enemy->query_ability("evade")) > 200 + random(200)) {
        message_vision("        $n�èS������o�n�����v�T�I(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�uı�o�����@���V�áA�L�k��ҤF�C(0)"+report_status(enemy)+"", this_object(), enemy);
        enemy->start_busy(6);
    }
    return;
}
void create()
{
    set_name("�ͯS", ({ "kate" }));
    set_race("human");
    set_level(60);
    set("title","�����̤l");
    set("age",28);
    set("long", "�a�ۤ@���n�޴U�A�ݰ_�ӫD�`���q���k�l�A���G�b�M��ۤ���F��C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
        (: command, "say �o�N�O�H���q�a�A���a�Ϧn�����ӹ�..." :),
        CYN"�ͯS�ۨ��ۻy�����R�n���]���b�o��...\n"NOR,
    }));
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
}
