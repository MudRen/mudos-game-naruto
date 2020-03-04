#include <ansi.h>

inherit ITEM;

int do_gie(object obj);

void create()
{
    set_name(HIK"��"NOR, ({ "gie" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "�]");
        set("value", 1000);
        set("long", "�b�a�W�|�v�T��ʡA������H�ĪG��n�C�i�H��(throw)");
    }
    setup();
}
void init()
{
    add_action("do_throw", "throw");
}
int do_throw(string arg)
{
    string func,target;
    object ob;
    if( this_player()->is_busy()) {
        write(CYN"�A���b���L���C"NOR"\n");
        return 1;
    }
    if( !this_player()->is_fighting() ) {
        write(CYN"�A�S�b�԰��C"NOR"\n");
        return 1;
    }
    if( !arg || sscanf(arg, "%s %s", func, target)!=2 )
        return notify_fail(CYN"�A�Q�Τ����֡H"NOR"\n");

    if( !objectp(ob = present(target, environment(this_player()))) )
        return notify_fail(CYN"�A�Q�Τ����֡H"NOR"\n");

    if( !ob ||
        !ob->is_character() ||
        ob->is_corpse() ||
        ob==this_player() )
        return notify_fail(CYN"�A�Q�Τ����֡H\n"NOR);

     if( userp(ob) ) return notify_fail("����缾�a�ϥΡC\n");  // add by -Acme-
    if( func == "gie") {
        do_gie(ob);
        return 1;
    }
    return 0;
}
int do_gie(object ob)
{
    object me;
    me = this_player();
    message_vision("$N���_"HIK"��"NOR"�ֳt��V$n�I\n"NOR, me, ob);
    if( random(ob->query_ability("evade")) > random(me->query_ability("exact")) ) {
        message_vision("        $n�q�����׶}�F�C\n", me, ob);
        destruct(this_object());
    }
    message_vision(HIK"        ��"NOR"���F���a�A$n�Q����F���ʪ����C\n"NOR, me, ob);
    ob->start_busy(1);
    destruct(this_object());
}
