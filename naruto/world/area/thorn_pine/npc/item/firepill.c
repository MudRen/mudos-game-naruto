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

    if( this_player()->is_busy())
        return notify_fail("�A���b���L���C\n");

    if( !this_player()->is_fighting() )
        return notify_fail("�A�S�b�԰��C\n");

    if( !arg || sscanf(arg, "%s %s", func, target)!=2 )
        return notify_fail("�A�Q�Τ����֡H\n");

    if( !objectp(ob = present(target, environment(this_player()))) )
        return notify_fail("�o�̨S���A�n�᪺�ؼСC\n");

    if( !ob || !ob->is_character() || ob->is_corpse() || ob == this_player() )
        return notify_fail("�A�u�ݨ���Ů��N���I�L�F�C\n"NOR);

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
    int damage, exact, evade;

    me = this_player();
    exact = me->query_level();
    evade = ob->query_level();

    me->add_temp("apply/attack", 50);
    damage = COMBAT_D->isDamage(me, ob, 0);
    me->add_temp("apply/attack", -50);

    if( damage < 20 ) damage = random(20);

    message_vision("\n$N���_"HIR"����"NOR"�ֳt��V$n�I\n"NOR, me, ob);
    if( !COMBAT_D->SkillHit(me, ob, exact, evade) ) {
        message_vision(" $n�q�����׶}�F�C\n\n", me, ob);
        destruct(this_object());
    } else {
        message_vision( sprintf("�u�R�E�԰աv�n�T�_�A$n�Q���ˤF�C(%d) %s\n\n", damage, COMBAT_D->report_status(ob) ), me, ob);
        ob->damage_stat("hp", damage, ob);
        destruct(this_object());
    }
    me->start_busy(2);
    return 1;
}
