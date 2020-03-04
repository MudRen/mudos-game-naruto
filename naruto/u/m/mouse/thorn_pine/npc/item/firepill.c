#include <ansi.h>

inherit ITEM;

int do_firepill(object obj);

void create()
{
    set_name(HIR"����"NOR, ({ "firepill" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "�i");
        set("value", 400);
        set("long", "�@�i�j�_�Ӫ��z�ˡA�y���¤O�C�i�H��(throw)");
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
    if( func == "firepill") {
        do_firepill(ob);
        return 1;
    }
    return 0;
}
int do_firepill(object ob)
{
    object me;
    int damage;
    me = this_player();
    damage = me->query_ability("attack") - ob->query_ability("defend");
    damage -= random(100);
    message_vision("$N���_"HIR"����"NOR"�ֳt��V$n�I\n"NOR, me, ob);
    if( (damage <= 0 ) || (random(ob->query_ability("evade")) > random(me->query_ability("exact"))) ) {
        message_vision("        $n�q�����׶}�F�C(0)\n", me, ob);
        destruct(this_object());
    }
    message_vision("        �u�R�E�԰աv�n�T�_�A$n�Q���ˤF�C("+damage+")\n"NOR, me, ob);
    ob->damage_stat("hp", damage, ob);
    destruct(this_object());
}
