#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;
int i;

string *def_msg = ({
        "$n�\�X���O���m���A�A���W���צ�F�o���I",
        "$n����o�¡A�O�F�n�j�@�f�\�Ҥ~�צ�C",
});
string *atk_msg = ({
        "�u�԰աI�v���n�A$n�����Y�����Q���_�F�h�֡I",
        "$n�Ⲵ½�ժ��˭��F�X�h�A���G���w���h��ı�C",
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
    if(this_object()->is_busy()) {
        message_vision("$N�u�F�@�f���D�R"HIG"��I�O�q�٨S�����A���ǤF$n�C\n"NOR, this_object(), enemy);
        return;
    }
    i = random(7) + 1;
    if( i == 4) {
        message_vision("$N�殱�鹡���O�A���X��Ѱʦa"HIW"�u"HIR"�W�E"HIY"�}�a��"HIW"�v\n"NOR, this_object());
        damage = this_object()->query_ability("attack")*2;
        damage += random(200);
        msg = def_msg[random(sizeof(def_msg))];
        if( (random(enemy->query_ability("evade")) + random(enemy->query_ability("attack")))/2 > 300+random(300)) {
            message_vision("        "+msg+"(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(6);
            return;
        }
        msg = atk_msg[random(sizeof(atk_msg))];
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        "+msg+"("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    } else 
    if( i > 4) {
        if(enemy->is_busy()) {
            message_vision("$N�q�D�R"HIG"�S�Ϊ��F��I\n"NOR, this_object(), enemy);
            return;
        }
        message_vision("$N�j�q�@�n�I�|�P�_�ձ�Ť�I\n"NOR, this_object());
        if( random(enemy->query_ability("wittiness")) > 100+random(50)) {
            message_vision("        $n���G�S������o�q�n���v�T�C"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(3);
            return;
        }        
        message_vision("        $n�����@�}�w�t�A���駹���ʤ��F�I(0)"+report_status(enemy)+"", this_object(), enemy);
        enemy->start_busy(random(5)+2);
        return;
    } else {
        message_vision("$N���O�����A���X"HIW"�u"HIY"�}�a��"HIW"�v\n"NOR, this_object());
        damage = random(this_object()->query_ability("attack"));
        damage += random(100);
        if( (random(enemy->query_ability("evade")) + random(enemy->query_ability("attack")))/2 > 200+random(200)) {
            message_vision("        $n�M�ۻɨ��K���פU�F�o�ۡI(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(4);
            return;
        }
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        �u�I�I�v���@�n�A$n�f�R�A��˰h�F�X�B�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
}
void create()
{
    set_name("�۪�", ({ "wowgin" }));
    set_race("human");
    set_level(60);
    set("title",HIK"�ۼv�ȹ�"NOR);
    set("age",28);
    set("long", "�������A�@�ݴN���D�L�R���F�̱j���z�o�O�C\n");
    set("chat_chance_combat", 100);
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
                do_chat((: command, "say �@�i�N���F�I��s�h�ӴX���~�O�u���C" :));
                return 0;
            }
            message_vision("$N���D�R"HIG"��I�n�a��ݦb�A�I�������W�I\n"NOR, this_object());
            do_chat(({ 
               (: command, "follow " + this_player()->query("id") :),
               (: command, "guard " + this_player()->query("id") :),
            }));
            break;
        default:
            do_chat((: command, "say �ֵ��کU���աI" :));
            return 0;
            break;
    }
    return 1;
}
