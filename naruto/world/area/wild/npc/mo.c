#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

string *name = ({ "�p�ߤl", "�p��", "�p��", "�p�U�l", "�p��",
                  "�p����", "�p��", "�p�n", "�p�e��", "�p��",
                  "�p�d�m", "�p��", "�p��", "�p���Z", "�p�T", });

void do_fight()
{
    mapping cnd = ([]);
    int damage, raiseDamage, i, exact, evade;
    object enemy, target;
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
    // ���䦳�S���D���a������
    for(i=0;i<sizeof(inv);i++) {
        if( inv[i] == this_object() ) continue;
        if( !this_object()->visible(inv[i]) ) continue;
        if( environment()->is_area() && !area_environment(this_object(), inv[i])) continue;
        if( inv[i]->query("userp") == 0 && inv[i]->is_corpse() ) {
            target = inv[i];
            break;
        }
    }

    cnd["name"] = HIG"���r"NOR;
    cnd["duration"] = 10;

    if( !target ) {
        damage = 100 + random(150);
        this_object()->damage_stat("mp", 10, this_object());
        if( !COMBAT_D->isHit(this_object(), enemy) ) {
            message_vision("$N����o�X�@�}"HIG"���{��"NOR"�A���O����Ƥ]�S�o�͡C\n", this_object());
        } else {
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("$N���X����Ĳ�I$n������A$n�u�Pı�@��"HIG"�O�H���ߪ���"NOR"�ǤJ�ۤv�餺(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->set_condition("vp", cnd);
        }
        return;
    }
    exact = this_object()->query_level();

    this_object()->damage_stat("mp", 30, this_object());
    message_vision(CYN"\n$N���c�a�L���A���X����K�b"NOR+target->query("name")+CYN"�������A�C�C�N���O��i"NOR+target->query("name")+CYN"...\n\n"NOR, this_object(), enemy);
    message_vision(target->query("name")+GRN"�������Ȱ_�ӡA�o�X���ߪ��ͯ�A���M�z���}�ӡA�Q�X�R���G�k���ͬr�I\n"NOR, this_object(), enemy);
    for(i=0;i<sizeof(inv);i++) {
        if( inv[i] == this_object() ) continue;
        if( !this_object()->visible(inv[i]) ) continue;
        if( environment()->is_area() && !area_environment(this_object(), inv[i])) continue;
        if( living(inv[i]) ) {
            if( inv[i]->is_corpse() ) continue;

            evade = inv[i]->query_level();
            raiseDamage = target->query("level")*20 + 100 + random(200);

            if( COMBAT_D->SkillHit(this_object(), inv[i], exact, evade) ) {
                if( inv[i]->query("camp") != "hole_bandit" ) {

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(inv[i], enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 300 ) damage = 150 + random(150);

                    inv[i]->receive_damage(damage, this_object());
                    message_vision( sprintf(HIG"�@�r�Q�q�b$N�����W�A�y���Y�����`�˻P���r(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(inv[i]) ), this_object(), inv[i]);
                    inv[i]->set_condition("vp", cnd);
                } else {
                    message_vision(HIG"$N���M�����D�����覡�A�o���M�l�J�F�X�f�r��...\n"NOR, inv[i]);
                    inv[i]->set_condition("vp", cnd);
                }
            } else {
                message_vision("���O$N���B�𤣿��A�ͬr�S���Q�q�b$N���|�P�C\n", inv[i]);
            }
        }
    }
    destruct(target);
    message_vision("\n"NOR, this_object());
    return;
}

void do_heal()
{
    string animal;
    int damage;
    object item;

    // �w�g���l�L����N�Ȯɤ��l�F, hp�����]���l
    if( present("_ANIMAL_CORPSE_", environment(this_object())) ) return;
    if( query_stat("hp") >= query_stat_maximum("hp") ) return;

    animal = name[random(sizeof(name))];
    item = new("/obj/corpse.c");
    item->set_name(animal+"������", ({ "corpse", "_ANIMAL_CORPSE_" }) );
    item->set("long", "���g�O�@���i�R�S���⪺�p�ʪ��A���{�b�u�O�@�㰮�\����F�C\n");
    item->set("level", 15);
    item->set("no_sac", 1);

    message_vision("\n$N"HIM"���L�a���ۦۤv���ˤf�A���M�q���O�̮��X�@���Q���i�R��"+animal+"...\n"NOR, this_object());

    if( environment(this_object())->is_area() ) move_side(item, this_object());
    else item->move(environment(this_object()));

    this_object()->heal_stat("hp", query_stat_maximum("hp")/2);
    if( query_stat("hp") > query_stat_maximum("hp") ) set_stat_current("hp", query_stat_maximum("hp"));
    message_vision(HIG"$N�~�M���ߪ����X�k��K�b"NOR+animal+HIG"�Y���A��x�o�X�@�κ��r��N"NOR+animal+HIG"���A��ɤJ�ۤv�餺\n"NOR, this_object());
    message_vision(HIG"�u��$N���ˤf�C�C¡�X�A�o�l���F"NOR+animal+HIG"���ͩR�O�A$N�K�N�p�P���ͪ�"NOR+animal+HIG"��b�a�W�C\n\n"NOR, this_object());
    return;
}

void create()
{
    set_name("�]��", ({ "mo gao", "gao" }));
    set_class("middle");
    set_level(45);
    set("title", "�餧��");
    set("long", "�����@�V���H�A���W�л\�۲`��⪺���O�A�ݰ_�Ӧ��ǩ_�S�A�L�N�O\n"
                "�ϥίS��ޥ����U�s������h�Ԫ̩M�y�H������A�J�ӬݥL�����WŢ\n"
                "�n�ۤ@�h�����~�A�o�h���~�ɫG�ɷt�A�ٴ��o�ۿW�S������C�D��\n"
                "���H���G���|�Pı���U���}�w�t�A���L�j�@�U�l�N��_���`�F�C\n");
    set("camp", "hole_bandit");
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":2+random(2), "p1":50, "p2":100 ]), // ����
        ([ "type":"obj", "id":22, "amount":1, "p1":20, "p2":100 ]),           // ������
        ([ "type":"wp", "id":16, "amount":1, "p1":1, "p2":200 ]),             // ����C
        ([ "type":"wp", "id":70, "amount":1, "p1":1, "p2":500 ]),             // �s�p�C
        ([ "type":"eq", "id":66, "amount":1, "p1":50, "p2":100 ]),            // �s�D�c
        ([ "type":"eq", "id":67, "amount":1, "p1":50, "p2":100 ]),            // �C���@��
    }) );
    // �H������
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: do_heal :),
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
void die()
{
    object enemy, killer;
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        ::die();
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            ::die();
            return;
        } else
        if( environment(enemy) != environment(this_object()) ) {
            ::die();
            return;
        }
    }
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n\n"GRN+this_object()->query("name")+"���`����O�����M�Q�X�j�q�����I�~��v���U�k...\n\n"NOR+this_object()->query("name")+"�G"HIG"�������I�i�c��"+enemy->query("name")+"�I���L��"+this_object()->query("name")+"�O�������I"NOR"\n\n"HIY+enemy->query("name")+HIY"�����F�|�B���]�۱������޵s���Y�l"+this_object()->query("name")+"�I����~���w�n�p�ʡI\n\n\n"NOR;

    killer->add("exchange", 1);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F 1 �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}