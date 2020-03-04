#include <ansi.h>

inherit ITEM;

int do_bom(object obj);

void create()
{
    set_name(HIK"���u"NOR, ({ "bom" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 1500);
        set("long", "�@�����]�p�L�����u�A�¤O�j�j�C�i�H��(throw)");
    }
    setup();
}
void init()
{
    add_action("do_throw", "throw");
}
int do_throw(string arg)
{
    string func, target;
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
    if( func == "bom") {
        do_bom(ob);
        return 1;
    }
    return 0;
}

int do_bom(object ob)
{
    object me;
    int damage, exact, evade;

    me = this_player();
    exact = me->query_level();
    evade = ob->query_level();

    me->add_temp("apply/attack", 300);
    damage = COMBAT_D->isDamage(me, ob, 0);
    me->add_temp("apply/attack", -300);

    if( damage < 100 ) damage = random(100);

    message_vision("\n$N���_"HIK"���u"NOR"�ֳt��V$n�I\n"NOR, me, ob);
    if( !COMBAT_D->SkillHit(me, ob, exact, evade) ) {
        message_vision("$n�q�����׶}�F�C\n\n", me, ob);
        destruct(this_object());
    } else {
        message_vision( sprintf("�u�F���v�@�n���T�A$n�Q�������F�X�h�C(%d) %s\n\n", damage, COMBAT_D->report_status(ob) ), me, ob);
        ob->damage_stat("hp", damage, ob);
        destruct(this_object());
    }
    me->start_busy(4);
    return 1;
}
