#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"�Ф��^�a"NOR, ({ "plume bandage", "bandage" }));
    set_weight(1);
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("heal_hp", 300);
        set("base_value", 25);
        set("base_weight", 10);
        set("long", "�@�ӥΨӫ�Ϫ��^�a�C\n"
                    "�ĪG�G���W��_ 300 hp\n"
                    "�ϥΤ覡�Guse bandage          ��ۤw���\n"
                    "          use bandage on <id>  ��Y�H���\n" );
    }

    setup();
}

void do_use(object me, string arg)
{
    int heal_hp;
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

    heal_hp = this_object()->query("heal_hp");
    who->heal_stat("hp", heal_hp);
    message_vision(HIW"$N�ϥΤF�@��" + this_object()->query("name") + HIW"���W�v��$n��O�� " + heal_hp + " �I�C\n"NOR, me, who);

    condition = ([]);
    condition["duration"] = 60;
    condition["name"] = BLU"(�N�o)"HIK"���"NOR;
    who->set_condition("cd_first_aid", condition);

    this_object()->set_amount(this_object()->query_amount()-1);
    if( this_object()->query_amount() <= 0 )
        destruct(this_object());
}
