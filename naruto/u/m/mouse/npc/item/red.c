#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY"�s�~"HIR"���]�U"NOR, ({ "Red Cash Gift", "red", "cash", "gift" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "���ߵo�]�A���]���ӡA�լݬ�"HIG"(use red)"NOR"���p��a�I" );
    }
    setup();
}
int do_use(object me, string arg)
{
    int i;
    if( !objectp(me) ) return 0;
    message_vision("$N"HIW"�a�ۺ�i���߱����}��W��"NOR"$n"HIW"�C\n"NOR, me, this_object());

    i = random(4999)+1;
    if( i < 100 ){
        tell_object(me, HIY"�s�~"HIR"���]�U"HIW"���~�M�� "HIY"500000"HIW" ���䲼�I�u�O�Ȩ�F�I\n"NOR);
        tell_object(me, HIG"(���w�g�s�b�Ȧ椤�F�C)\n"NOR);
        me->add("bank", 500000);
    } else if( i < 500){
        tell_object(me, HIY"�s�~"HIR"���]�U"HIW"���~�M�� "HIY"50000"HIW" ���䲼�I���u�n�I\n"NOR);
        tell_object(me, HIG"(���w�g�s�b�Ȧ椤�F�C)\n"NOR);
        me->add("bank", 50000);
    } else if( i < 1000){
        tell_object(me, HIY"�s�~"HIR"���]�U"HIW"��F "HIY"5000"HIW" ���䲼�I\n"NOR);
        tell_object(me, HIG"(���w�g�s�b�Ȧ椤�F�C)\n"NOR);
        me->add("bank", 5000);
    } else if( i < 2000){
        tell_object(me, HIY"�s�~"HIR"���]�U"HIW"�̭��u�� "HIY"125"HIW" ���A�u�O����F�C\n"NOR);
        tell_object(me, HIG"(���w�g�s�b�Ȧ椤�F�C)\n"NOR);
        me->add("bank", 125);
    } else {
        message_vision("$n"HIW"�̭��� "HIY"10"HIW" ���w�����F�X��...�u������̥h�աC\n"NOR, me, this_object());
    }
    // �Ӽƴ��
    destruct(this_object());
    return 1;
}
