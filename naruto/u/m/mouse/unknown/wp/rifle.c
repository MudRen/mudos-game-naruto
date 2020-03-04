#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;
int i;
int do_fire(object obj);

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void create()
{
    set_name(HIY"�Ӻֺj"NOR, ({ "rifle"}));
    set_weight(7000);
    setup_weapon(20, 30, 100, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 2525);
        set("long", "�y�H�ϥΪ��y�j�A�̭����G�٦��l�u�i�H�o�g(firegun fire mob)�C\n" );
    }
    setup();
}
void init()
{
    add_action("do_wield", "wield");
    add_action("do_unwield", "unwield");
    add_action("do_firegun", "firegun");
}
int do_wield(string arg)
{
    if( arg == "rifle as twohanded" ) {
    this_player()->add_temp("quest/rifle", 1);
    }
}
int do_unwield(string arg)
{
    if( arg == "rifle" ) {
    this_player()->delete_temp("quest/rifle");
    }
}
int do_firegun(string arg)
{
    string func,target;
    object ob;

    if ( !arg || sscanf(arg, "%s %s", func, target)!=2 )
           return notify_fail("�A�Q�g�֪��H\n");

    if ( !objectp(ob = present(target, environment(this_player()))) )
            return notify_fail("�A�Q�g�֪��H\n");

    if ( !ob
    ||      !ob->is_character()
    ||      ob->is_corpse()
    ||      ob==this_player() )
            return notify_fail("�A�Q�g�֪��H\n");

    if( func == "fire") {  do_fire(ob); }
    return 1;
}
int do_fire(object ob)
{
    object me;
    int damage;
    me = this_player();
    if( !me->is_fighting() ) {
        write("�A�S�b�԰��A����κj�C\n");
        return 1;
    }
    if( me->query_temp("quest/rifle") < 1) {
        write("�A�S���j���ΡC\n");
        return 1;
    }
    if( i < 9) {
        message_vision("$N���_"HIY"�Ӻֺj"NOR"���$n�o�g�I\n", me, ob);
        i = i+1;
        damage = random(81) + 20;
        if( random(me->query_ability("evade")) - random(ob->query_ability("evade"))) {
            ob->damage_stat("hp", damage, ob);
            message_vision("        $n�Q�l�u�����F�I�h���z�z�j�s�C("+damage+")"+report_status(ob)+"", me, ob);
            return 1;
        }
        message_vision("        $n���N�]���������A���O�@���l�u(0)"+report_status(ob)+"", me, ob);
        return 1;
    }
    message_vision("$N���_"HIY"�Ӻֺj"NOR"���F�X�U�A�~�o�{�l�u�w�g�Υ��F�C\n", me, ob);
    set("long", "�y�H�ϥΪ��y�j�A���l�u�w�g�Υ��F�C");
    set("base_value", 1010);
    return 1;
}
