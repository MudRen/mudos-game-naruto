/*  inventory.c

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int i;
    string msg;
    object *inv, ob;

//    if( wizardp(me) && arg ) {
    if( arg ) {
    if( arg == "_MY_PET_" ) {
    ob = me->query_temp("pet");
    if( !ob ) return notify_fail("�A�S���d���C\n");
    } else {
    ob = present(arg, environment(me));
            if( !ob ) ob = find_player(arg);
            if( !ob ) ob = find_living(arg);
            if( !ob ) ob = present(arg, environment(me));
            if( !ob ) return notify_fail("�A�n�ݽ֪����~�H\n");
            if( ob->query_owner() != me && !wizardp(me) )
            return notify_fail("�A����d��設�W�����~�C\n");
        }
    }
    else ob = me;

    inv = all_inventory(ob);
    if( !sizeof(inv) ) {
        write((ob==me)? "�ثe" + gender_self(me) + "���W�S������F��C\n"
            : ob->name() + "���W�S����a����F��C\n");
        return 1;
    }
    
    msg = sprintf("%-45s [�Ŷ�] %-4s %-13s\n",
            ((ob==me)? gender_self(me) : ob->name()) + "���W�a�ۤU�C�o�ǪF��",
            sizeof(inv)*100/40 + "%",
            sizeof(inv) + "/40" );
    
    msg += sprintf("============================================= [�t��] %-4s %-13s\n",
        ob->query_encumbrance() * 100 / (ob->query_ability("carriage")+1) + "%",
           ob->query_encumbrance() + "/" + ob->query_ability("carriage") );
    
    msg += implode(map_array(inv, "inventory_desc", this_object()), "\n") + "\n";
    tell_object(me, msg);
    return 1;
}

string inventory_desc(object ob)
{
    string desc = ob->short();

    if( ob->query("equipped") ) {
        if( ob->query("keep_this") ) desc = HIK"��"NOR + desc;
        else desc = HIK"��"NOR + desc;
    } else {
        if( ob->query("keep_this") ) desc = HIK"��"NOR + desc;
        else desc = "  " + desc;
    }

    if( wizardp(this_player()) ) desc += " " + BLU+base_name(ob)+NOR;

    return desc;
}

int help (object me)
{
    write(@HELP
���O�榡: inventory
 
�i�C�X�A�ثe���W����a���Ҧ����~�C

��  ��ܧA�w�g�˳ƸӪ��~
��  ��ܸӪ��~�w�g keep
��  ��ܸӪ��~�w�˳ƥB keep

�� : �����O�i�H " i " �N���C

�i�H�d�ߦۤw�d���W�������~
ex: i acme's dog �� i _MY_PET_
HELP);
    return 1;
}
