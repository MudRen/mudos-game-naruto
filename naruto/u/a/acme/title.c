#include <ansi.h>

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name("���Y", ({ "title" }));
    set_weight(1);
    if( !clonep() ) {
        set("wear_as", "head_eq");
        set("unit", "��");
        set("value", 1);
        set("long", "�@�����_���F��C");
    }
    setup();
}

void init()
{
    add_action("do_title", "title");
    add_action("do_name", "name");
}

int do_title(string arg)
{
    object who;
    string s1, s2;

    if( !arg ) return 0;

    if( sscanf(arg, "%s %s", s1, s2) != 2 ) return 0;

    who = present(s1, environment(this_player()));
    if( ! who ) who = find_player(s1);
    if( !who || !who->is_character() || who->is_corpse() )
        return notify_fail("�o�̨S���o�ӤH�C\n");

    s2 = color(s2);

    who->set("title", s2);

    write("ok.\n");

    return 1;
}
int do_name(string arg)
{
    object who;
    string s1, s2;

    if( !arg ) return 0;

    if( sscanf(arg, "%s %s", s1, s2) != 2 ) return 0;

    who = present(s1, environment(this_player()));
    if( ! who ) who = find_player(s1);
    if( !who || !who->is_character() || who->is_corpse() )
        return notify_fail("�o�̨S���o�ӤH�C\n");

    s2 = color(s2);

    who->set("name", s2);

    write("ok.\n");

    return 1;
}
