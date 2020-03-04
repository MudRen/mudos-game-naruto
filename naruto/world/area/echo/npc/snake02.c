#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void do_fight()
{
    int damage, raiseDamage, exact, evade;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( random(1000) ) {
        case 0..450:
            exact = this_object()->query_level();
            evade = enemy->query_level();

            this_object()->damage_stat("mp", 20, this_object());
            message_vision("\n$N"HIR"���_����H��@���A�ֳt���X���u��"NOR"$n"HIR"�Y�ӡI\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("���O$N���ޥ��������m�A�g�X�����u����ѻ��h�F�C\n\n", this_object(), enemy);
                this_object()->start_busy(1);
                return;
            }
            raiseDamage = 250;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            if( damage < 70 ) damage = 50 + random(20);

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("�u�F���v�@�n�A�uť��$n�@�n�G�s�A�@��r�骺�¤H�N�ϥͤF(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            break;
        case 451..550:
            message_vision("$N���M�Q�_�F�j�Ѫ��G��A���O��F�@�q����S�n�n�Y�A���G�O���F...\n"NOR, this_object(), enemy);
            break;
        case 551..999:
            exact = this_object()->query_level();
            evade = enemy->query_level();

            this_object()->damage_stat("mp", 15, this_object());
            message_vision("\n$N"HIC"���_�����"NOR"$n"HIC"�@���I�o�X��D�B�붶�ۤ����V�W�h�I\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("�u���B�뭸��@�b�o���M���h�F�O�q�A������b�a�W�C\n\n", this_object(), enemy);
                return;
            }
            raiseDamage = 100;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            // �ˮ`�ާl��
            damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("�u���j�v�@�n�A�B���W�b$n�����W�A�᪺$n���o��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->start_busy(1);
            break;
    }
    return;
}
void create()
{
    set_name("�D��", ({ "snake gi", "gi" }) );
    set_race("human");
    set("gender", "male");
    set_level(35);
    set("age", 45);
    set("limbs", ({ "�D�Y", "�D��", "����", "�ݤf", "�}��", "�ӻH", "�y��" }) );
    set("title",HIG"�D�ڲ��v"NOR);
    set("long", "����@�ڤ�����D�H�A���b���¤����|�毫���C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "say ���j���D�����I�б����o���������~�a�I" :),
        (: command, "say ���F�D�ڪ��aģ�I" :),
        (: command, "say �����ڭ̬��۪��Ʊ�I�N��P�ڤH���j��a�C" :),
    }));
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":100 ]),     // �D������
        ([ "type":"wp", "id":51, "amount":1, "p1":1, "p2":200 ]),     // �D��
        ([ "type":"food", "id":29, "amount":1, "p1":50, "p2":100 ]),  // �D�J
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // �D��
    }) );
    setup();
    carry_object("/world/area/thorn_pine/npc/wp/thorn_staff")->wield("twohanded");
}
void init()
{
    if( this_object() == this_player() ) return;

    // �Y this_player() �ݤ����o�ӤH���A�h���޵o�԰��C
    if( ! this_object()->visible(this_player()) ) return;

    // �ϰ�]�w
    if( environment()->is_area() && !area_environment(this_object(), this_player()) ) return;

    // �Y���西���ۤ������A�}�l�԰��C
    if( this_player()->is_killing(query("id")) ) {
        COMBAT_D->auto_fight(this_player(), this_object(), "hatred");
        return;
    }
    if( is_killing(this_player()->query("id")) )
    {
        COMBAT_D->auto_fight(this_object(), this_player(), "hatred");
        return;
    }
    // �ݨ�ѱi�k��K�}��
    if( this_player()->id("_HELP_GIRL_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N�@����$n�K�j�n�۵ۡG�u�����~�]�F�I�֥h��^�ӡI�v\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
