#include <npc.h>
#include <ansi.h>

// inherit F_VILLAGER;

object owner;
int attack = 0;        // �i�����P�_
int evade = 0;         // �i�j�׻P�_

void set_attack(int i) { attack = i; }
void set_evade(int i) { attack = i; }

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}

// ����
varargs int attack(object opponent)
{
    if( !attack ) return 0;
    return ::attack(opponent);
}
// �j��
varargs int evade(int ability, object from)
{
        if( !evade ) return 0;
        return ::evade(ability, from);
}
// �]�w�֦���
int set_owner(object obj)
{
    if( !objectp(obj) ) return 0;
    owner = obj;
}
// �d�߾֦���
object query_owner()
{
    if( !objectp(owner) ) return 0;
    return owner;
}
// �R���v����
void do_destruct()
{
    message_vision("$N�����l�����H�ƤF...\n", this_object());
    set_heart_beat(0);
    destruct(this_object());
    return;
}
void do_check()
{
    // �֦��̮����A�h�ƻs�~����
    if( !objectp(owner) ) {
        do_destruct();
        return;
    }
    // �b���P��m�]�|����
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), owner) ) {
            do_destruct();
            return;
        }
    } else {
        if( environment(this_object()) != environment(owner) ) {
            do_destruct();
            return;
        }
    }
    return;
}
void die()
{
    int damage;
    object enemy;
    enemy = this_object()->query_opponent();
    damage = 100+random(201);
    message_vision("$N�L�L��Ÿ�ݵۡA�����o�X"HIW"�E�P���ե�"NOR"�I\n", this_object(), enemy);
    message_vision("        $N���l�������}���X���l�A�����F$n�C("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
// �O�_�����R�O
int accept_order(object who, string cmd)
{
    return 0;  // �ƻs�~�O�������
}
void create()
{
    set_name("�w��", ({ "kube" }));
    set_race("beast");

    // ���ɰʧ@�G�ˬd�D�H�٦b���b
    set("chat_chance", 3);
    set("chat_msg", ({
        (: do_check :),
    }));
    // �԰��ɰʧ@�G�ˬd�D�H�٦b���b
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        (: do_check :),
    }) );
    setup();
}
