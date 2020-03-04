#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIK"�@��"NOR"����"NOR, ({ "slave", "_ITS_MY_LIFE_" }));
    set_weight(3);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("no_box", 1);
        set("no_sell", 1);
        set("long", "���yè�b�������A�O���i�a�s�q�H�f�c�l....����I¾�~���ЩҪ���\n"
                    "���I�i�H�Ψӷ�F�]�A�άO���������]�i�H�A�Q�n�m�\�άO�Q�j��\n"
                    "�l���ɳ̦n�Ϊ����~�I"HIY"(�@���Ū��A�A��bag�S�@��)\n"
                    "�i�H�ϥ�"HIC"[sandbag slave]"NOR"���O���L�ܦ��F�]�C"NOR);
    }
    setup();
}

void init()
{
    if( userp(environment(this_object())) )
        add_action("do_sandbag", "sandbag");
}

int do_sandbag(string arg)
{
    object me, scap;

    me = this_player();

    if( arg != "slave" ) return notify_fail("�Q�s����F���F�]�H\n");
    if( me->is_busy() ) return notify_fail("�A�{�b�S���šC\n");
    if( me->is_fighting() ) return notify_fail("�԰����٭n����F�]�C\n");

    message_vision(NOR"$N�ε۩R�O���y���$n���G"HIG"�ޡI�b���̯��n�I\n"NOR, me, this_object());

    scap = new("/world/npc/scap.c");
    scap->set("master_name", me->query("id"));

    if( environment(me)->is_area() ) move_side(scap, me);
    else scap->move(environment(me));

    message_vision(scap->name()+CYN"���W�N�F�]���D���n���ۤ��ʡI\n"NOR, me, this_object());

    destruct(this_object());
    return 1;
}
