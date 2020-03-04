#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("���U", ({ "sea monkey", "monkey" }) );
    set_race("beast");
    set("title", HIC"�p��������" NOR);
    set_level(45);
    set("age", 150);
    set("long", @long
�@��������٭��H�٤j�����U�A���b�����a���ˮ����A���֭n��ް_
���S���{�פF�C�Q�n�����e�A���G���O�@��H�వ�쪺�ơC
long
);
    set("limbs", ({ "�U�Y", "����", "�{�l", "�U�u", "������", "�U�I", "�U�L" }) );
    set("verbs", ({ "bite" }) );
    set("set_drop", ({
          ([ "type":"wp", "id":25, "amount":1, "p1":1, "p2":800 ]),  // ����
    }) );
    setup();
    add_temp("apply/attack", 40);
    set_skill("combat", 150);
    set_skill("dodge", 150);
    set_skill("parry", 150);
    set_skill("savage hit", 150);
    set_skill("heavy hit", 150);
    set_skill("continual hit", 150);
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
    msg = "\n\n\t"HIC"��"+this_object()->query("name")+"�ˤU�ɡA�H���q�q���w�I�n�|�_����\n"NOR;
    msg += HIW"\n�H���q�������ŧG�G"+enemy->query("name")+"("+enemy->query("id")+")�����H���q�����ɤ@�`�I�u�O�j�֤H�ߡI\n\n"NOR;

    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    if( random(100) < 26 ) {
        killer->add("exchange", 1);
        tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F 1 �I�I���I�ơC)\n"NOR);
    }
    ::die();
    return;
}