
#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("�i"HIK"�g��������"NOR"�j�ݬ�NPC�������~�C��", ({ "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("long", "�@�ӨϥΫ�i�H�Ȯɩʪ����A�ݬ�NPC�������~�C��C(help use)");
    }

    setup();
}

void do_use(object me, string arg)
{
    mapping c;
    mapping cnd = ([]);

    message_vision(HIW"$N�N�i"HIK"�g��������"NOR"�j"NOR+HIW"���b�r�b�L���A����P�ɵ��L�I�I\n"NOR, me);

    if( !mapp(c = me->query_condition("know1")) ) c = ([]);

    cnd["name"] = HIK"�g����"NOR;
    cnd["duration"] = 1800 + c["duration"];
    me->set_condition("know1", cnd);


    destruct(this_object());
}
