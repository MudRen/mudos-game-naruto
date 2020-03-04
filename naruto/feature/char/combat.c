/* combat.c
*/

#include <attack.h>
#include <dbase.h>
#include <score.h>
#include <skill.h>
#include <statistic.h>
#include <combat.h>

varargs int query_attr(string,int);

int ability_attack() { return query_attr("str") * 3 + query_temp("apply/attack"); }
int ability_defend() { return query_attr("con") * 3 + query_temp("apply/armor"); }
int ability_exact() { return query_attr("int")/2 + query_attr("dex")*3/2 + query_temp("apply/exact"); }
int ability_evade() { return query_attr("int")*3/2 + query_attr("dex")/2 + query_temp("apply/evade"); }
int ability_intimidate() { return query_attr("dex") + query_attr("str") + query_temp("apply/intimidate"); }
int ability_wittiness() { return query_attr("int") + query_attr("con") + query_temp("apply/wittiness"); }
int ability_carriage() { return query_attr("str") * 3000 + query_temp("apply/carriage") * 1000; }

/* ��O */
varargs int query_ability(string application)
{
    if( !living(this_object()) ) return 0;

    switch(application) {
        case "attack": return ability_attack();          // �����O
        case "defend": return ability_defend();          // ���m�O
        case "exact": return ability_exact();            // �R����O
        case "evade": return ability_evade();            // �j�ׯ�O
        case "intimidate": return ability_intimidate();  // �����ޥ�
        case "wittiness": return ability_wittiness();    // ���m�ޥ�
        case "sock": return 1;                           // �P�R�@��
        case "carriage": return ability_carriage();      // �t����O
    }
    return 0;
}

// ��������
varargs int receive_damage(int damage, object from)
{
    int kill_mode = 0;
    mapping flag;
    string from_type;

    if( damage < 1 ) return 0;

    // ������O
    damage_stat("hp", damage, from);

    // ��Z�Ҧ�
    if( !kill_mode && !from->is_killing(this_object()) && mapp(flag = query_exhausted()) && (flag["hp"] || flag["ap"] || flag["mp"]) ) {
        string stat;
        object ob;

        foreach(stat, ob in flag)
        set_stat_current(stat, 1);

        clear_statistic_flags();
        remove_all_enemy();

        call_out("lose_fight", 0, from);

        if( !userp(from) ) this_object()->unconcious();
        return damage;
    }

    return damage;
}
