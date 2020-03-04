#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void do_fight()
{
    mapping cnd = ([]);
    int damage, i, exact, evade;
    object enemy;
    object *inv;
    inv = all_inventory(environment(this_object()));

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( !inv ) return;
    if( !this_object() ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = this_object()->query_level();

    this_object()->damage_stat("mp", 15, this_object());
    message_vision("$N���_�Z���I�i"HIW"�y�o�z"NOR"�A�u��$N�����O���M�ഫ��"GRN"������"NOR"�X����|�P...\n", this_object(), enemy);

    cnd["name"] = HIG"���r"NOR;
    cnd["duration"] = 10;

    for(i=0;i<sizeof(inv);i++) {
        if( inv[i] == this_object() ) continue;
        if( !this_object()->visible(inv[i]) ) continue;
        if( environment()->is_area() && !area_environment(this_object(), inv[i])) continue;
        if( living(inv[i]) ) {
            if( inv[i]->is_corpse() ) continue;
            evade = inv[i]->query_level();

            if( COMBAT_D->SkillHit(this_object(), inv[i], exact, evade) ) {
                message_vision(HIG"$N���p�߱N���l�J�X�f�A���y�F�X�n...\n"NOR, inv[i]);
                inv[i]->add_busy(1);
                inv[i]->set_condition("vp", cnd);
            } else {
                message_vision("���G���S����$N�y���v�T�C\n", inv[i]);
            }
        }
    }
    return;
}
void create()
{
    set_name("�s��", ({ "dao gao", "gao" }));
    set_class("middle");
    set_level(35);
    set("title", "�s����");
    set("long", "�����@�ت��H�A�ݥL�@�ƥ������ҼˡA�N���D�L�O�o�̥��c�s�骺��\n"
                "��C���L�{�b��������G�w�g���O�L�F�A�]���츭���Ԫ̥�D�˳ߤ�\n"
                "���_���M��Ԫ̧������a�A�P���y�H���|�]�N�o�̪��s��C�����n��\n"
                "����V�A�ϱo�s��̤@�׮t�I�Q����A���G�ӤF�@��ۺ��]�����_��\n"
                "�k�l�A�~�M�ϥίS���ޥ��N�Ԫ̩M�y�H�����h�F�A�]���s���K�N��\n"
                "�⤧�������F�]���A�ٻ��A��U�P�ۤv�@�_�M�]���ǲߧޥ��C\n");
    set("camp", "hole_bandit");
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":2000+random(1000), "p1":50, "p2":100 ]), // �Ȥl
        ([ "type":"obj", "id":22, "amount":1, "p1":20, "p2":100 ]),                 // ������
        ([ "type":"wp", "id":16, "amount":1, "p1":1, "p2":500 ]),                   // ����C
        ([ "type":"wp", "id":70, "amount":1, "p1":1, "p2":800 ]),                   // �s�p�C
        ([ "type":"eq", "id":66, "amount":1, "p1":5, "p2":100 ]),                   // �s�D�c
        ([ "type":"eq", "id":67, "amount":1, "p1":10, "p2":100 ]),                  // �C���@��
    }) );
    // �H������
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();

    // �W�j
    add_temp("apply/attack", 100);
    add_temp("apply/armor", 60);
    add_temp("apply/exact", 20);
    add_temp("apply/evade", 20);
    add_temp("apply/intimidate", 10);
    add_temp("apply/wittiness", 10);
    add_temp("apply/int", 7);
    add_temp("apply/con", 7);
    add_temp("apply/str", 7);
    add_temp("apply/dex", 7);
}
