#include <npc.h>
#include <ansi.h>
#include "wp.h"

void do_fight()
{
    mapping cnd = ([]);
    object enemy, bad;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( file_size(__DIR__"item/bad_pill.c") < 0 ) return;
    if( catch(bad = new(__DIR__"item/bad_pill.c")) ) return;

    message_vision(HIB"\n$N�j�Ǫ��S�X�@�٩ǯ��A�q�h�̺N�X�@��"HIG"��⨧�l"HIB"��V$n�C\n"NOR, this_object(), enemy);

    if( !bad->move(enemy) ) {
        message_vision("���O$n�����W�ӭ��F�A��⨧�l����$n��u����F�@�Ǩ����C\n"NOR, this_object(), enemy);
        destruct(bad);
        return;
    } else {
        bad->set_owner(enemy);
        bad->set("changed", 1);
    }
    return;
}
void create()
{
    set_name("�g�ۦѧ���", ({ "aborigines doctor", "doctor" }) );
    set_level(50);
    set_race("human");
    set("gender", "male");
    set("attitude", "aggressive");
    set("wp_number", 2);
    set("age", 70+random(261));
    set("nickname",HIM"�޲�"NOR);
    set("long", "���y�K�����Ѥg�H�A���o���p����몺�ӹ�A�ڻ��O�]���g�۪���\n"
                "��̮ɱ`�|��B�M��U�ؤ��P���ħ��A���ɺ��K�|�Ť���ġA���[\n"
                "�U�ӳs�ֽ��]����ܦn�F�A�Ѩ�ѧ����O�p���C\n");
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    carry_object(__DIR__"wp/tree_staff.c")->wield("lefthand");
    call_out("die_1", 120+random(240), this_object());
    do_heal();
}

void die_1()
{
    message_vision(GRN"$N�ݤF�@�ݥ|�P�A�S���^�O�L���F�C\n"NOR, this_object());
    destruct(this_object());
    return;
}
