#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"�@���Y"NOR, ({ "kare pill", "pill" }));
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 1);
        set("no_box", 1);
        set("long","��D�@�ڪ����ġA���O�ݰ_�ӴN���@�����ΡA�S����S�O�C\n");
    }
    setup();
}

void do_use(object me, string arg)
{
    mapping cnd = ([]);
    object *inv, item;
    int sk, add;

    inv = all_inventory(me);

    if( me->is_busy() ) {
        write("�A���b���L�A�S�ŦY�ġC\n");
        return;
    }
    if( me->query_attr("con") < 60 ) {
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
    if( sk >= 50 ) add = me->query_stat_maximum("mp")*(sk/50 - 1);
    else add = 0;

    message_vision("\n$N�N$n��J�f���t�ۡA�u��$N�������U�ӷU���G...\n"NOR, me, this_object());
    tell_object(me,HIY"�@���Y�o���ĥΤF�I�A���d�J�ԼW�[�F�ƭ��A���O��O�믫�o��z�F...\n"NOR);

    cnd["name"] = YEL"�@���Y"NOR;
    cnd["duration"] = sk;
    cnd["hp"] = me->query_stat_maximum("hp")/2 - me->query_stat_maximum("hp");
    cnd["ap"] = me->query_stat_maximum("ap")/2 - me->query_stat_maximum("ap");
    cnd["mp"] = add;

    me->set_condition("akimichi1", cnd);
    me->heal_stat("mp", add);
    me->improve_skill("akimichi medicine", 1);
    me->start_busy(2);

    // �Ӽƴ��
    this_object()->add_amount(-1);
    if( !this_object()->query_amount() )
        destruct(this_object());
}
