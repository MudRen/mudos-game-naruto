#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void do_fight()
{
    mapping cnd = ([]);
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // �w�g���F�N���Ω�
    if( enemy->query_condition("calcification") ) return;
    cnd["name"] = "�ۦ�";
    cnd["duration"] = 1;

    message_vision("$N���X�k��A�I�I�I�a�Q�X�ƹΥۦǯ��A�N$n�ιγ��A�åB�U�]�U��I\n"NOR, this_object(), enemy);
    message_vision("���G$n�Q�ۦǯ��ҧx��A�@�ɶ��~�M�L�k��ʡI\n"NOR, this_object(), enemy);
    enemy->set_condition("calcification", cnd);
    enemy->start_busy(2);
    return;
}
void create()
{
    set_name(HIR"���s���]"NOR, ({ "fire stone", "stone", "fire" }) );
    set_race("human");
    set("gender", "male");
    set_level(30);
    set("age", 1000 + random(5000));
    set("attitude", "aggressive");
    set("limbs", ({ "����", "���u", "�ۻL", "�۸}", "�۴x", "�Y��", "����" }) );
    set("title", "�ۦǥ�");
    set("long", "���鳡�����b�U�N�������j�]�H�A�f���o�X�C�I���q�s�n�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 25);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":127, "amount":1+random(20), "p1":4, "p2":10 ]),     // �ۦ�
    }) );
    setup();
}
