#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
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
void do_change()
{
    if( i > 0) {
        message_vision(CYN"$N�J���ˬd�ۨ��W���Z���t�ơC\n"NOR, this_object());
        message_vision("$N�j�n�^���R"HIG"�u��ok�I��h�u��aok�I\n"NOR, this_object());
        i = 0;
        return;
    }
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
    message_vision("$N���X�H����"HIK"[�Q���ľW�j]"NOR"�A�t�X��ũ��O���X����l�u�I\n", this_object(), enemy);
    damage = random(this_object()->query_ability("attack"))/2;
    damage += 10;
    if( random(enemy->query_ability("evade")) > 100) {
        message_vision("        $n�ֳt�q�@���׶}�I(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n�Q����l�u�����A�n�����F�I�ˡI("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void do_drop()
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
    message_vision("$N�Y�۲�l�j�ۡR"HIG"�֥���h�u�I\n"NOR, this_object(), enemy);
    call_out("drop_1",10,this_object(),enemy);
}
void drop_1()
{
    int damage;
    object enemy;
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( i > 2) {
        message_vision("$N�j�n�۵ۡR"HIG"���n�աA��h�u����F�I\n"NOR, this_object(), enemy);
        return;
    }
    damage = 100 + random(300);
    message_vision("$N�q�h���ǥX"HIG"��h�u"NOR"�A�޶}�ޫH���$n�ΤO�Y�h�I\n"NOR, this_object(), enemy);
    i = i+1;
    if( random(enemy->query_ability("evade")) > 200) {
        message_vision("        $n���\�����}�F�z���d��I(0)"+report_status(enemy)+"\n"NOR, this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n�{�פ���A�Q�z�����ˤF�I("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void create()
{
    set_name("�¹D����", ({ "bandit" }));
    set_race("human");
    set_level(40);
    set("title","�ͧJ�ʩ��|");
    set("age", 20+random(50));
    set("long", "�Q���Y���Ϊ��¹D����A�M���l���ۼv�ȹΦ����C\n");
    set("chat_chance", 100);
    set("chat_msg", ({
       (: do_change :),
    }) );
    // �԰��ʧ@
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: do_drop :),
        (: command, "say ���I���}�I���}�I" :),
    }) );
    setup();
    set_stat_current("hp", 9999);             // ��O
    set_stat_maximum("hp", 9999);             // �̤j��
}
void relay_say(object ob, string arg)
{
    if( arg == "�۪�" ) {
        do_chat(({ 
           (: command, "say �ۼv�ȹΦ����۪��H�I�ǩR�ӡI" :),
           (: command, "kill wowgin" :),
        }));
        return;
    }
    if( arg == "��J��" ) {
        do_chat(({ 
           (: command, "say �j�a�`�N�I�O�ۼv�ȹΪ���J���I" :),
           (: command, "kill fancus" :),
        }));
        return;
    }
    if( arg == "�ͯS" ) {
        do_chat(({ 
           (: command, "say ������ڭn�����L�I���n����" :),
           (: command, "kill kate" :),
        }));
        return;
    }
}
int give_check(object ob)
{
    if( ob->id("_BANDIT_CARD_") ) return 1;           // ���ⶱ�Υd
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say �ڥ����ۡC" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �԰����C" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( ob->query_amount() > 1 ) {
                do_chat((: command, "say �u�n���ڤ@�i�N���F�C" :));
                return 0;
            }
            message_vision("$N���D�R"HIG"��ϡ��ע�I\n"NOR, this_object());
            do_chat(({ 
                (: command, "follow " + this_player()->query("id") :),
                (: command, "guard " + this_player()->query("id") :),
            }));
            break;
        default:
            do_chat((: command, "say ....." :));
            return 0;
            break;
    }
    return 1;
}
