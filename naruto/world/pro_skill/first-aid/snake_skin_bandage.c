#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(GRN"�D���^�a"NOR, ({ "snake-skin bandage", "bandage" }));
    set_weight(1);
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 10);
        set("base_weight", 10);
        set("long", "�@�ӥΨӫ�Ϫ��^�a�C\n"
                    "�ĪG�G���W��_ 100 hp\n"
                    "�ϥΤ覡�Guse bandage          ��ۤw���\n"
                    "          use bandage on <id>  ��Y�H���\n" );
    }

    setup();
}

void do_use(object me, string arg)
{
    object who;
    mapping condition;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���šC\n");
    }

    if( arg && arg != "" ) {
        who = present(arg, environment(me));
        if( !objectp(who) ) return notify_fail("�A����S���o�ӤH�C\n");
    } else who = me;

    if( who->query_condition("cd_first_aid") ) {
        tell_object(me, "�A�{�b�S����k��"+ who->name() +"��ϡC\n");
        return;
    }

    who->heal_stat("hp", 100);
    message_vision(HIW"$N�ϥΤF�@��"GRN"�D���^�a"NOR"���W�v��$n��O�� 100 �I�C\n"NOR, me, who);

    condition = ([]);
    condition["duration"] = 60;
    condition["name"] = BLU"(�N�o)"HIK"���"NOR;
    who->set_condition("cd_first_aid", condition);

    this_object()->set_amount(this_object()->query_amount()-1);
    if( this_object()->query_amount() <= 0 )
        destruct(this_object());
}
