#include <npc.h>
#include <ansi.h>

object do_random(string category)
{
    int rnd, *key;
    key = keys(ITEM_D->do_query_all(category));
    rnd = key[random(sizeof(key))];
    return ITEM_D->get_item(category, rnd);
}

void do_fight()
{
    int damage, raiseDamage, i;
    object enemy, wp;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    this_object()->damage_stat("mp", 15, this_object());
    message_vision(HIK"\n$N���L�I�i�u"HIB"�v�������N"HIK"�v�H�Y�X�{�T��v�����ֳt��_$N�I��Z���I�i"YEL"�u�T��뤧�R�v\n"NOR, this_object(), enemy);

    for(i=0;i<3;i++) {
        if( !COMBAT_D->isHit(this_object(), enemy) ) {
            message_vision("$N�o�{�L�k���Q����$n�A�K�N�v�������^�F�C\n", this_object(), enemy);
            this_object()->start_busy(1);
        } else {
            wp = do_random("wp");
            raiseDamage = 600;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, wp);
            add_temp("apply/attack", -raiseDamage);

            if( damage < 200 ) damage = 250 + random(150);

            enemy->receive_damage(damage, this_object());
            message_vision( sprintf(HIB"[�v]"NOR"$N���t���}�A���"+wp->query("name")+"�����F$n���}��(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            destruct(wp);
        }
    }
    message_vision("\n", this_object());
    return;
}

void to_do_say()
{
    do_chat( ({ 
        (: command, "say �o�̬O�j�Ѫ�����u�|������v" :),
        (: command, "say �]���a��츭���A�ҥH�Ѥ츭�Ԫ̬ݺޡC" :),
        (: command, "say �̭��Ǫ����s�A�S����O���n�H�K�a��C" :),
    }) );
}

void create()
{
    set_name("����e��", ({ "ji feng", "feng" }));
    set_race("human");
    set_level(60);
    set("camp", "muye");
    set("title", HIK"�S�O�W��"NOR);
    set_class("superior");   // �W��
    set("long", "�g�`�y�¹��ӯf�H�����A���H���������A��@�X�A���P�_�A�b����\n"
                "���p�U����O����w�A�H�ӱ�������O�@�L�������ҥͪ��ʩR�A�L�]\n"
                "�O�츭������U�Ԫ̡C\n");

    set("age", 23);
    set("gender", "male");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set("chat_chance_combat", 25);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    set_skill("ninja", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");
    carry_object(_DIR_AREA_"ship/npc/wp/snow_blade.c")->wield();
}

void relay_say(object ob, string arg)
{
    if( arg == "�|������" )  {
        do_chat( ({ 
            (: command, "hmm" :),
            (: command, "say �|������@���|�y�A���O�إߦb�U�B�C" :),
            (: command, "say ���L�C�@�y���Z�����l�����C" :),
            (: command, "say ��P�i�঳����γ~�a..." :),
            (: command, "say ���O����𪺤@���ثe�L�H����C" :),
        }) );
    }
}
