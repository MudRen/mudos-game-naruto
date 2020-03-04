#include <ansi.h>

inherit NPC;

#define LIFE 50000

void create()
{
    set_name(HIK"����"NOR, ({ "slave", "_OBJ_STAKE_" }) );
    set("title", HIW"�F�]"NOR);
    set_race("human");
    set("stake_life", LIFE);

    set("long", "���yè�b�������A�O���i�a�s�q�H�f�c�l....����I¾�~���ЩҪ���\n"
                "���I�i�H�Ψӷ�F�]�A�άO���������]�i�H�A�Q�n�m�\�άO�Q�j��\n"
                "�l���ɳ̦n�Ϊ����~�I"HIW"(�F�]�A�i�H[say �^��]���L�^�k���W)\n"NOR);
    setup();

    set_attr("str", 1);
    set_attr("con", 1);
    set_attr("dex", 1);
    set_attr("int", 1);
    delete_stat("hp");

    set("no_combat", 1); // �������
    set("no_defend", 1); // ���ਾ�m
    set("no_evade", 1);  // ����j��
}

// ���O�D�H�������
int accept_fight(object ob)
{
    if( query("master_name") != ob->query("id") ) {
        message_vision("$N���D�G"HIG"�ڤ��O��$n�Ϊ��F�]�C\n"NOR, this_object(), ob);
        return 0;
    }
    else return 1;
}

varargs int receive_damage(int damage, object from, object attacker)
{
    return damage;
}

int relay_say(object me, string arg)
{
    object scap;

    if( arg == "�^��" ) {
        if( query("master_name") != me->query("id") ) {
            message_vision("$N�L�`�a�ݵۻ��D�G"HIG"$n���O�ڪ��D�H�C\n"NOR, this_object(), me);
            return 0;
        } else {
            scap = new("/world/item/scap.c");
            if( sizeof(all_inventory(me)) >= 40 || me->query_encumbrance() >= me->query_ability("carriage") - 1 ) {
                message_vision("$N������y���D�R"HIG"�D�H���W�ӭ��F�A�ڭI���� ��__��C\n"NOR, this_object(), me);
                return 1;
            }
            if( !scap->move(me) ) {
                tell_object(me, HIY"(�]���A���W�ӭ��A�����K�w�ѳߦa���k���F)\n"NOR);
                destruct(scap);
                destruct(this_object());
                return 1;
            }
            message_vision("$N"CYN"�N�˳Ʀ��@���^��$n�I��F�C\n"NOR, this_object(), me);
            destruct(this_object());
        }
        return 1;
    }
}
