#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(RED"���ԤY"NOR, ({ "chili pill", "pill" }));
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 1);
        set("no_box", 1);
        set("long","��D�@�ڪ����ġA�~������A���ݴNı�o�D�`�����C\n");
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
    if( me->query_attr("con") < 70 ) {
        write("�A�����L�k�t���D���ġC\n");
        return;
    }
    if( me->query_condition("akimichi1") != 0 ) {
        write("�A�w�g�Y�L��D���ĤF�A���ɮĹL�F�A�Y�a�C\n");
        return;
    }
    if( me->query_condition("akimichi2") != 0 ) {
        write("���ԤY���b�o���ĥΤ��A�A�Y�ĤG���i��|��R�C\n");
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
    add = me->query_stat("ap") + me->query_stat("hp");

    message_vision("\n$N�N$n��J�f���j�f�C�Z�ۡA�u��$N�y��ֳt�ܬ��A���G�֭n�z�o�F�C\n"NOR, me, this_object());
    tell_object(me,HIR"���ԤY���ĪG�v����{�A�A�Pı�O�q�P�d�J�Է���������{�I\n"NOR);

    cnd["name"] = RED"���ԤY"NOR;
    cnd["duration"] = sk;
    cnd["attack"] = sk/2;
    cnd["armor"] = sk/2;
    cnd["mp"] = add;

    me->set_condition("akimichi2", cnd);
    me->set_stat_current("hp", 1);
    me->set_stat_current("ap", 1);
    me->heal_stat("mp", add);
    me->improve_skill("akimichi medicine", 1);
    me->start_busy(2);

    // �Ӽƴ��
    this_object()->add_amount(-1);
    if( !this_object()->query_amount() )
        destruct(this_object());
}
