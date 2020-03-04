#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void do_fight()
{
    int damage, raiseDamage;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    this_object()->damage_stat("mp", 15, this_object());
    message_vision("\n$N"HIW"���_���j�@�ݡA�p�F�D�몺�W�V"NOR"$n"HIW"�|�����`�B�I\n"NOR, this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("���j�N���W�իݵo���D�A�u�I�v�a�@�n���V�Ů�...\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    raiseDamage = 800;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/twohanded"));
    add_temp("apply/attack", -raiseDamage);

    if( damage < 400 ) damage = 250 + random(150);

    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("���j�N���W�իݵo���D�A�u�I�v�a�@�n�r��F$n�A��X�F�@�Ӯ��Y�j����}(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    enemy->start_busy(1);
    return;
}
void create()
{
    set_name("�D��", ({ "snake king", "snake", "king" }) );
    set_race("human");
    set("gender", "male");
    set("camp", "snaker");
    set_level(45);
    set("age", 35);
    set("limbs", ({ "�D�Y", "�D��", "����", "�ݤf", "�}��", "�ӻH", "�y��" }) );
    set("title",HIW"�D�ڬӫ�"NOR);
    set("long", "����@����ܭ��A��W���ۤ@��զ⪺���j�A�ݰ_�ӫܫ­��C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "say �D�ڬO�̰��j���رڡI" :),
        (: command, "nomatch" :),
        (: command, "say �`���@�ѤѤU�|�H�D�ڬ��L�I" :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":5, "p2":100 ]),     // �D������
        ([ "type":"wp", "id":47, "amount":1, "p1":1, "p2":800 ]),     // �լӳD�j
        ([ "type":"wp", "id":49, "amount":1, "p1":15, "p2":100 ]),    // �s�M
        ([ "type":"wp", "id":48, "amount":1, "p1":20, "p2":100 ]),    // �޼C
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // �D��
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // �D�r
    }) );
    setup();
    carry_object(_DIR_AREA_"thorn_pine/npc/wp/soft_lance.c")->wield("twohanded");
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
    msg = "\n\n\t"NOR+this_object()->query("name")+HIW"�{���e�j�۹D�G�H���u�O���L�����ͪ��I�ڥ���F�I\n"NOR;
    msg += HIR"\n\t���׬O�˨��@�کάO"+enemy->query("name")+"�I�I�D�ڳ����|��L�A�̪��I\n"NOR;
    msg += HIW"\n\t�D�H�ڤ��ӳQ"HIR+enemy->query("name")+HIW"�����F�I�D�H�̫s�˸U��...\n\n\n"NOR;

    killer->add("exchange", 1);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F 1 �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}