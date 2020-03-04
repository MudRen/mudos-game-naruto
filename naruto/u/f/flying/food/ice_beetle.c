#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"�B�����"NOR, ({ "Ice Beetle", "ice", "beetle " }));
    set("unit", "�j��");
    set("base_unit", "�j��");
    set("base_value", -1);
    set("base_weight", 200);
    set("food_stuff", 10);    // �����q�A���~�@�w�n�������q
    set("long", "�Ĥj�v������һs���A���_�a���X�L�z���H��A�O�@�J��h�������A\n"
                "�ٯ���������h�Ҫ����~�}�ġA�]�����\�����o�ز������H�֤��S��\n"
                "�ҥH�N��ӤH�]�ȶR�찲�ĦӤ������ʡC\n"
             HIW"�ϥΤ�k��"HIC"(use ice)"HIW"�A�ĪG�O�믫"HIR"MAX"HIW"�C\n"NOR);
    setup();
}

void do_use(object me)
{
    message_vision("$N���X�@���_�X���$n�A�@�f��N�٤F�U�h�C\n", me, this_object());
    message_vision(HIC"$N�P������@�}�÷N�A�����@���w�t�C\n"NOR, me, this_object());
    me->heal_stat("hp", me->query_stat_maximum("ap"));
    tell_object(me,HIY"(�A���믫�^�_�F "HIR+me->query_stat_maximum("ap")+HIY" �I�C)\n"NOR);
    destruct(this_object());
}

