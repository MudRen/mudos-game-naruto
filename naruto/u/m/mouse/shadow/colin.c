#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight(object enemy)
{
    int damage, i;
    object* targets;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("$N"HIW"�������`���M�渨�A�}�l�ƨg���X�u"HIB"��������j"HIW"�v���O���g�|�P�C\n"NOR, this_object());
    for(i=0;i<sizeof(targets);i++) {
        if( i > 9) break;   // ��Q�ӤH����
        damage = this_object()->query_ability("attack") + random(200);
        damage -= targets[i]->query_ability("defend");
        if( damage <= 0 || random(this_object()->query_ability("exact")) < random(targets[i]->query_ability("evade")) ) {
            message_vision("        ���O���u�����j�S����$n....(0)"+report_status(targets[i])+"", this_object(), targets[i]);
        } else {
            targets[i]->damage_stat("hp", damage, targets[i]);
            message_vision( sprintf("        $n�Q�L�Ʃ��u����F����A�����S���@�B�O���㪺�I(%d)%s", damage, report_status(targets[i])), this_object(), targets[i]);
        }
    }
}
void create()
{
    set_name("�I���J�L", ({ "fulin colin", "colin" }));
    set_race("human");
    set_level(60);
    set("title",HIK"�ۼv�ȹ�"NOR);
    set("age",28);
    set("long", "�������ӡB��W�ݤ��X������A���H�ܨIí���Pı�C\n");
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
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
                do_chat((: command, "say �u�n�@�i�C" :));
                return 0;
            }
            message_vision("$N���D�R"HIG"�n���C\n"NOR, this_object());
            do_chat(({ 
               (: command, "follow " + this_player()->query("id") :),
               (: command, "guard " + this_player()->query("id") :),
            }));
            break;
        default:
            do_chat((: command, "say ���ݭn�C" :));
            return 0;
            break;
    }
    return 1;
}
