// stake.c ���H 
// 2002/04/13 -Tmr
// update by -Acme-

inherit NPC;

#define LIFE 10000

void create()
{
    set_name("���H", ({ "wood stake", "stake", "_OBJ_STAKE_" }) );
    set_race("human");
    set("long", "�@�Ӥ�s�����H�A�M�����j�a�m�\\�Ϊ��C\n");
    // ���H���ͩR��
    set("stake_life", LIFE);
    setup();
    set_attr("str", 10);
    set_attr("con", 10);
    set_attr("dex", 10);
    set_attr("int", 10);
    delete_stat("hp");
}

// ���a�ޯ� combat �W�L�@�ʯŤ���������
int accept_fight(object ob) { if( ob->query_skill("combat", 1) > 100) return 0; else return 1; }

// ���H���|�j��
varargs int evade(int ability, object from) { return 0; }

// ���H�L�k���m
varargs int defend(int damage, object from) { return damage; }

//���H���|����
varargs int attack(object opponent) { return 0; }

varargs int receive_damage(int damage, object from, object attacker)
{
    // �S��������
    if( !attacker ) return 0;

    // ���H���ͩR �P�_
    add("stake_life",-damage);
    if( query("stake_life") < 0 ) {
        message_vision("�u�ذաv���n�T�A$N�ܦ����H���A�������a�F�C\n",this_object());
        remove_all_killer();
        call_out( (:destruct($1):),1,this_object());
    }       
    return damage;
}

