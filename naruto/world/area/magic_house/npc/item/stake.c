// mouse by 2007/7/31

inherit NPC;

#define LIFE 20000

void create()
{
    set_name("�]�k���H", ({ "magic stake", "stake", "_OBJ_STAKE_" }) );
    set_race("human");
    set("long", "���`�Q�ΨӴ��շs�]�N�����H�A�֦���������ܤO�C\n");
    // ���H���ͩR��
    set("stake_life", LIFE);
    setup();

    set_attr("str", 10);
    set_attr("con", 10);
    set_attr("dex", 10);
    set_attr("int", 10);
    delete_stat("hp");

    // �԰��]�w
    set("no_combat", 1); // �������
    set("no_defend", 1); // ���ਾ�m
    set("no_evade", 1);  // ����j��
}

// ���a�ޯ� combat �W�L 120 �Ť��������� ���H���@��
int accept_fight(object ob) { if( ob->query_skill("combat", 1) > 120) return 0; else return 1; }

varargs int receive_damage(int damage, object from, object attacker)
{
    return damage;
}
