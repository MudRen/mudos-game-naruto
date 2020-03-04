#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("�Ȭr"HIR"��M"NOR, ({ "blood serum", "serum" }));
    if( !clonep() ) {
        set("unit", "�~");
        set("value", 0);
        set("no_sell", 1);
        set("base_value", 0);
        set("base_weight", 1);
        set("long","��Ѱ��Ȭr����M�A�ϥΤ�k�� use serum�C\n");
    }
    setup();
}

void do_use(object me, string arg)
{
    if( me->query_condition("scorpion_poison") == 0 ) {
        write("�A�ثe�S�����Ȭr�A�H�K�ϥΦ�M�u�|�y���t��C\n");
        return;
    }
    message_vision("$N���}�F$n�A�N��M�`�J�쨭�W�A�y��ݰ_�Ӧn�h�F�C\n"NOR, me, this_object());

    me->start_busy(1);
    me->delete_condition("scorpion_poison");

    // �Ӽƴ��
    this_object()->add_amount(-1);
    if( !this_object()->query_amount() )
        destruct(this_object());
}
