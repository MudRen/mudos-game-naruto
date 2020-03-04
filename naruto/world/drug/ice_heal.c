#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"�B��"HIY"����"NOR, ({ "Ice porridge", "ice", "porridge" }));
    set("unit", "�j�J");
    set("base_unit", "�j�J");
    set("base_value", -1);
    set("base_weight", 200);
    set("no_box", 1);
    set("food_stuff", 30);    // �����q�A���~�@�w�n�������q
    set("long", "�Ĥj�v������һs���A���_�a���X�L�z���H��A�O�@�J��h�������A\n"
                "�ٯ���������h�Ҫ����~�}�ġA�]�����\�����o�ز������H�֤��S��\n"
                "�ҥH�N��ӤH�]�ȶR�찲�ĦӤ������ʡC\n"
             HIW"�ϥΤ�k��"HIC"(use ice)"HIW"�A�ĪG�O�믫"HIR"MAX"HIW"�C\n"NOR);
    setup();
}

void do_use(object me)
{
    if( environment(this_object()) != me ) {
        write("�o�F�褣�b�A���W�A����æY�C\n");
        return;
    }
    message_vision("$N���X�@�J�_�X�H��$n�A�@�f��N��F�U�h�C\n", me, this_object());
    message_vision(HIC"$N�P������@�}�D�N�A�����@���M���C\n"NOR, me, this_object());
    me->heal_stat("ap", me->query_stat_maximum("ap"));
    tell_object(me,HIY"(�A���믫�^�_�F "HIR+me->query_stat_maximum("ap")+HIY" �I�C)\n"NOR);

    this_object()->add_amount(-1);
    if( !this_object()->query_amount() ) destruct(this_object());
}
