#include <ansi.h>

inherit ITEM;

int do_dart(object obj);

void create()
{
    set_name("����", ({ "dart" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 100);
        set("long", "�Ԫ̱`�Ϊ�����C�i�H��(throw)");
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
    if( func == "dart") {
        do_dart(ob);
        return 1;
    }
    return 0;
}
int do_dart(object ob)
{
    object me;
    int damage;
    me = this_player();
    damage = (me->query_ability("attack") - ob->query_ability("defend"))/2;
    damage -= random(50);
    message_vision("$N���_����ֳt��V$n�I\n"NOR, me, ob);
    if( (damage <= 0 ) || (random(ob->query_ability("evade")) > random(me->query_ability("exact"))) ) {
        message_vision("        $n�q�����׶}�F�C(0)\n", me, ob);
        destruct(this_object());
    }
    message_vision("        �u�P�v�a�@�n�A���Цb$n���W�y���@�I�ˮ`("+damage+")\n"NOR, me, ob);
    ob->damage_stat("hp", damage, ob);
    destruct(this_object());
}
