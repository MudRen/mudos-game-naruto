#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(GRN"�Ե�Y"NOR, ({ "holenso pill", "pill" }));
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 1);
        set("no_box", 1);
        set("long","��D�@�ڪ����ġA�~��ݰ_�ӫܹ������W�檺�峽�Ե�Y�C\n");
    }
    setup();
}

void do_use(object me, string arg)
{
    mapping cnd = ([]);
    object *inv, item;
    int sk, add, out;

    inv = all_inventory(me);

    if( me->is_busy() ) {
        write("�A���b���L�A�S�ŦY�ġC\n");
        return;
    }
    if( me->query_attr("con") < 50 ) {
        write("�A�����L�k�t���D���ġC\n");
        return;
    }
    if( me->query_condition("akimichi1") != 0 ) {
        write("�A�w�g�Y�L��D���ĤF�A���ɮĹL�F�A�Y�a�C\n");
        return;
    }
    if( me->query_condition("akimichi2") != 0 ) {
        write("�A�w�g�Y�L��D���ĤF�A���ɮĹL�F�A�Y�a�C\n");
        return;
    }
    if( me->query_condition("akimichi3") != 0 ) {
        write("�����P�٨S�h�h�e����A�Y�ġC\n");
        return;
    }
    foreach(item in inv) {
        if( item->query("equipped") ) {
            write("�Y�U��D���Įɨ���|���o����A�]�������ۥ���˳ơC\n");
            return;
        }
    }
    sk = me->query_skill("akimichi pill");

    if( sk < 40 ) {
        write("�A����D���Ī��Ѥ����A�����D�p�󭹥Τ~�|���ĪG�C\n");
        return;
    }
    add = me->query_stat_maximum("hp")/3;
    if( sk < 100 ) out = add*2;
    else if( sk < 160 ) out = add;
    else out = add/2;

    if( me->query_stat_maximum("ap") < out ) {
        write("�A������L�k�t��Ե�Y���ĪG�C\n");
        return;
    }
    message_vision("\n$N�N$n��J�f���Z�F�X�U�A�u��$N���������G�S�ܭD�F�\�h�C\n"NOR, me, this_object());
    tell_object(me,HIG"�Ե�Y�o���ĥΤF�I�A�Pı��������G���ȡA�Ī��������I�V�áI\n"NOR);

    cnd["name"] = GRN"�Ե�Y"NOR;
    cnd["duration"] = sk;
    cnd["hp"] = add;
    cnd["ap"] = out*-1;
    cnd["mp"] = 0;

    me->set_condition("akimichi1", cnd);
    me->heal_stat("hp", add);
    me->improve_skill("akimichi medicine", 1);
    me->start_busy(2);

    // �Ӽƴ��
    this_object()->add_amount(-1);
    if( !this_object()->query_amount() )
        destruct(this_object());
}
