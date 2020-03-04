#include <ansi.h>

inherit COMBINED_ITEM;

object owner;

// �]�w�D�H
int set_owner(object ob)
{
    if( !objectp(ob) ) return 0;
    owner = ob;
}

// �d�ߥD�H
object query_owner()
{
    if( !objectp(owner) ) return 0;
    return owner;
}

void create()
{
    set_name(GRN"�H"NOR+HIG"��"NOR"�Y"NOR, ({ "bad pill", "pill", "_BAD_PILL" }));
    set("unit", "�b");
    set("base_value", -1);
    set("base_weight", 10);
    set("no_sac", 1);
    set("no_drop", 1);
    set("no_sell", 1);
    set("no_box", 1);
    set("no_give", 1);
    set("long", "�H�ͯ�O�S�j�������Ӫ��A�S�O���w�H�ͦb�Y�ɪv�����ī~�W�C\n");
    setup();
    call_out("poison_pill", 10, this_object());
}

void poison_pill(object ob)
{
    mapping cnd = ([]);
    object pill, me;
    int i, damage;

    me = query_owner();

    if( !me ) {
        me = environment(this_object());
        set_owner(me);
    }
    if( !objectp(ob) || !me ) return;

    i = random(20) + 1;
    switch( random(6) ) {
        case 0: if( pill = present("heal hp pill", me) ) {
                    if( pill->query_amount() >= i ) damage = i*5;
                    else damage = pill->query_amount()*5;

                    me->receive_damage(damage, me);
                    message_vision( sprintf(HIR"�H���è�b "HIY+i+HIR" ��$n�W�A�Ϥ��z�����ˤF$N"NOR"(%d) %s\n", damage, COMBAT_D->report_status(me) ), me, pill);
                } else {
                    set_temp("pill", 1);
                }
                break;
        case 1: if( pill = present("heal mp pill", me) ) {
                    message_vision(HIM"�H���è�b "HIY+i+HIM" ��$n�W�A�Ϥ����Ͳ��ܦ����F�H�ͤY�C\n"NOR, me, pill);
                    set_temp("bad_add", 1);
                } else {
                    set_temp("pill", 1);
                }
                break;
        case 2: if( pill = present("heal ap pill", me) ) {
                    message_vision(HIC"�H���è�b "HIY+i+HIC" ��$n�W�A�Ϥ����t���Y��ç���h�ĥΡC\n"NOR, me, pill);
                } else {
                    set_temp("pill", 1);
                }
                break;
        case 3: if( pill = present("big heal hp pill", me) ) {
                    if( pill->query_amount() >= i ) damage = i*10;
                    else damage = pill->query_amount()*10;

                    me->receive_damage(damage, me);
                    message_vision( sprintf(HIR"�H���è�b "HIY+i+HIR" ��$n�W�A�Ϥ��z�����ˤF$N"NOR"(%d) %s\n", damage, COMBAT_D->report_status(me) ), me, pill);
                } else {
                    set_temp("pill", 1);
                }
                break;
        case 4: if( pill = present("big heal mp pill", me) ) {
                    message_vision(HIM"�H���è�b "HIY+i+HIM" ��$n�W�A�Ϥ����Ͳ��ܦ����F�H�ͤY�C\n"NOR, me, pill);
                    set_temp("bad_add", 2);
                } else {
                    set_temp("pill", 1);
                }
                break;
        case 5: if( pill = present("big heal ap pill", me) ) {
                    message_vision(HIC"�H���è�b "HIY+i+HIC" ��$n�W�A�Ϥ����t���Y��ç���h�ĥΡC\n"NOR, me, pill);
                } else {
                    set_temp("pill", 1);
                }
                break;
    }
    if( !me->query_condition("vp") && query_temp("pill") ) {
        message_vision("$N�Q�X�@�}�c�䪺�r��A��$n�ߨ褤�r�F�C\n"NOR, this_object(), me);

        cnd["name"] = HIG"���r"NOR;
        cnd["duration"] = this_object()->query_amount();

        me->set_condition("vp", cnd);
    } else {
        if( query_temp("bad_add") ) {
            if( pill->query_amount() > i ) this_object()->add_amount(i*query_temp("bad_add"));
            else this_object()->add_amount(pill->query_amount()*query_temp("bad_add"));
            delete_temp("bad_add");
        }
        if( pill->query_amount() > i ) pill->add_amount(-i);
        else {
            tell_object(me,"���O�A���W�S���������ī~�A�ҥH�ҫ��ī~�����P���F�C\n"NOR);
            destruct(pill);
        }
    }
    delete_temp("pill");
    call_out("poison_pill", 20, ob);
    return;
}
