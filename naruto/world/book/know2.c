#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIY"�u�C"HIK"�g��������"NOR"�j�ݬ�NPC�������~�C��P���v", ({ "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("long", "�@�ӨϥΫ�i�H�Ȯɩʪ����A�ݬ�NPC�������~�C��P���v�C(help use)");
    }

    setup();
}

void do_use(object me, string arg)
{
    mapping c;
    mapping cnd = ([]);

    message_vision(HIW"$N�N�i"HIY"�u�C"HIK"�g��������"NOR"�j"NOR+HIW"���b�r�b�L���A����P�ɵ��L�I�I\n"NOR, me);

    if( !mapp(c = me->query_condition("know2")) ) c = ([]);

    cnd["name"] = HIY"�u�C"HIK"�g����"NOR;
    cnd["duration"] = 1800 + c["duration"];
    me->set_condition("know2", cnd);


    destruct(this_object());
}
