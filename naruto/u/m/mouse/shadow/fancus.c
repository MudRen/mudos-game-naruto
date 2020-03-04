#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;
int i;

string *def_msg = ({
        "$n�~�����Y�j���A�n���e�����}�F�����I",
        "$n�@�Ӱ����j�}�����A�o���Q�F���ѻ��I�ҩ��S�����ˡC",
        "$n�V��g�b�ƤV�A�~�w�ߪ����U�}�B�C",
});
string *atk_msg = ({
        "�u�I�v�@�n���T�A$n�s�z�@�n�A�����ƤV���~�C",
        "�u�S�v�@�n�A$n���Q���S���뭸�V�������@�ݡC",
        "$n���b�a�W���u�A���L���������z�A���G�D�`�h�W�C",
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
    if(i < 10) {
    message_vision("$N���D�R"HIG"�٤����O���A�A�h��X��n�F�C\n"NOR, this_object());
    return;
    }
    message_vision("$N���ʬ��ʵ����A���M�@�O"HIW"�u"HIR"���۷i��"HIW"�v"NOR"�ⳡ�ֳt��������V$n�I\n", this_object(), enemy);
    damage = this_object()->query_ability("attack") - random(enemy->query_ability("defend"));
    if( damage < 0) {
        damage = 0;
    }
    if( random(enemy->query_ability("evade")) > this_object()->query_ability("evade")) {
        msg = def_msg[random(sizeof(def_msg))];
        message_vision("        "+msg+"(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        i = 0;
        return;
    }
    damage += i*i;
    msg = atk_msg[random(sizeof(atk_msg))];
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        "+msg+"("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    enemy->start_busy(3);
    i = 0;
    return;
}
void do_mass()
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
    i = i+1+random(3);
    message_vision(CYN"$N�ֳt����ۤ��u"NOR"("HIY+i+NOR")\n", this_object());
    return;
}
void create()
{
    set_name("��J��", ({ "fancus" }));
    set_race("human");
    set_level(60);
    set("title",HIK"�ۼv�ȹ�"NOR);
    set("age",25);
    set("long", "�����U�Q�B�������j�A�ݰ_�ӫD�`�M�I���H���C\n");
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_mass :),
        (: do_mass :),
        (: do_fight :),
        (: do_mass :),
        (: do_mass :),
    }) );
    setup();
}
int give_check(object ob)
{
    if( ob->id("_TEAM_PAPER_") ) return 1;           // �ȹζ��г�
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( ob->query_amount() > 1 ) {
                do_chat((: command, "say �@�i�N�n�A�h�����n�C" :));
                return 0;
            }
            message_vision("$N���D�R"HIG"�n�F�I�n�h���ֻ��a�I\n"NOR, this_object());
            do_chat(({ 
                (: command, "follow " + this_player()->query("id") :),
                (: command, "guard " + this_player()->query("id") :),
            }));
            break;
        default:
            do_chat((: command, "say �o�تF�褣�n���ڡC" :));
            return 0;
            break;
    }
    return 1;
}
