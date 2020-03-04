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
    set_name(HIK"�H�a��"NOR, ({ "parasitism bug", "bug", "_GI_BUG_" }));
    set("unit", "��");
    set("base_value", 0);
    set("base_weight", 1);
    set("no_sac", 1);
    set("no_sell", 1);
    set("no_drop", 1);
    set("no_box", 1);
    set("no_give", 1);
    set("long", "�o�k�@�کҾިϪ��Τl�A³�����d�J�ԡA�ҥH��X�֧ԳN�ϥΡC\n");
    call_out("eat_mp", 3, this_object());
    setup();
}

void init()
{
    add_action("do_rid", "rid");
}

int do_rid(string arg)
{
    if( this_player()->is_fighting() ) {
        tell_object(this_player(), "�԰������ΡA�u�|���A�i�h�����Ӥw�C\n"NOR);
        return 1;
    }
    if( query("keep_this") ) {
        tell_object(this_player(), "�o�˪F��A�w�g keep �L�k���C\n"NOR);
        return 1;
    }
    message_vision(CYN"$N�N���W��$n"CYN"�ް_�ӥ�b�a�W�A�٥����a��$n"CYN"�W��F�X�}�C\n"NOR, this_player(), this_object());
    tell_object(this_player(), "���M�M���F"HIK"�H�a��"NOR"�A���٬O�����A���Y����C\n"NOR);
    destruct(this_object());
    return 1;
}

void eat_mp()
{
    object me;
    int i, damage;

    me = query_owner();
    i = query_amount()*2;

    if( !me ) {
        me = environment(this_object());
        set_owner(me);
    }
    if( !objectp(this_object()) || !me ) return;

    message_vision("\n$N"HIM"���XĲ�����}$n���֦סA�����l��$n���]�O�C\n"NOR, this_object(), me);

    if( me->query_stat_current("mp") > i ) {
        if( userp(me) ) message_vision("$n���]�O�~�M�ֳt�y���A���G�l���F "HIB+i+NOR" �I�C\n\n"NOR, this_object(), me);
        me->damage_stat("mp", i, me);
    } else if( me->query_stat_current("mp") <= 0 ) {
        if( userp(me) ) message_vision("���O$n���W�w�g�S�������]�O�ണ��$N�l���C\n\n"NOR, this_object(), me);
    } else {
        if( userp(me) ) message_vision("�ܧ֦a$n���W�Ѿl�� "HIB+i+NOR" �I�]�O�N�Q$N���l���F�C\n\n"NOR, this_object(), me);
        me->set_stat_current("mp", 0);
    }
    call_out("eat_mp", 10);
    return;
}
